#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/RateStarsLayer.hpp>

using namespace geode::prelude;

// Modify main menu
class $modify(CustomMenuLayer, MenuLayer)
{
    bool init() {
        if (!MenuLayer::init()) return false;

        auto closeMenu = this->getChildByID("close-menu");
        auto rightSideMenu = this->getChildByID("right-side-menu");

        auto hhgdSpr = ButtonSprite::create("HHGD");
        hhgdSpr->setScale(0.7f);
        auto closeSpr = CCSprite::create("HHGD_CloseBtn_001.png"_spr);
        closeSpr->setScale(0.7f);
        auto restartSpr = CCSprite::createWithSpriteFrameName("GJ_updateBtn_001.png");
        restartSpr->setScale(0.7f);
        auto hhgdBtn = CCMenuItemSpriteExtra::create(hhgdSpr, this, menu_selector(CustomMenuLayer::onHHGDClick));
        auto closeBtn = static_cast<CCMenuItemSpriteExtra*>(closeMenu->getChildByID("close-button"));
        auto restartBtn = CCMenuItemSpriteExtra::create(restartSpr, this, menu_selector(CustomMenuLayer::onRestartClick));

        // Close Menu
        // Add custom close and restart buttons
        closeBtn->setSprite(closeSpr);
        closeMenu->addChild(restartBtn);
        restartBtn->setID("restart-button"_spr);
        closeMenu->updateLayout();

        // Right Side Menu
        // Add HHGD button
        rightSideMenu->addChild(hhgdBtn);
        hhgdBtn->setID("hhgd-button"_spr);
        rightSideMenu->updateLayout();
        
        return true;
    }

    void onRestartClick(CCObject* sender)
    {
        createQuickPopup("Restart Game", "Are you sure you want to <cy>restart</c>?", "Cancel", "Yes", [](auto, bool btn2)
        {
            if (btn2)
            {
                geode::utils::game::restart(true);
            }
        });
    }

    void onHHGDClick(CCObject* sender)
    {
        geode::log::warn("Not yet implemented");
    }
};

// Modify rating screen
class $modify(CustomRateStarsLayer, RateStarsLayer)
{
    $override
    bool init(int levelID, bool platformer, bool moderator) {
        if (!RateStarsLayer::init(levelID, platformer, moderator)) return false;

        // Color rating button which level creator suggested green
        auto level = GameLevelManager::get()->getSavedLevel(m_levelID);
        int requested = level->m_starsRequested;

        if (requested <= 0 || requested > 10) return true;

        m_mainLayer->getChildByType<CCMenu>(0)->getChildByType<CCMenuItemSpriteExtra>(requested - 1)->getChildByType<ButtonSprite>(0)->setColor(ccColor3B(0, 255, 0));

        return true;
    }
};
