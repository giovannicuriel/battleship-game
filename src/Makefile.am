AM_CXXFLAGS= $(SDL_CFLAGS)
noinst_LIBRARIES = libbattleship.a
bin_PROGRAMS = battleship

if UNIT_TESTS_ENABLED
    AM_CXXFLAGS += -fprofile-arcs -ftest-coverage -coverage
endif

libbattleship_a_SOURCES = \
    types.cpp \
    utils.cpp \
    adapters/sdl-adapter-impl.cpp \
    event-broker/event-broker.cpp \
    event-broker/subscription-handler-factory.cpp \
    event-broker/subscription-handler.cpp \
    controller/window-controller.cpp \
    controller/board-controller.cpp \
    controller/game-controller.cpp \
    logic/game-logic.cpp \
    logic/minefield/minefield.cpp \
    cli/cli.cpp \
    gui/window.cpp \
    gui/world/world-object.cpp \
    gui/world/board-tile.cpp \
    gui/world/world.cpp \
    cli/command-builder.cpp \
    cli/command-palette.cpp \
    cli/input-reader.cpp

battleship_SOURCES= \
    main.cpp

battleship_LDADD = libbattleship.a -lpthread $(SDL_LIBS)
