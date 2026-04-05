/*
 * UI Scaler — Slay the Spire 2 Mod Pack
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

namespace STSTweaks {

struct UIElement { std::string name; float x, y, scale = 1.0f, alpha = 1.0f; bool vis = true; };

class UIScaler {
    std::unordered_map<std::string, UIElement> els;
    void Reg(const std::string& n, float x, float y) { els[n] = {n, x, y}; }
public:
    void Init() {
        Reg("energy_orb", 0.08f, 0.88f); Reg("deck_count", 0.9f, 0.88f);
        Reg("discard_pile", 0.92f, 0.88f); Reg("draw_pile", 0.06f, 0.88f);
        Reg("hp_bar", 0.5f, 0.92f); Reg("gold_counter", 0.85f, 0.02f);
        Reg("floor_counter", 0.5f, 0.02f); Reg("map_button", 0.95f, 0.02f);
        Reg("potion_slots", 0.15f, 0.02f); Reg("relic_bar", 0.02f, 0.02f);
        Reg("intent_icons", 0.5f, 0.3f); Reg("buff_debuff", 0.5f, 0.75f);
        std::cout << "[StS2 UI] " << els.size() << " elements registered" << std::endl;
    }
    void SetScale(const std::string& n, float s) {
        if (els.count(n)) els[n].scale = std::clamp(s, 0.3f, 3.0f);
    }
    void SetAlpha(const std::string& n, float a) {
        if (els.count(n)) els[n].alpha = std::clamp(a, 0.0f, 1.0f);
    }
    void ScaleAll(float s) { for (auto& [n, e] : els) e.scale = std::clamp(s, 0.3f, 3.0f); }
    void Shutdown() { std::cout << "[StS2 UI] Shutdown" << std::endl; }
};

} // namespace STSTweaks
