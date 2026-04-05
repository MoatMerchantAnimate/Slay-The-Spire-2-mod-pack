/*
 * Visual Enhancer — Slay the Spire 2 Mod Pack
 */
#include <iostream>
#include <algorithm>

namespace STSTweaks {

struct VisualCfg {
    float sharpen = 0.3f, contrast = 1.05f, saturation = 1.1f, brightness = 1.0f;
    bool crtFilter = false;
    float crtCurvature = 0.3f, crtScanlines = 0.2f;
    bool removeVignette = false;
};

class VisualEnhancer {
    VisualCfg cfg;
    bool active = false;
public:
    void Init(const VisualCfg& c = {}) {
        cfg = c; active = true;
        std::cout << "[StS2 Visual] Sharpen: " << cfg.sharpen
                  << " CRT: " << (cfg.crtFilter ? "ON" : "OFF") << std::endl;
    }
    void SetSharpen(float s) { cfg.sharpen = std::clamp(s, 0.f, 2.f); }
    void ToggleCRT(bool on) { cfg.crtFilter = on; }
    void SetContrast(float c) { cfg.contrast = std::clamp(c, 0.5f, 2.0f); }
    void Shutdown() { active = false; }
};

} // namespace STSTweaks
