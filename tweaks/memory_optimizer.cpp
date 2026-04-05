/*
 * Memory Optimizer — Slay the Spire 2 Mod Pack
 */
#include <windows.h>
#include <iostream>

namespace STSTweaks {

struct MemConfig {
    bool compressTextures = true;
    bool unloadDistantFloors = true;
    int gcIntervalFrames = 300;
    float maxHeapMB = 512.0f;
};

class MemoryOptimizer {
    MemConfig cfg;
    int frameCounter = 0;
    bool active = false;
public:
    void Init(const MemConfig& c = {}) {
        cfg = c; active = true;
        SetProcessWorkingSetSize(GetCurrentProcess(), (SIZE_T)-1, (SIZE_T)-1);
        std::cout << "[StS2 Mem] GC every " << cfg.gcIntervalFrames << " frames" << std::endl;
    }
    void OnFrame() {
        if (!active) return;
        frameCounter++;
        if (frameCounter >= cfg.gcIntervalFrames) {
            EmptyWorkingSet(GetCurrentProcess());
            frameCounter = 0;
        }
    }
    void ForceClean() {
        EmptyWorkingSet(GetCurrentProcess());
        std::cout << "[StS2 Mem] Working set trimmed" << std::endl;
    }
    void Shutdown() { active = false; }
};

} // namespace STSTweaks
