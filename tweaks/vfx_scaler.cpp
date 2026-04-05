/*
 * VFX Scaler — Slay the Spire 2 Mod Pack
 */
#include <iostream>
#include <algorithm>

namespace STSTweaks {

struct VFXConfig {
    float particleScale = 1.0f;
    float screenShakeScale = 1.0f;
    int maxParticles = 500;
    bool disableBloom = false;
    bool disableScreenDistort = false;
    float lightningQuality = 1.0f;
};

class VFXScaler {
    VFXConfig cfg;
    int activeParticles = 0;
    bool active = false;
public:
    void Init(const VFXConfig& c = {}) {
        cfg = c; active = true;
        std::cout << "[StS2 VFX] Scale: " << cfg.particleScale
                  << " Max particles: " << cfg.maxParticles << std::endl;
    }
    void SetScale(float s) { cfg.particleScale = std::clamp(s, 0.0f, 2.0f); }
    void SetMaxParticles(int m) { cfg.maxParticles = std::clamp(m, 50, 5000); }
    void ToggleBloom(bool on) { cfg.disableBloom = !on; }
    void ToggleShake(bool on) { cfg.screenShakeScale = on ? 1.0f : 0.0f; }
    bool ShouldSpawn() const { return activeParticles < cfg.maxParticles; }
    void Shutdown() { active = false; }
};

} // namespace STSTweaks
