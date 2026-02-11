#pragma once
#include <string>
#include <archive.h>

bool ic_ensure_dir(const std::wstring& path);
bool ic_write_file(struct archive* a, const std::wstring& path);
