//
// Created by Killian on 21/03/2023.
//

#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <utility>
#include "ResourceRegistry.h"
#include "GameObject.h"

class Player;

// The tile types the game supports (each type is associated to a class)
enum class TileType : uint8_t
{
    Ground = 0,
    PassagePoint = 1,
    Path = 2,
    Soil = 3
};

// We need to pack the structures to tell to the compiler to not add any padding
#pragma pack(push, 1)
// The header of the file
struct RawGameGrid
{
    uint32_t width;
    uint32_t height;
    uint32_t tilesetPathSize; // size of the tilemaps path
    uint32_t tilesSize; // total size of tiles
    uint32_t entitiesSize; // total size of entities
    uint8_t data[];
};

// The tile structure in the file
struct RawGameTile
{
    TileType type;
    uint32_t size; // size of total structure
    uint32_t texturesCount; // number of textures in data
    bool collidable;
    uint8_t data[]; // custom data
};

// The entity structure in the file (TODO)
struct RawGameEntity
{
    uint32_t size; // size of total structure
    uint32_t textureIndex; // offset in texture names
    uint8_t data[]; // custom data
};
#pragma pack(pop)

////////////////////////////////////////////////////////////
/// \brief  The grid system of the game
///
/// This class is responsible for the grid system of the game.
/// It can load a tilemap and a tileset, and use them to render
/// a game grid efficently using a vertex array and a render
/// texture.
/// This class is also responsible for the camera, using the
/// camera position and zoom factor, it can render the grid
/// at the right position and scale.
///
////////////////////////////////////////////////////////////
class GameGrid : public GameObject
{
public:
    GameGrid(const GameGrid& other) = delete;
    GameGrid& operator=(const GameGrid& other) = delete;
    GameGrid(GameGrid&& other) = delete;
    GameGrid& operator=(GameGrid&& other) = delete;

    ////////////////////////////////////////////////////////////////////////////
    /// \brief  The constructor
    ///
    /// The file needs to be in the HTF format described here :
    ///
    /// Header:
    /// --------------------------------------------------------------------------------------
    /// | width    | height   | tilesetPathSize | tilesSize | entitiesSize | tilesetPath     |
    /// --------------------------------------------------------------------------------------
    /// | uint32_t | uint32_t | uint32_t        | uint32_t  | uint32_t     | char[]          |
    /// --------------------------------------------------------------------------------------
    /// | 4        | 4        | 4               | 4         | 4            | tileSetPathSize |
    /// --------------------------------------------------------------------------------------
    /// ----------------------------
    /// | tiles     | entities     |
    /// ----------------------------
    /// | Tile[][]  | Entity[]     |
    /// ----------------------------
    /// | tilesSize | entitiesSize |
    /// ----------------------------
    ///
    /// Tile:
    /// ---------------------------------------------------------------
    /// | type     | size     | textureCount | collidable | data      |
    /// ---------------------------------------------------------------
    /// | uint8_t  | uint32_t | uint32_t     | bool       | uint8_t[] |
    /// ---------------------------------------------------------------
    /// | 1        | 4        | 4            | 1          | size - 9  |
    /// ---------------------------------------------------------------
    ///
    /// Entity: TODO
    ///
    /// \note This does not initializes the game grid, you need to call Init
    /// \see Init
    ///
    /// \param path the path to the file
    ///
    ////////////////////////////////////////////////////////////////////////////
    explicit GameGrid(std::string path) : m_path(std::move(path)) {}

    ////////////////////////////////////////////////////////////////////////////
    /// \brief  Initializes the game grid using the path given in the constructor
    ///
    /// This function initializes the game grid, it loads the tileset and the
    /// tilemap, and creates the vertex array and render texture.
    ///
    /// \see CreateVertexArray
    ///
    ////////////////////////////////////////////////////////////////////////////
    void Init() override;

    ////////////////////////////////////////////////////////////////////////////
    /// \brief  Updates the game grid
    ///
    /// This function updates the game grid, rebuilds the vertex array, only
    /// rendering the visible tiles. It is also responsible for checking collisions
    /// between the player and the collidable tiles as well as the outer bounds of
    /// the map, and setting the view according to the player position and zoom.
    ///
    /// \param deltaTime the time since the last frame
    ///
    /// \see DynamicRectangleCollision
    /// \see CreateVertexArray
    /// \see GameObject::Update
    ///
    ////////////////////////////////////////////////////////////////////////////
    void Update(float deltaTime) override;

    ////////////////////////////////////////////////////////////////////////////
    /// \brief  Renders the game grid
    ///
    /// This function first renders the vertex array to the render texture, and
    /// then renders it as a sprite with the view set to the calculated view in
    /// Update(). This is done to avoid artifacts, as upscaling directly the
    /// vertex array will cause blank horieontal lines to appear between tiles.
    /// To avoid this, we can also render it using a custom shader.
    ///
    /// \param window the window to render to
    ///
    /// \see GameObject::Render
    ///
    ////////////////////////////////////////////////////////////////////////////
    void Render(sf::RenderWindow& window) override;

