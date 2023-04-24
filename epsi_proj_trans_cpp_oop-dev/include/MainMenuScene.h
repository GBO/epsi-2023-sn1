//
// Created by Killian on 16/03/2023.
//

#pragma once

#include <Scene.h>
#include <queue>
#include "ResourceRegistry.h"
#include "GameGrid.h"
#include "Player.h"
#include "GUILayer.h"
#include "Inventory.h"

// A temporary scene

class MainMenuScene : public Scene
{
public:
    MainMenuScene();
    ~MainMenuScene() override;

    void Init() override;
    void Update(float deltaTime) override;
    void Render(sf::RenderWindow& window) override;
    void HandleEvent(const sf::Event& event) override;

private:
    std::atomic_bool m_loaded = false;

    TextureRegistry::ResourceHandle m_loadingScreenTexture;
    sf::Sprite m_loadingScreenSprite;

    TextureRegistry::ResourceHandle m_mainMenuTexture;
    sf::Sprite m_mainMenuSprite;

    sf::Vector2f m_movement;

    std::shared_ptr<Player> m_player;
    std::shared_ptr<GameGrid> m_testGameGrid;
    std::shared_ptr<GUILayer> m_guiLayer;
    std::shared_ptr<Inventory> m_inventory;
    std::shared_ptr<Hotbar> m_hotbar;
};