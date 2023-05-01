
//
// Created by Killian on 31/03/2023.
//

#pragma once

#include "GameObject.h"

////////////////////////////////////////////////////////////////////////////
/// \brief  The layer responsible for updating and rendering the GUI objects
///
/// The GUI objects must be grouped together, because we need to render them
/// using a view corresponding to the window, otherwise the GUI will be rendered
/// in the world space, and not in the window space.
/// This object needs to be the last in the game object list, for it to render
/// the GUI on top of all other objects
///
/// \see GameObject
///
////////////////////////////////////////////////////////////////////////////
class GUILayer : public GameObject
{
public:
    void Init() override;
    void Update(float deltaTime) override;
    void Render(sf::RenderWindow& window) override;
    bool HandleEvent(const sf::Event& event) override;

    inline void AddGUIObject(const std::shared_ptr<GameObject>& guiObject) { m_guiObjects.push_back(guiObject); };

private:
    std::vector<std::shared_ptr<GameObject>> m_guiObjects;
};
