#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(HHGDMenuLayer, MenuLayer)
{
    $override
    bool init() {
        if (!MenuLayer::init())
        {
            return false;
        }

        auto closeMenu = static_cast<CCMenu*>(this->getChildByID("close-menu"));
        auto rightSideMenu = static_cast<CCMenu*>(this->getChildByID("right-side-menu"));

        auto closeButtonSprite = CCSprite::create("HHGD_closeBtn_001.png"_spr);
        closeButtonSprite->setScale(0.7f);
        auto restartButtonSprite = CCSprite::createWithSpriteFrameName("GJ_updateBtn_001.png");
        restartButtonSprite->setScale(0.7f);
        auto hhgdButtonSprite = ButtonSprite::create("HHGD");
        hhgdButtonSprite->setScale(0.7f);

        auto closeButton = static_cast<CCMenuItemSpriteExtra*>(closeMenu->getChildByID("close-button"));
        auto restartButton = CCMenuItemSpriteExtra::create(restartButtonSprite, this, menu_selector(HHGDMenuLayer::onRestartButtonClick));
        auto hhgdButton = CCMenuItemSpriteExtra::create(hhgdButtonSprite, this, menu_selector(HHGDMenuLayer::onHHGDButtonClick));

        closeButton->setSprite(closeButtonSprite);
        restartButton->setID("restart-button"_spr);
        closeMenu->addChild(restartButton);

        hhgdButton->setID("hhgd-button"_spr);
        rightSideMenu->addChild(hhgdButton);
        
        closeMenu->updateLayout();
        rightSideMenu->updateLayout();

        return true;
    }

    void onRestartButtonClick(CCObject* sender)
    {
        createQuickPopup("Restart Game", "Are you sure you want to <cy>restart</c>?", "Cancel", "Yes", [](auto, bool yesButton)
        {
            if (yesButton)
            {
                geode::utils::game::restart(true);
            }
        });
    }

    void onHHGDButtonClick(CCObject* sender)
    {

    }
};
