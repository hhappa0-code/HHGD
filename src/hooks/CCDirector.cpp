#include <Geode/Geode.hpp>
#include <Geode/modify/CCDirector.hpp>
#include "../utils/SettingsManager.hpp"

using namespace geode::prelude;

class $modify(HHGDCCDirector, CCDirector)
{
    $override
    void drawScene()
    {
        CCDirector::drawScene();

        float dt = this->getDeltaTime();

        SettingsManager::get().update(dt);
    }
};
