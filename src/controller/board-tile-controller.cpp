#include <iostream>
#include <controller/board-tile-controller.hpp>
#include <gui/world/board-tile.hpp>
#include <gui/events.hpp>
#include <event-broker/topics.hpp>

BoardTileController::BoardTileController(World* world, Window* window, EventBroker* broker):
    m_World(world),
    m_Window(window),
    m_Broker(broker) {

}

void BoardTileController::start() {
    m_Field.generate(Dimension { 8, 8}, 14);
    for (short int x = 0; x < 8; x++) {
        for (short int y = 0; y < 8; y++) {
            BoardTile *tile = new BoardTile(m_Window->renderer, {
                origin : Gui::Point({x : x * 50, y : y * 50}),
                size : Gui::Size({x : 50, y : 50}),
                coordinate: Point({x: x, y: y})
            });
            m_Tiles.push_back(tile);
            m_World->addWorldObject(tile);
        }
    }
}

void BoardTileController::processEvent(Event* event) {
    MouseEvent* mouseEvent = (MouseEvent*) event;
    switch (mouseEvent->type) {
        case MOUSE_CLICKED:
            processMouseClickedEvent(mouseEvent->point);
        default:
            break;
    }
}

void BoardTileController::processMouseClickedEvent(const Gui::Point& point) {
    std::map<::Point, BombCount> result;
    for (auto tile: m_Tiles) {
        if (tile->contains(point)) {
            Point tileCoordinate = tile->getCoordinate();
            result = m_Field.probe(tileCoordinate);
            
            if (result[tileCoordinate] == -1) {
                m_Broker->publish(GAME_EVENTS_TOPIC, new GameEvent { type: BOMB_BLOWN_UP });
            } else {
                m_Broker->publish(GAME_EVENTS_TOPIC, new GameEvent { type: AREA_CLEARED });
            }
            break;
        }
    }

    for (auto tile: m_Tiles) {
        Point tileCoordinate = tile->getCoordinate();
        if (result.find(tileCoordinate) != result.end()) {
            BombCount count = result[tileCoordinate];
            if (count == -1) {
                tile->setState(BLOWN_UP);
            } else {
                tile->setSurroundingBombCount(count);
            }
        }
    }
}