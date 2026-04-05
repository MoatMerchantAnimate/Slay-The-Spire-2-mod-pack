/*
 * Card Render Optimizer — Slay the Spire 2 Mod Pack
 */
#include <iostream>
#include <vector>
#include <string>

namespace STSTweaks {

struct CardRenderCfg {
    int maxHandBatch = 32;
    bool enableInstancing = true;
    int textureAtlasSize = 4096;
    float cardShadowQuality = 0.5f;
    bool cacheCardArt = true;
};

struct CardBatch {
    std::vector<int> cardIDs;
    int drawCalls = 0;
};

class CardRenderer {
    CardRenderCfg cfg;
    std::vector<CardBatch> batches;
    int totalDrawCalls = 0;
    bool active = false;
public:
    void Init(const CardRenderCfg& c = {}) {
        cfg = c; active = true;
        std::cout << "[StS2 Cards] Instancing: " << (cfg.enableInstancing ? "ON" : "OFF")
                  << " Atlas: " << cfg.textureAtlasSize << "px" << std::endl;
    }
    void OptimizeHand(const std::vector<int>& hand) {
        CardBatch batch;
        batch.cardIDs = hand;
        batch.drawCalls = cfg.enableInstancing ? 1 : (int)hand.size();
        batches.push_back(batch);
        totalDrawCalls += batch.drawCalls;
    }
    int GetDrawCalls() const { return totalDrawCalls; }
    void ResetFrame() { batches.clear(); totalDrawCalls = 0; }
    void Shutdown() { active = false; }
};

} // namespace STSTweaks
