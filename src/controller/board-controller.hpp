#ifndef __BOARD_TILE_CONTROLLER_HPP__
#define __BOARD_TILE_CONTROLLER_HPP__

#include <vector>
#include <event-broker/event-broker.hpp>
#include <event-broker/subscriber.hpp>
#include <gui/window.hpp>
#include <gui/world/board-tile.hpp>
#include <logic/minefield/minefield.hpp>
#include <types.hpp>

struct BoardControllerConfig {
    Size boardSize;
    uint8_t nBombs;
    Size tileSize;
};

class BoardController: public Subscriber {
protected:
    EventBroker* m_Broker;
    Field* m_Field;
    BoardControllerConfig m_Config;
    EventFactory* m_EventFactory;
    std::vector<BoardTile*> m_Tiles;
    void processMouseClickedEvent(const Point& point);
public:
    BoardController(
        EventBroker* broker,
        Field* field,
        BoardControllerConfig config,
        EventFactory* eventFactory
    );
    void addTilesTo(Window* window);
    void processEvent(Event* event);
    void start();
};
#endif // __BOARD_TILE_CONTROLLER_HPP__