#pragma once
#include <string>
#include <archive_entry.h>

std::wstring ic_resolve_entry_path(struct archive_entry* entry);
std::wstring ic_normalize_path(const std::wstring& path);
std::wstring ic_join_path(const std::wstring& root, const std::wstring& sub);
