#ifndef __BOARD_TILE_CONTROLLER_HPP__
#define __BOARD_TILE_CONTROLLER_HPP__

#include <vector>
#include <event-broker/event-broker.hpp>
#include <event-broker/subscriber.hpp>
#include <gui/window.hpp>
#include <gui/world/board-tile.hpp>
#include <logic/minefield/minefield.hpp>

class BoardController: public Subscriber {
protected:
    EventBroker* m_Broker;
    std::vector<BoardTile*> m_Tiles;
    Field m_Field;
    void processMouseClickedEvent(const Point& point);
public:
    BoardController(EventBroker* broker);
    void addTilesTo(Window* window);
    void processEvent(Event* event);
    void start();
};
#endif // __BOARD_TILE_CONTROLLER_HPP__