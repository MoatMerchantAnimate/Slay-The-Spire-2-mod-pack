/*
 * Load Time Reducer — Slay the Spire 2 Mod Pack
 */
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <thread>

namespace STSTweaks {

class AssetPreloader {
    std::vector<std::string> preloadList;
    bool active = false;
public:
    void AddAsset(const std::string& path) { preloadList.push_back(path); }
    void PreloadAll() {
        std::cout << "[StS2 Load] Preloading " << preloadList.size() << " assets..." << std::endl;
        for (auto& path : preloadList) {
            HANDLE f = CreateFileA(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr,
                                   OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, nullptr);
            if (f != INVALID_HANDLE_VALUE) {
                char buf[65536];
                DWORD read;
                while (ReadFile(f, buf, sizeof(buf), &read, nullptr) && read > 0) {}
                CloseHandle(f);
            }
        }
        std::cout << "[StS2 Load] Preload complete" << std::endl;
    }
};

class LoadTimeReducer {
    AssetPreloader preloader;
    bool active = false;
public:
    void Init() {
        preloader.AddAsset("cards/textures.pak");
        preloader.AddAsset("enemies/sprites.pak");
        preloader.AddAsset("vfx/particles.pak");
        preloader.AddAsset("ui/atlas.pak");
        preloader.AddAsset("maps/floor_data.pak");
        std::thread([this]{ preloader.PreloadAll(); }).detach();
        active = true;
        std::cout << "[StS2 Load] Background preload started" << std::endl;
    }
    void Shutdown() { active = false; }
};

} // namespace STSTweaks
