// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
// ******************************************************************
// *
// *  This file is part of the Cxbx-Reloaded project.
// *
// *  Cxbx and Cxbe are free software; you can redistribute them
// *  and/or modify them under the terms of the GNU General Public
// *  License as published by the Free Software Foundation; either
// *  version 2 of the license, or (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// *  GNU General Public License for more details.
// *
// *  You should have recieved a copy of the GNU General Public License
// *  along with this program; see the file COPYING.
// *  If not, write to the Free Software Foundation, Inc.,
// *  59 Temple Place - Suite 330, Bostom, MA 02111-1307, USA.
// *
// *  All rights reserved
// *
// ******************************************************************
#pragma once

#include <filesystem>
#include <string>
#include <optional>

#include "Logging.h"

bool CreateSettings();

bool HandleFirstLaunch();

// TODO: Eventually, we should remove this function to start using std::filesystem::path method for all host paths.
void CxbxResolveHostToFullPath(std::string& file_path, std::string_view finish_error_sentence);

// Loads a keys.bin file as generated by dump-xbox
// See https://github.com/JayFoxRox/xqemu-tools/blob/master/dump-xbox.c
void LoadXboxKeys();

bool CxbxrLockFilePath();

void CxbxrUnlockFilePath();

// Hybrid functions depending on specific platforms
bool CxbxrIsElevated();

std::optional<std::string> CxbxrExec(bool useDebugger, void** hProcess, bool requestHandleProcess);

/*! cleanup emulation */
[[noreturn]] void CxbxrAbortEx(CXBXR_MODULE cxbxr_module, const char* szErrorMessage, ...);

#define CxbxrAbort(fmt, ...) CxbxrAbortEx(LOG_PREFIX, fmt, ##__VA_ARGS__)

/*! terminate gracefully the emulation */
[[noreturn]] void CxbxrShutDown(bool is_reboot = false);
