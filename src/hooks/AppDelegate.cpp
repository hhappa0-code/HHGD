#include <Geode/Geode.hpp>
#include <Geode/modify/AppDelegate.hpp>
#include "../utils/SettingsManager.hpp"

using namespace geode::prelude;

class $modify(HHGDAppDelegate, AppDelegate)
{
    $override
    void applicationDidEnterBackground() {
        AppDelegate::applicationDidEnterBackground();

        SettingsManager::get().saveAll();
    }

    $override
    void trySaveGame(bool force) {
        AppDelegate::trySaveGame(force);
        
        SettingsManager::get().saveAll();
    }
};
