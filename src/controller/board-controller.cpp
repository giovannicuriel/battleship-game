#include <iostream>
#include <controller/board-controller.hpp>
#include <gui/world/board-tile.hpp>
#include <event-broker/events.hpp>
#include <event-broker/topics.hpp>
#include <utils.hpp>

BoardController::BoardController(
        EventBroker* broker,
        Field* field,
        BoardControllerConfig config,
        EventFactory* eventFactory
    ):
    m_Broker(broker),
    m_Field(field),
    m_Config(config),
    m_EventFactory(eventFactory) {
}

/**
 * Maybe, just maybe, window should not be here.
 */
void BoardController::addTilesTo(Window* window) {
    m_Field->generate(
        Area { 0, 0, m_Config.boardSize.x, m_Config.boardSize.y },
        m_Config.nBombs
    );
    for (short int x = 0; x < m_Config.boardSize.x; x++) {
        for (short int y = 0; y < m_Config.boardSize.y; y++) {
            BoardTile *tile = new BoardTile(window->getSdlAdapter(), {
                area : Area {
                    x : x * m_Config.tileSize.x,
                    y : y * m_Config.tileSize.y,
                    w : m_Config.tileSize.x,
                    h : m_Config.tileSize.y
                },
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
    std::map<Point, BombCount> result;
    for (auto tile: m_Tiles) {
        std::cout << "Testing tile at " << tile->getCoordinate() << "\n";
        std::cout << ">>> Does it contains point " << point << "? " << tile->contains(point) << "\n";
        if (tile->contains(point)) {
            Point tileCoordinate = tile->getCoordinate();
            result = m_Field->probe(tileCoordinate);
            Event* event;
            if (result[tileCoordinate] == -1) {
                event = m_EventFactory->buildGameEvent(BOMB_BLOWN_UP);
            } else {
                event = m_EventFactory->buildGameEvent(AREA_CLEARED);
            }
            m_Broker->publish(GAME_EVENTS_TOPIC, event);
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