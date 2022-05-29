#include <iostream>
#include <controller/game-controller.hpp>
#include <event-broker/topics.hpp>
#include <gui/events.hpp>

GameController::GameController(EventBroker* broker):
    m_Broker(broker),
    m_Logic(8) {

}

void GameController::processEvent(Event* event) {
    GameEvent* gameEvent = (GameEvent*)event;

    switch (gameEvent->type) {
        case BOMB_BLOWN_UP:
            m_Logic.increaseBlownUpBombCount();
            if (m_Logic.isGameOver()) {
                m_Broker->publish(GAME_EVENTS_TOPIC, new GameEvent { type: GAME_OVER });
            }
            break;
        case GAME_OVER:
            std::cout << "Game over\n";
            break;
        default:
            break;
    }
}