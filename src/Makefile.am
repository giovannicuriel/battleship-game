AM_CXXFLAGS= $(SDL_CFLAGS)
bin_PROGRAMS = battleship
noinst_LIBRARIES = libbattleship.a

if UNIT_TESTS_ENABLED
    AM_CXXFLAGS += -fprofile-arcs -ftest-coverage -coverage
endif

libbattleship_a_SOURCES = \
    commons.cpp \
    logic/game-logic.cpp \
    gui/window.cpp \
    world/world-object.cpp \
    world/board-tile.cpp \
    world/world.cpp \
    event-broker/event-broker.cpp \
    event-broker/subscription-handler-factory.cpp \
    event-broker/subscription-handler.cpp

battleship_SOURCES= \
    main.cpp

battleship_LDADD = $(SDL_LIBS) libbattleship.a -lpthread
