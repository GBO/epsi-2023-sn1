//
// Created by Killian on 31/03/2023.
//
#include <Application.h>
#include "GUILayer.h"

void GUILayer::Init()
{
    for(auto& guiObject : m_guiObjects)
    {
        guiObject->Init();
    }
}

void GUILayer::Update(float deltaTime)
{
    for(auto& guiObject : m_guiObjects)
    {
        guiObject->Update(deltaTime);
    }
}

void GUILayer::Render(sf::RenderWindow& window)
{
    sf::View view(sf::FloatRect{{0, 0}, {
        static_cast<float>(Application::GetInstance().GetWindowWidth()),
        static_cast<float>(Application::GetInstance().GetWindowHeight())
    }});
    window.setView(view);

    for(auto& guiObject : m_guiObjects)
    {
        guiObject->Render(window);
    }
}

bool GUILayer::HandleEvent(const sf::Event& event)
{
    for(auto& guiObject : m_guiObjects)
    {
        if(guiObject->HandleEvent(event)) return true;
    }
    return false;
}