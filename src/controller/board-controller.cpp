#include <iostream>
#include <controller/board-controller.hpp>
#include <gui/world/board-tile.hpp>
#include <event-broker/events.hpp>
#include <event-broker/topics.hpp>

BoardController::BoardController(EventBroker* broker):
    m_Broker(broker) {
}

/**
 * Maybe, just maybe, window should not be here.
 */
void BoardController::addTilesTo(Window* window) {
    m_Field.generate(Area { 0, 0, 8, 8}, 14);
    for (short int x = 0; x < 8; x++) {
        for (short int y = 0; y < 8; y++) {
            BoardTile *tile = new BoardTile(window->getSdlAdapter(), {
                area : Area({x : x * 50, y : y * 50, w : 50, h : 50}),
                coordinate: Point({x: x, y: y})
            });
            m_Tiles.push_back(tile);
            window->addObject(tile);
        }
    }
}

void BoardController::processEvent(Event* event) {
    MouseEvent* mouseEvent = (MouseEvent*) event;
    switch (mouseEvent->type) {
        case MOUSE_CLICKED:
            processMouseClickedEvent(mouseEvent->point);
        default:
            break;
    }
}

void BoardController::processMouseClickedEvent(const Point& point) {
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

void BoardController::start() {
    m_Broker->subscribe(MOUSE_EVENTS_TOPIC, this);
}