AM_CXXFLAGS=
if UNIT_TESTS_ENABLED
    AM_CXXFLAGS += -fprofile-arcs -ftest-coverage -coverage $(GTEST_CFLAGS) -I"../src"
    check_PROGRAMS = \
        types-tests.run \
        event-broker-tests.run \
        subscription-handler-tests.run \
        subscription-handler-factory-tests.run \
        cli-tests.run \
        patricia-tree-tests.run \
        logic-types-tests.run \
        window-controller-tests.run \
        board-controller-tests.run \
        events-tests.run
    TESTS = \
        types-tests.run \
        event-broker-tests.run \
        subscription-handler-tests.run \
        subscription-handler-factory-tests.run \
        cli-tests.run \
        patricia-tree-tests.run \
        logic-types-tests.run \
        window-controller-tests.run \
        board-controller-tests.run \
        events-tests.run
endif

event_broker_tests_run_SOURCES = event-broker/event-broker-tests.cpp
subscription_handler_tests_run_SOURCES = event-broker/subscription-handler-tests.cpp
subscription_handler_factory_tests_run_SOURCES = event-broker/subscription-handler-factory-tests.cpp
events_tests_run_SOURCES = event-broker/events-tests.cpp
cli_tests_run_SOURCES = cli/cli-tests.cpp
patricia_tree_tests_run_SOURCES = cli/patricia-tree-tests.cpp
logic_types_tests_run_SOURCES = logic/types-tests.cpp
window_controller_tests_run_SOURCES = controller/window-controller-tests.cpp
board_controller_tests_run_SOURCES = controller/board-controller-tests.cpp
types_tests_run_SOURCES = types-tests.cpp

default_deps = ../src/libbattleship.a $(SDL_LIBS) $(GTEST_LIBS)
event_broker_tests_run_LDADD = $(default_deps)
subscription_handler_tests_run_LDADD = $(default_deps)
subscription_handler_factory_tests_run_LDADD = $(default_deps)
events_tests_run_LDADD = $(default_deps)
cli_tests_run_LDADD = $(default_deps)
patricia_tree_tests_run_LDADD = $(default_deps)
logic_types_tests_run_LDADD = $(default_deps)
window_controller_tests_run_LDADD = $(default_deps)
board_controller_tests_run_LDADD = $(default_deps)
types_tests_run_LDADD = $(default_deps)