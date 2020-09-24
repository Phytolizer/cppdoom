cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
if (WIN32)
    set(CMAKE_TOOLCHAIN_FILE "C:\\dev\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake")
else ()
    set(CMAKE_TOOLCHAIN_FILE
            "/home/kyle/.local/share/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif ()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project("Ez-Boom" VERSION 0.1.0)

set(PACKAGE_NAME "${PROJECT_NAME}")
set(PACKAGE_TARNAME "ez-boom")
set(PACKAGE_VERSION "${PROJECT_VERSION}")
set(PACKAGE_STRING "${PROJECT_NAME} ${PROJECT_VERSION}")

file(GLOB_RECURSE SOURCES "src/*.cc")
add_executable(doom ${SOURCES})

if (WIN32)
    set(SDL2_DIR "/dev/libs/SDL2/")
    set(SDL2_INCLUDE_DIRS "/dev/libs/SDL2/include")
    set(SDL2_LIBRARY "/dev/libs/SDL2/lib/x64")
endif ()

target_include_directories(doom PRIVATE deps/eternal/include)

find_package(SDL2 REQUIRED)
target_link_libraries(doom PRIVATE SDL2 SDL2_image)

find_path(STRTK_INCLUDE_DIRS "strtk.hpp")
target_include_directories(doom SYSTEM PRIVATE ${STRTK_INCLUDE_DIRS})

find_path(BOOST_VARIANT2_INCLUDE_DIRS "boost/variant2/variant.hpp")
target_include_directories(doom SYSTEM PRIVATE ${BOOST_VARIANT2_INCLUDE_DIRS})

find_path(BOOST_LEXICAL_CAST_INCLUDE_DIRS "boost/detail/basic_pointerbuf.hpp")
target_include_directories(doom SYSTEM
        PRIVATE ${BOOST_LEXICAL_CAST_INCLUDE_DIRS})

find_path(RANG_INCLUDE_DIRS "rang.hpp")
target_include_directories(doom SYSTEM PRIVATE ${RANG_INCLUDE_DIRS})

find_package(fmt CONFIG REQUIRED)
target_link_libraries(doom PRIVATE fmt::fmt fmt::fmt-header-only)

find_package(Microsoft.GSL CONFIG REQUIRED)
target_link_libraries(doom PRIVATE Microsoft.GSL::GSL)

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(doom PRIVATE spdlog::spdlog spdlog::spdlog_header_only)

include(CheckSymbolExists)
check_symbol_exists(stricmp "cstring" HAVE_STRICMP)
if (NOT HAVE_STRICMP)
    add_definitions("-Dstricmp=strcasecmp")
endif ()

include(CheckIncludeFile)
check_include_file("asm/byteorder.h" HAVE_ASM_BYTEORDER_H)

include(TestBigEndian)
test_big_endian(WORDS_BIGENDIAN)

configure_file(cmake/config.h.cin config.h)

include_directories(${CMAKE_BINARY_DIR})