    ////////////////////////////////////////////////////////////////////////////
    /// \brief  Handles the events
    ///
    /// The game grid is responsible for the camera, so it handles the wheel
    /// scroll event to zoom in and out.
    ///
    /// \param event the event to handle
    /// \return true if other objects should not handle the event
    ///
    /// \see GameObject::HandleEvent
    ///
    ////////////////////////////////////////////////////////////////////////////
    bool HandleEvent(const sf::Event& event) override;

    ////////////////////////////////////////////////////////////////////////////
    /// \brief  Sets the player
    ///
    /// \param player the player
    ///
    /// \see Player
    ////////////////////////////////////////////////////////////////////////////
    inline void SetPlayer(const std::shared_ptr<Player>& player) { m_player = player; }

    ////////////////////////////////////////////////////////////////////////////
    /// \brief  A class representing a tile
    ///
    /// This class is the base class for all tiles. It is responsible for
    /// the texture indices of the tile, and the parsing of the raw tile
    /// structure.
    ///
    /// \see Tile::ParseRawTile
    ////////////////////////////////////////////////////////////////////////////
    class Tile
    {
    public:
        explicit Tile(const std::vector<uint32_t>& textureIndices, sf::Vector2f position, bool collidable)
            : m_textureIndices(textureIndices), m_position(position), m_collidable(collidable)
        {}

        Tile(const Tile& other) = delete;
        Tile& operator=(const Tile& other) = delete;

        virtual ~Tile() = default;

        virtual void Update(float deltaTime, GameGrid& grid, const std::shared_ptr<Player>& player) = 0;
        [[nodiscard]] virtual TileType GetType() const = 0;

        [[nodiscard]] inline sf::FloatRect GetBoundingBox() const { return {m_position * TILE_SIZE, sf::Vector2f(TILE_SIZE, TILE_SIZE)}; }
        [[nodiscard]] inline uint32_t GetTextureIndex(uint64_t index) const { return m_textureIndices[index]; }

    protected:
        friend GameGrid;

        ////////////////////////////////////////////////////////////////////////////
        /// \brief  A factory function to create a tile from a the raw tile structure
        ///
        /// \param rawTile the raw tile structure
        /// \return A new tile subclass
        ///
        ////////////////////////////////////////////////////////////////////////////
        static std::unique_ptr<Tile> ParseRawTile(RawGameTile* rawTile, sf::Vector2f position);

        sf::Vector2f m_position;
        std::vector<uint32_t> m_textureIndices;
        bool m_collidable;
    };

    ////////////////////////////////////////////////////////////////////////////
    /// \brief  Get a mutable reference to the tile at the given position
    ///
    /// \param x the x position
    /// \param y the y position
    /// \return the tile at the given position
    ///
    /// \see Tile
    ///
    ////////////////////////////////////////////////////////////////////////////
    [[nodiscard]] std::unique_ptr<Tile>& GetTile(int x, int y);


    ////////////////////////////////////////////////////////////////////////////
    /// \brief  Sets the texture index of a tile's layer
    ///
    /// This function must be used with caution: the layer must be between 0 and
    /// the tile's layer count, otherwise the function will throw an exception.
    ///
    /// \param x the x position
    /// \param y the y position
    /// \param layer the layer of the tile
    /// \param textureIndex the new texture index
    /// \return the tile at the given position
    ///
    /// \see Tile
    ///
    ////////////////////////////////////////////////////////////////////////////
    void SetTextureIndexAtTile(int x, int y, uint64_t layer, uint32_t textureIndex);

    ////////////////////////////////////////////////////////////////////////////
    /// \brief  Updates an area of connected soils
    ///
    /// When a new soil tile is added or an existing one is deleted, we need to
    /// call this function to update the neighbouring soil tile's textures.
    ///
    /// \param pos the position of the updated tile
    ///
    /// \see Tile
    ///
    ////////////////////////////////////////////////////////////////////////////
    void UpdateSoilArea(sf::Vector2f pos);

    [[nodiscard]] uint32_t GetWidth() const { return m_width; }
    [[nodiscard]] uint32_t GetHeight() const { return m_height; }

    static constexpr float TILE_SIZE = 32.0f;

protected:
    friend Tile;

private:
    ////////////////////////////////////////////////////////////////////////////
    /// \brief  Creates a vertex array from the tilemap
    ///
    /// This function needs to be called each frame, because it only renders the
    /// visible tiles at a given frame
    ///
    /// \return a vertex array
    ///
    ////////////////////////////////////////////////////////////////////////////
    sf::VertexArray CreateVertexArray();

    static constexpr float ZOOM_SPEED = 20.0f;
    static constexpr float DEFAULT_VIEW_WIDTH = 39.0f * TILE_SIZE;

    std::string m_path;

    TextureRegistry::ResourceHandle m_tilesetTexture;
    std::vector<std::unique_ptr<Tile>> m_tiles;
    std::vector<std::unique_ptr<Tile>*> m_collidableTiles;
    uint32_t m_width = 0;
    uint32_t m_height = 0;

    sf::VertexArray m_vertexArray;
    sf::RenderStates m_renderState;
    sf::View m_renderView;
    sf::RenderTexture m_renderTexture;

    float m_zoomFactor = 1.0f;
    float m_zoomDelta = 0.0f;

    std::shared_ptr<Player> m_player;
};