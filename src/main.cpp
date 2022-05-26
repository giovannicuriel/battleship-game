#include <iostream>
#include <cstdlib>
#include "gui/world/world.hpp"
#include "gui/world/board-tile.hpp"
#include "gui/window.hpp"
#include "gui/events.hpp"
#include "logic/game-logic.hpp"

#include "event-broker/event-broker.hpp"
#include "event-broker/subscriber.hpp"
#include "event-broker/subscription-handler-factory.hpp"
#include <unistd.h>
#include <logic/minefield/minefield.hpp>

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


// int main_gui(void)
// {
//     World world;
//     GameLogic logic;
//     Window window = Window(&world);

//     window.init();
//     // TODO Improve this thing. Try to use unique_ptr or something else
//     for (auto x = 0; x < 8; x++)
//     {
//         for (auto y = 0; y < 8; y++)
//         {
//             BoardTile *tile = new BoardTile(window.renderer, & logic, {
//                 origin : Point({x : x * 50, y : y * 50}),
//                 size : Size({x : 50, y : 50}),
//                 hasShip : rand() % 2 == 0
//             });
//             logic.addBoardTile(tile);
//             world.addWorldObject(tile);
//         }
//     }

//     bool shouldExit = false;
//     SDL_Event event;
//     while (!shouldExit)
//     {
//         while (SDL_PollEvent(&event) != 0)
//         {
//             // std::cout << "Received an event: " << event.type << "\n";
//             switch (event.type)
//             {
//             case SDL_QUIT:
//                 shouldExit = true;
//                 break;
//             case SDL_WINDOW_MOUSE_FOCUS:
//                 world.processEvent({type : MOUSE_ENTERED, point : {x : event.motion.x, y : event.motion.y}});
//                 break;
//             case SDL_MOUSEBUTTONDOWN:
//                 world.processEvent({type : MOUSE_CLICKED, point : {x : event.motion.x, y : event.motion.y}});
//                 break;
//             }
//         }
//         window.update();
//         SDL_Delay(1000 / 10);
//     }
//     return 0;
// };


// #include <list>

// struct ConvexPolygon {
//     std::list<Point> points;
//     bool contains(const Point &p) {
//         Point current = {x : 0, y : 0};
//         for (auto it : points) {
//             if (it.x < p.x) {
//                 current.x += -1;
//             } else if (it.x > p.x) {
//                 current.x += 1;
//             }

//             if (it.y < p.y) {
//                 current.y += -1;
//             } else if (it.y > p.y) {
//                 current.y += 1;
//             }
//         }
//         if (current.x != 0 && current.y != 0) {
//             return false;
//         }
//         return true;
//     }
// };


// struct Predicate {
//     virtual bool operator()() = 0;
// };

// class MouseClickedInside : public Predicate {
// protected:
//     int x;
//     int y;
// public:
//     MouseClickedInside(int x, int y) : x(x), y(y) {}
//     bool operator()() {
//         std::cout << "Mouse event at " << x << " " << y << "\n";
//         return true;
//     }
// };


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

#include <cli/command-builder.hpp>
#include <cli/cli.hpp>

int main_minefield_cli(void) {
    Field minefield;
    PatriciaTree<Node<CliCommand*, StringKeySpec>> commandTree;
    CliCommandBuilder builder { &commandTree, &minefield };
    Cli cli { &commandTree, &minefield, &builder};
    cli.run();
    return 0;
}
int main(void) {
    return main_minefield_cli();
}