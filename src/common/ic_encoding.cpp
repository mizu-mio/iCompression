#include "ic_encoding.h"
#include <windows.h>

static std::wstring decode(const char* s, UINT cp)
{
    if (!s) return L"";

    int len = MultiByteToWideChar(cp, MB_ERR_INVALID_CHARS, s, -1, NULL, 0);
    if (len <= 0) return L"";

    std::wstring w(len, L'\0');
    MultiByteToWideChar(cp, 0, s, -1, &w[0], len);
    return w;
}

std::wstring ic_decode_utf8(const char* s)
{
    return decode(s, CP_UTF8);
}

std::wstring ic_decode_gbk(const char* s)
{
    return decode(s, 936);
}

std::wstring ic_decode_best(const char* s)
{
    auto w = ic_decode_utf8(s);
    if (!w.empty()) return w;

    w = ic_decode_gbk(s);
    if (!w.empty()) return w;

    return decode(s, CP_ACP);
}
