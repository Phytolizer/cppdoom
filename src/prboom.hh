//
// Created by kyle on 9/26/20.
//

#ifndef EZ_BOOM_PRBOOM_HH
#define EZ_BOOM_PRBOOM_HH

#include <string_view>
namespace prboom
{

enum class MessageBoxFlag
{
    PRB_MB_OK = 0,
    PRB_MB_OKCANCEL = 1,
    PRB_MB_ABORTRETRYIGNORE = 2,
    PRB_MB_YESNOCANCEL = 3,
    PRB_MB_YESNO = 4,
    PRB_MB_RETRYCANCEL = 5,
    PRB_MB_DEFBUTTON1 = 0x000,
    PRB_MB_DEFBUTTON2 = 0x100,
    PRB_MB_DEFBUTTON3 = 0x200,
};

enum class MessageBoxResponse
{
    PRB_IDOK = 1,
    PRB_IDCANCEL = 2,
    PRB_IDABORT = 3,
    PRB_IDRETRY = 4,
    PRB_IDIGNORE = 5,
    PRB_IDYES = 6,
    PRB_IDNO = 7,
};

MessageBoxResponse messageBox(std::string_view text, MessageBoxFlag type);

} // namespace prboom

#endif // EZ_BOOM_PRBOOM_HH
