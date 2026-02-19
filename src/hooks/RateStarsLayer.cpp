#include <Geode/Geode.hpp>
#include <Geode/modify/RateStarsLayer.hpp>

using namespace geode::prelude;

class $modify(HHGDRateStarsLayer, RateStarsLayer)
{
    $override
    bool init(int levelID, bool platformer, bool moderator) {
        if (!RateStarsLayer::init(levelID, platformer, moderator))
        {
            return false;
        }

        auto level = GameLevelManager::get()->getSavedLevel(m_levelID);
        int requested = level->m_starsRequested;

        if (requested <= 0 || requested > 10)
        {
            return true;
        }

        m_mainLayer->getChildByType<CCMenu>(0)->getChildByType<CCMenuItemSpriteExtra>(requested - 1)->getChildByType<ButtonSprite>(0)->setColor(ccColor3B(0, 255, 0));

        return true;
    }
};
