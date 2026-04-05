/*
 * Animation Speed Control — Slay the Spire 2 Mod Pack
 */
#include <iostream>
#include <algorithm>

namespace STSTweaks {

struct AnimConfig {
    float cardPlaySpeed = 1.0f;
    float enemyTurnSpeed = 1.0f;
    float transitionSpeed = 1.0f;
    float vfxSpeed = 1.0f;
    float damageNumberSpeed = 1.5f;
};

class AnimationController {
    AnimConfig cfg;
    bool active = false;
public:
    void Init(const AnimConfig& c = {}) {
        cfg = c; active = true;
        std::cout << "[StS2 Anim] Card: " << cfg.cardPlaySpeed << "x Enemy: "
                  << cfg.enemyTurnSpeed << "x" << std::endl;
    }
    void SetCardSpeed(float s)   { cfg.cardPlaySpeed = std::clamp(s, 0.5f, 10.0f); }
    void SetEnemySpeed(float s)  { cfg.enemyTurnSpeed = std::clamp(s, 0.5f, 10.0f); }
    void SetTransition(float s)  { cfg.transitionSpeed = std::clamp(s, 0.5f, 5.0f); }
    void SetAll(float s) {
        cfg.cardPlaySpeed = cfg.enemyTurnSpeed = cfg.transitionSpeed = cfg.vfxSpeed = s;
    }
    float GetTotalTimeScale() const {
        return (cfg.cardPlaySpeed + cfg.enemyTurnSpeed + cfg.transitionSpeed) / 3.0f;
    }
    void Shutdown() { active = false; }
};

} // namespace STSTweaks
