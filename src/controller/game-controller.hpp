#ifndef __GAME_CONTROLLER_HPP__
#define __GAME_CONTROLLER_HPP__

#include <event-broker/subscriber.hpp>
#include <event-broker/event-broker.hpp>
#include <event-broker/events.hpp>
#include <logic/game-logic.hpp>

class GameController: public Subscriber {
protected:
    GameLogic m_Logic;
    EventBroker* m_Broker;
public:
    GameController(EventBroker* broker);
    void processEvent(Event* event);
    void start();
};

#endif // __GAME_CONTROLLER_HPP__