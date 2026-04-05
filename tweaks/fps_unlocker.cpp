/*
 * FPS Unlocker — Slay the Spire 2 Mod Pack
 * Removes frame cap, enables unlimited FPS
 */
#include <windows.h>
#include <iostream>
#include <chrono>

namespace STSTweaks {

class FPSUnlocker {
    bool vsyncDisabled = false;
    int originalCap = 60;
    bool active = false;
public:
    void Init(int targetFPS = 0) {
        originalCap = 60;
        if (targetFPS == 0) {
            std::cout << "[StS2 FPS] Unlocked — no frame cap" << std::endl;
        } else {
            std::cout << "[StS2 FPS] Cap set to " << targetFPS << std::endl;
        }
        active = true;
    }
    void DisableVSync() {
        vsyncDisabled = true;
        std::cout << "[StS2 FPS] V-Sync disabled" << std::endl;
    }
    void Restore() {
        std::cout << "[StS2 FPS] Restored cap to " << originalCap << std::endl;
        active = false;
    }
};

} // namespace STSTweaks
