AM_CXXFLAGS= $(SDL_CFLAGS)
bin_PROGRAMS = battleship
noinst_LIBRARIES = libbattleship.a

if UNIT_TESTS_ENABLED
    AM_CXXFLAGS += -fprofile-arcs -ftest-coverage -coverage
endif

libbattleship_a_SOURCES = \
    gui/types.cpp \
    gui/window.cpp \
    gui/world/world-object.cpp \
    gui/world/board-tile.cpp \
    gui/world/world.cpp \
    controller/window-controller.cpp \
    controller/board-controller.cpp \
    controller/game-controller.cpp \
    logic/game-logic.cpp \
    logic/minefield/minefield.cpp \
    logic/types.cpp \
    event-broker/event-broker.cpp \
    event-broker/subscription-handler-factory.cpp \
    event-broker/subscription-handler.cpp \
    cli/cli.cpp \
    cli/command-builder.cpp \
    cli/command-palette.cpp \
    cli/input-reader.cpp

battleship_SOURCES= \
    main.cpp

battleship_LDADD = $(SDL_LIBS) libbattleship.a -lpthread
