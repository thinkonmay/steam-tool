#ifndef DLLMAIN_H
#define DLLMAIN_H

#include "OSTPlatform/include/DynamicLibrary.h"

#include <string>
#include <fstream>
#include <filesystem>
#include <array>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <regex>
#include <memory>
#include <atomic>
#include <format>

#include "Steam/Types.h"
#include "Steam/Enums.h"
#include "Steam/Structs.h"
#include "Steam/Callback.h"
#include "Utils/Config/LuaConfig.h"
#include "Utils/Logging/Log.h"
#include "Utils/Config/Config.h"


inline OSTPlatform::DynamicLibrary::ModuleHandle client_hModule = nullptr;
inline OSTPlatform::DynamicLibrary::ModuleHandle ui_hModule = nullptr;

inline constexpr size_t kRuntimePathCapacity = 260;

inline char SteamInstallPath[kRuntimePathCapacity] = {};
inline char SteamclientPath[kRuntimePathCapacity]  = {};
inline char SteamUIPath[kRuntimePathCapacity]      = {};
inline char DiversionPath[kRuntimePathCapacity]    = {};
inline char LuaDir[kRuntimePathCapacity]           = {};
inline char ConfigPath[kRuntimePathCapacity]       = {};

// The fake AppId used by -onlinefix (SpaceWar).
constexpr AppId_t kOnlineFixAppId = 480;

// Implemented in dllmain.cpp. Lets a merged proxy DLL (built with
// OST_MERGED_PROXY) start/stop the tool directly, instead of loading a
// separate OpenSteamTool.dll via LoadLibrary. selfModule is the proxy's HMODULE.
void OpenSteamToolStart(void* selfModule);
void OpenSteamToolStop();

#endif // DLLMAIN_H
