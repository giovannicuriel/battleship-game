// class SimpleSubscriber: public Subscriber {
// public:
//     void processEvent(Event* e) {
//         MouseClickedEvent* event = (MouseClickedEvent*)e;
//         std::cout << "Processing event: " << event->x << ", " << event->y << "\n";
//         sleep(1);
//     }
// };

// int main_subscriber(void) {

//     EventBroker eb { new SubscriptionHandlerFactoryImpl() };
//     SimpleSubscriber subs { };
//     std::string topic("sample-topic");
//     eb.subscribe(topic, &subs);
//     std::cout << "[main] waiting to send some events\n";
//     sleep(2);
//     std::cout << "[main] sending some events\n";

//     MouseClickedEvent ev1 { x: 10, y: 20 };
//     MouseClickedEvent ev2 { x: 10, y: 30 };
//     eb.publish(topic, &ev1);
//     eb.publish(topic, &ev2);
//     sleep(5);
//     return 0;
// }

// class EventData;


// class Subscriber {
// public:
//     Subscriber();
//     virtual ~Subscriber();
//     virtual void onEvent(EventData *data) = 0;
// };

// struct Subscription {
//     Subscriber * m_Subscriber;
//     Subscription * when(Predicate * predicate);
// }

// class Databroker
// {
// protected:
//     std::list<Subscriber> m_Subscribers;

// public:
//     Databroker();
//     virtual ~Databroker();
//     void addSubscriber(Subscriber *subscriber, Delegate *delegate, std::string topic);
//     void sendEvent(std::string topic, EventData * data);
// };


// void testIsInside(const Point &p, ConvexPolygon &polygon) {
//     std::cout << "Point " << p << " is inside: " << polygon.contains(p) << "\n";
// }

// int main_is_inside(void)
// {
//     std::cout << "Hello, World!" << std::endl;
//     ConvexPolygon polygon;
//     polygon.points.push_back({x : 1, y : 1});
//     polygon.points.push_back({x : 3, y : 11});
//     polygon.points.push_back({x : 14, y : 14});
//     polygon.points.push_back({x : 11, y : 3});

//     testIsInside({x : 0, y : 0}, polygon);
//     testIsInside({x : 1, y : 1}, polygon);
//     testIsInside({x : 1, y : 1}, polygon);
//     testIsInside({x : 1, y : 1}, polygon);
//     testIsInside({x : 1, y : 1}, polygon);
//     return 0;
// }
#include <controller/window-controller.hpp>
#include <controller/board-tile-controller.hpp>
#include <controller/game-controller.hpp>
#include <gui/world/world.hpp>
#include <event-broker/event-broker.hpp>
#include <event-broker/subscription-handler-factory.hpp>
#include <event-broker/topics.hpp>

int main(void) {
    SubscriptionHandlerFactoryImpl factory;
    EventBroker broker(&factory);
    World world;
    WindowController app(&world, &broker);
    GameController gameController(&broker);
    BoardTileController boardController(&world, &app.getWindow(), &broker);

    broker.subscribe(MOUSE_EVENTS_TOPIC, &boardController);
    broker.subscribe(GAME_EVENTS_TOPIC, &gameController);
    boardController.start();
    app.start();
    return 0;
}