#pragma once
#include <Geode/Geode.hpp>
#include <map>

using namespace geode::prelude;

class SettingsManager
{
private:
    std::map<std::string, bool> m_bools;
    std::map<std::string, int> m_ints;
    std::map<std::string, float> m_floats;
    std::map<std::string, std::string> m_strings;

    SettingsManager()
    {
        loadAll();
    }

public:
    static SettingsManager& get()
    {
        static SettingsManager instance;

        return instance;
    }

    void loadAll()
    {
        auto mod = Mod::get();

        m_bools["practice-music-sync"] = mod->getSavedValue<bool>("practice-music-sync", false);

        geode::log::info("Settings synced to cache.");
    }

    void saveAll()
    {
        auto mod = Mod::get();
        
        for (auto const& [k, v] : m_bools)
        {
            mod->setSavedValue<bool>(k, v);
        }

        for (auto const& [k, v] : m_ints)
        {
            mod->setSavedValue<int>(k, v);
        }

        for (auto const& [k, v] : m_floats)
        {
            mod->setSavedValue<float>(k, v);
        }

        for (auto const& [k, v] : m_strings)
        {
            mod->setSavedValue<std::string>(k, v);
        }

        mod->saveData();

        geode::log::info("Settings synced to config.");
    }

    void update(float dt)
    {
        static float saveTimer = 0.f;
        saveTimer += dt;

        if (saveTimer >= 300.f)
        {
            saveTimer = 0.f;
            this->saveAll();
        }
    }

    bool getBool(std::string k)
    {
        return m_bools[k];
    }

    int getInt(std::string k)
    {
        return m_ints[k];
    }

    float getFloat(std::string k)
    {
        return m_floats[k];
    }

    std::string getString(std::string k)
    {
        return m_strings[k];
    }

    void set(std::string k, bool v)
    {
        m_bools[k] = v;
    }
    void set(std::string k, int v)
    {
        m_ints[k] = v;
    }
    void set(std::string k, float v)
    {
        m_floats[k] = v;
    }
    void set(std::string k, std::string v)
    {
        m_strings[k] = v;
    }
};
