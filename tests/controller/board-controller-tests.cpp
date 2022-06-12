#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../mocks/event-broker/mock-event-broker.hpp"
#include "../mocks/gui/mock-window.hpp"
#include "../mocks/adapters/mock-sdl-adapter.hpp"
#include "../mocks/logic/mock-field.hpp"
#include "../mocks/event-broker/mock-event.hpp"
#include <controller/board-controller.hpp>
#include <event-broker/topics.hpp>

using ::testing::_;
using ::testing::Return;
using ::testing::Pointee;
using ::testing::WhenDynamicCastTo;

class ChildBoardController: public BoardController {
public:
    ChildBoardController(
        EventBroker* broker,
        Field* field,
        BoardControllerConfig config,
        EventFactory* eventFactory
    ): BoardController(broker, field, config, eventFactory) { };
};

class BoardControllerTest: public ::testing::Test {
protected:
    void SetUp() override {

    };
    void TearDown() override {
        delete controller;
    };

    MockEventBroker mockEventBroker;
    MockField mockField;
    MockWindow mockWindow;
    MockSdlAdapter mockAdapter;
    MockEventFactory mockEventFactory;
    BoardController* controller;
};

TEST_F(BoardControllerTest, ShouldBuildAController) {
    BoardControllerConfig config { { x: 2, y: 2}, 2, { x: 10, y: 10} };
    controller = new BoardController(&mockEventBroker, &mockField, config, &mockEventFactory);
    /** Testing .2 constructors */
    ChildBoardController child(&mockEventBroker, &mockField, config, &mockEventFactory);
}

TEST_F(BoardControllerTest, ShouldAddTilesToAWindow) {
    EXPECT_CALL(mockWindow, getSdlAdapter())
        .Times(4)
        .WillRepeatedly(Return(&mockAdapter));
    EXPECT_CALL(mockWindow, addObject(_))
        .Times(4);
    EXPECT_CALL(mockField, generate(_, _));

    BoardControllerConfig config { { x: 2, y: 2}, 2, { x: 10, y: 10} };
    controller = new BoardController(&mockEventBroker, &mockField, config, &mockEventFactory);
    controller->addTilesTo(&mockWindow);
}

TEST_F(BoardControllerTest, ShouldProcessAnAreaClearedEvent) {
    BoardControllerConfig config { { x: 2, y: 2}, 2, { x: 10, y: 10} };
    std::map<Point, BombCount> mockProbeReturn = {
        { Point { 0, 0 }, 10 },
        { Point { 0, 1 }, -1 },
        { Point { 1, 0 }, 10 },
        { Point { 1, 1 }, 10 },
    };
    GameEvent blownUpEvent { type: BOMB_BLOWN_UP };
    GameEvent areaClearedEvent { type: AREA_CLEARED };

    EXPECT_CALL(mockField, probe(_))
        .Times(1)
        .WillRepeatedly(Return(mockProbeReturn));
    EXPECT_CALL(mockEventFactory, buildGameEvent(AREA_CLEARED))
        .Times(1)
        .WillRepeatedly(Return(&areaClearedEvent));
    EXPECT_CALL(mockEventFactory, buildGameEvent(BOMB_BLOWN_UP))
        .Times(0);
    EXPECT_CALL(mockEventBroker, publish(GAME_EVENTS_TOPIC, &areaClearedEvent))
        .Times(1);

    controller = new BoardController(&mockEventBroker, &mockField, config, &mockEventFactory);
    controller->addTilesTo(&mockWindow);
    MouseEvent eventT1 { type: MOUSE_CLICKED, point: { 5, 5 } };
    controller->processEvent(&eventT1);
}

TEST_F(BoardControllerTest, ShouldProcessABombBlownUpEvent) {
    BoardControllerConfig config { { x: 2, y: 2}, 2, { x: 10, y: 10} };
    std::map<Point, BombCount> mockProbeReturn = {
        { Point { 0, 0 }, 10 },
        { Point { 0, 1 }, -1 },
        { Point { 1, 0 }, 10 },
        { Point { 1, 1 }, 10 },
    };
    GameEvent blownUpEvent { type: BOMB_BLOWN_UP };
    GameEvent areaClearedEvent { type: AREA_CLEARED };

    EXPECT_CALL(mockField, probe(_))
        .Times(1)
        .WillRepeatedly(Return(mockProbeReturn));
    EXPECT_CALL(mockEventFactory, buildGameEvent(AREA_CLEARED))
        .Times(0);
    EXPECT_CALL(mockEventFactory, buildGameEvent(BOMB_BLOWN_UP))
        .Times(1)
        .WillRepeatedly(Return(&blownUpEvent));
    EXPECT_CALL(mockEventBroker, publish(GAME_EVENTS_TOPIC, &blownUpEvent))
        .Times(1);

    controller = new BoardController(&mockEventBroker, &mockField, config, &mockEventFactory);
    controller->addTilesTo(&mockWindow);
    MouseEvent eventT1 { type: MOUSE_CLICKED, point: { 5, 15 } };
    controller->processEvent(&eventT1);
}

TEST_F(BoardControllerTest, ShouldDoNothingIfEventTypeIsUnknown) {
    BoardControllerConfig config { { x: 2, y: 2}, 2, { x: 10, y: 10} };

    EXPECT_CALL(mockField, probe(_))
        .Times(0);
    EXPECT_CALL(mockEventFactory, buildGameEvent(_))
        .Times(0);
    EXPECT_CALL(mockEventFactory, buildGameEvent(_))
        .Times(0);
    EXPECT_CALL(mockEventBroker, publish(_, _))
        .Times(0);

    controller = new BoardController(&mockEventBroker, &mockField, config, &mockEventFactory);
    controller->addTilesTo(&mockWindow);
    MouseEvent eventT1 { type: MOUSE_ENTERED, point: { 5, 15 } };
    controller->processEvent(&eventT1);
}

TEST_F(BoardControllerTest, ShouldSubscribeOnlyToMouseEvents) {
    BoardControllerConfig config { { x: 2, y: 2}, 2, { x: 10, y: 10} };
    controller = new BoardController(&mockEventBroker, &mockField, config, &mockEventFactory);

    EXPECT_CALL(mockEventBroker, subscribe(MOUSE_EVENTS_TOPIC, controller))
        .Times(1);
    controller->start();
}