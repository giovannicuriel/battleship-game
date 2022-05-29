#ifndef __BOARD_TILE_CONTROLLER_HPP__
#define __BOARD_TILE_CONTROLLER_HPP__

#include <vector>
#include <event-broker/event-broker.hpp>
#include <event-broker/subscriber.hpp>
#include <gui/world/world.hpp>
#include <gui/window.hpp>
#include <gui/world/board-tile.hpp>
#include <logic/minefield/minefield.hpp>

class BoardTileController: public Subscriber {
protected:
    World* m_World;
    Window* m_Window;
    std::vector<BoardTile*> m_Tiles;
    Field m_Field;
    EventBroker* m_Broker;
    void processMouseClickedEvent(const Gui::Point& point);
public:
    BoardTileController(World* world, Window* window, EventBroker* broker);
    void start();
    void processEvent(Event* event);
};
#endif // __BOARD_TILE_CONTROLLER_HPP__