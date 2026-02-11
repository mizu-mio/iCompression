#pragma once
#include <string>

std::wstring ic_decode_utf8(const char* s);
std::wstring ic_decode_gbk(const char* s);
std::wstring ic_decode_best(const char* s);
