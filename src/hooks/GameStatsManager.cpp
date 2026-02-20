#include <Geode/Geode.hpp>
#include <Geode/modify/GameStatsManager.hpp>
#include "../utils/SettingsManager.hpp"

using namespace geode::prelude;

class $modify(HHGDGameStatsManager, GameStatsManager)
{
    $override
    bool isItemUnlocked(UnlockType type, int id) {
        if (type == UnlockType::GJItem && id == 17)
        {
            return SettingsManager::get().getBool("practice-music-sync");
        }
        
        return GameStatsManager::isItemUnlocked(type, id);
    }
};
