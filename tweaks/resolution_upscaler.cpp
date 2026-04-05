/*
 * Resolution Upscaler — Slay the Spire 2 Mod Pack
 */
#include <iostream>
#include <algorithm>
#include <cmath>

namespace STSTweaks {

struct UpscaleConfig {
    float renderScale = 0.75f;
    int outputWidth = 1920, outputHeight = 1080;
    bool sharpenPass = true;
    float sharpenStr = 0.5f;
};

class ResolutionUpscaler {
    UpscaleConfig cfg;
    int renderW = 0, renderH = 0;
    bool active = false;
public:
    void Init(const UpscaleConfig& c = {}) {
        cfg = c;
        renderW = (int)(cfg.outputWidth * cfg.renderScale);
        renderH = (int)(cfg.outputHeight * cfg.renderScale);
        active = true;
        std::cout << "[StS2 Upscale] Render: " << renderW << "x" << renderH
                  << " -> Output: " << cfg.outputWidth << "x" << cfg.outputHeight << std::endl;
    }
    void SetScale(float s) {
        cfg.renderScale = std::clamp(s, 0.25f, 1.0f);
        renderW = (int)(cfg.outputWidth * cfg.renderScale);
        renderH = (int)(cfg.outputHeight * cfg.renderScale);
    }
    float GetPixelRatio() const { return cfg.renderScale * cfg.renderScale; }
    void Shutdown() { active = false; }
};

} // namespace STSTweaks
