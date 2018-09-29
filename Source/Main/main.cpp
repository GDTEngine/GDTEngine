/**
 * @file     main.cpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#include "Entity.hpp"
#include "PluginManager.hpp"
#include "RenderWindow.hpp"

using namespace gdt;

struct SAction
{
    friend class CEventManager;

public:

    using ActionCallback = void(*)(engine::CEntity*);

private:

    struct SCallbackInfo
    {
        ActionCallback actionCallback;
        engine::CEntity* pEntityPtr;
        core::EKeyState keyState;
    };

public:

    SAction(const std::string& actionId, core::EKeyCode key)
    {
        memcpy(this->actionId, actionId.c_str(), actionId.size() + 1);
        this->key = key;
    }

public:

    char actionId[32];
    core::EKeyCode key;

private:

    SCallbackInfo m_pCallbackInfo[8];
    int32 m_callbacksCount = 0;
};

class CEventManager
{
public:

    CEventManager()
    {
        
    }

    ~CEventManager()
    {
        
    }

    void bindAction(const std::string& actionId, core::EKeyState state, engine::CEntity* pEntity, SAction::ActionCallback actionCallback)
    {
        for (int32 i = 0; i < m_actions.size(); ++i)
        {
            if (!strcmp(m_actions[i].actionId, actionId.c_str()))
            {
                auto& callbackInfo = m_actions[i].m_pCallbackInfo[m_actions[i].m_callbacksCount];
                callbackInfo.keyState = state;
                callbackInfo.pEntityPtr = pEntity;
                callbackInfo.actionCallback = actionCallback;
                ++m_actions[i].m_callbacksCount;
                return;
            }
        }
    }

    static CEventManager& get()
    {
        static CEventManager instance;
        return instance;
    }

    void registerAction(const SAction& action)
    {
        m_actions.push_back(action);
    }

    void update(graphics::CRenderWindow& renderWindow)
    {
        for (int32 i = 0; i < m_actions.size(); ++i)
        {
            core::EKeyState state = renderWindow.getKeyState(m_actions[i].key);
            if (state != core::EKeyState::None)
            {
                for (int32 j = 0; j < m_actions[i].m_callbacksCount; ++j)
                {
                    auto& callbackInfo = m_actions[i].m_pCallbackInfo[j];
                    if (callbackInfo.keyState == state)
                    {
                        callbackInfo.actionCallback(callbackInfo.pEntityPtr);
                    }
                }
            }
        }
    }

private:

    std::vector<SAction> m_actions;

};

class CPlayer : engine::CEntity
{
public:

    CPlayer()
    {
        CEventManager::get().registerAction(SAction("MoveUp", core::EKeyCode::KeyW));
        CEventManager::get().registerAction(SAction("MoveDown", core::EKeyCode::KeyS));
        CEventManager::get().registerAction(SAction("MoveLeft", core::EKeyCode::KeyA));
        CEventManager::get().registerAction(SAction("MoveRight", core::EKeyCode::KeyD));

        auto movingUp = [](CEntity* entity) { LOG_MSG("MovingUp"); };
        auto movingDown = [](CEntity* entity) { LOG_MSG("MovingDown"); };
        auto movingLeft = [](CEntity* entity) { LOG_MSG("MovingLeft"); };
        auto movingRight = [](CEntity* entity) { LOG_MSG("MovingRight"); };

        CEventManager::get().bindAction("MoveUp", core::EKeyState::Pressed, this, movingUp);
        CEventManager::get().bindAction("MoveDown", core::EKeyState::Pressed, this, movingDown);
        CEventManager::get().bindAction("MoveLeft", core::EKeyState::Pressed, this, movingLeft);
        CEventManager::get().bindAction("MoveRight", core::EKeyState::Pressed, this, movingRight);
    }

    ~CPlayer()
    {
        
    }
};

int main(int argc, char* argv[])
{
    engine::CPluginManager::get().startUp();

    graphics::CRenderWindow window;
    window.create("Window", 1280, 720);

    while(true)
    {
        glfwPollEvents();
        window.clear();

        window.display();
    }

    getchar();
}
