#include "doom.hh"
#include "arglex.hh"
#include "doom_main.hh"
#include "misc.hh"
#include "sound.hh"
#include "system.hh"
#include "video.hh"
#include "wad.hh"

#include <csignal>
#include <cstdint>
#include <cstdio>
#include <fmt/core.h>
#include <gsl/gsl>
#include <spdlog/spdlog.h>
#include <vector>

arglex::ArgMeta argMeta;
int realtic_clock_rate = 100;
int endoom_mode;
std::vector<std::string> wad_files{};
std::vector<std::string> deh_files{};

void printVersion()
{
    spdlog::info("{}", sys::getVersionString());
}

void signalHandler(int s)
{
    // ignore any future instances of this signal
    signal(s, SIG_IGN);

    std::string msg = fmt::format("Exiting on signal: {}", sys::sigString(s));

    spdlog::error("signalHandler: {}", msg);
    exit(-1);
}

void setAffinityMask()
{
    video::process_affinity_mask = 0;
    if (sound::snd_midiplayer == sound::midiplayers[static_cast<int>(sound::MidiPlayerName::Sdl)])
    {
        video::process_affinity_mask = 1;
    }

    if (video::process_affinity_mask != 0)
    {
        const char* errbuf = nullptr;
#ifdef _WIN32
        HMODULE kernel32_dll;
        SetAffinityFunc SetAffinity = nullptr;
        bool ok = false;

        kernel32_dll = LoadLibrary("kernel32.dll");

        if (kernel32_dll)
        {
            SetAffinity = (SetAffinityFunc)GetProcAddress(kernel32_dll, "SetProcessAffinityMask");
            if (SetAffinity)
            {
                ok = SetAffinity(GetCurrentProcess(), video::process_affinity_mask);
            }
        }
        if (!ok)
        {
            errbuf = WINError();
        }
#elif defined(HAVE_SCHED_SETAFFINITY)
        cpu_set_t set;
        CPU_ZERO(&set);
        for (int i = 0; i < 16; i += 1)
        {
            CPU_SET((video::process_affinity_mask >> i) & 1, &set);
        }
        if (sched_setaffinity(getpid(), sizeof(set), &set) == -1)
        {
            errbuf = strerror(errno);
        }
#else
        return;
#endif
        if (errbuf == nullptr)
        {
            spdlog::info("setAffinityMask: manual affinity mask is {}", video::process_affinity_mask);
        }
        else
        {
            spdlog::error("setAffinityMask: failed to set process affinity mask: {}", errbuf);
        }
    }
}

void setProcessPriority()
{
    if (video::process_priority != 0)
    {
        const char* errbuf = nullptr;
#ifdef _WIN32
        {
            DWORD dwPriorityClass = NORMAL_PRIORITY_CLASS;

            if (process_priority == 1)
                dwPriorityClass = HIGH_PRIORITY_CLASS;
            else if (process_priority == 2)
                dwPriorityClass = REALTIME_PRIORITY_CLASS;

            if (SetPriorityClass(GetCurrentProcess(), dwPriorityClass) == 0)
            {
                errbuf = WINError();
            }
        }
#else
        return;
#endif
        if (errbuf == nullptr)
        {
            spdlog::info("setProcessPriority: priority for the process is {}", video::process_priority);
        }
        else
        {
            spdlog::error("setProcessPriority: failed to set priority for the process: {}", errbuf);
        }
    }
}

void findResponseFile(gsl::not_null<std::vector<arglex::Arg>*> args, std::vector<arglex::Arg>::iterator responseFile)
{
    // remove leading '@'
    std::string fname = responseFile->value.substr(1);
    wad::addDefaultExtension(fname, ".rsp");

    auto contents = misc::readFile(fname);
    if (!contents.has_value())
    {
        fname = fmt::format("{}/{}", sys::doomExeDir(), fname);
        contents = misc::readFile(fname);
        if (!contents.has_value())
        {
            spdlog::error("No such response file: {}", fname);
            exit(-1);
        }
    }
    spdlog::info("Found response file: {}", fname);
    if (contents.value().empty())
    {
        spdlog::error("Response file empty!");
        args->erase(responseFile);
        return;
    }

    for (auto infile = contents->begin(); infile != contents->end();)
    {
        while (infile != contents->end() && std::isspace(static_cast<int>(*infile)))
        {
            ++infile;
        }
        if (infile != contents->end())
        {
            bool quoted = false;
            std::string s;
            while (infile != contents->end())
            {
                if (!quoted && std::isspace(static_cast<int>(*infile)))
                {
                    break;
                }
                if (static_cast<char>(*infile) == '"')
                {
                    ++infile;
                    quoted = !quoted;
                }
                else
                {
                    s += static_cast<char>(*infile);
                    ++infile;
                }
            }
            if (quoted)
            {
                spdlog::error("Runaway quoted string in response file");
                exit(-1);
            }
            args->insert(responseFile, arglex::lexArg(s));
        }
    }
    args->erase(responseFile);
    spdlog::info("{} command-line args:", args->size());
    for (auto arg = next(args->begin()); arg != args->end(); ++arg)
    {
        spdlog::info("{}", arg->value);
    }
}

void loadResponseFiles(gsl::not_null<std::vector<arglex::Arg>*> args)
{
    bool rspFound = true;
    while (rspFound)
    {
        rspFound = false;
        for (auto i = args->begin(); i != args->end(); ++i)
        {
            auto& arg = *i;
            if (arg.value[0] == '@')
            {
                rspFound = true;
                findResponseFile(args, i);
            }
        }
    }
}

int main(int argc, const char* const* argv)
{
    std::vector<arglex::Arg> args = arglex::lexArgs(argc, argv);
    loadResponseFiles(&args);
    auto parseResult = arglex::parseArgs(args);

    if (parseResult.index() == 1)
    {
        fmt::print(stderr, "{}", boost::variant2::get<1>(parseResult));
        exit(-1);
    }
    argMeta = boost::variant2::get<0>(parseResult);
    spdlog::info("Loading system defaults.");
    misc::loadDefaults();

    printVersion();

    if (!argMeta.devparm)
    {
        signal(SIGSEGV, signalHandler);
    }
    signal(SIGTERM, signalHandler);
    signal(SIGFPE, signalHandler);
    signal(SIGILL, signalHandler);
    signal(SIGINT, signalHandler);
    signal(SIGABRT, signalHandler);

    setAffinityMask();
    setProcessPriority();

    video::preInitGraphics();

    doom::main();

    return 0;
}