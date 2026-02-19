#include <Geode/Geode.hpp>
#include <Geode/modify/GameStatsManager.hpp>

using namespace geode::prelude;

class $modify(HHGDGameStatsManager, GameStatsManager)
{
    $override
    bool isItemUnlocked(UnlockType type, int id) {
        if (type == UnlockType::GJItem && id == 17)
        {
            return Mod::get()->getSavedValue<bool>("practice-music-sync");
        }
        
        return GameStatsManager::isItemUnlocked(type, id);
    }
};
