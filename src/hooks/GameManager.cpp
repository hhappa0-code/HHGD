#include <Geode/Geode.hpp>
#include <Geode/modify/GameManager.hpp>
#include "../utils/SettingsManager.hpp"

using namespace geode::prelude;

class $modify(HHGDGameManager, GameManager)
{
    $override
    bool getGameVariable(char const* key) {
        if (std::string(key) == "0071")
        {
            return SettingsManager::get().getBool("practice-music-sync");
        }

        return GameManager::getGameVariable(key);
    }
};
