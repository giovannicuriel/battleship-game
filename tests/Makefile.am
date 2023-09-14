AM_CXXFLAGS=
if UNIT_TESTS_ENABLED
    AM_CXXFLAGS += -fprofile-arcs -ftest-coverage -coverage $(GTEST_CFLAGS) -I"../src"
    check_PROGRAMS = \
        types-tests.run \
        event-broker-tests.run \
        subscription-handler-factory-tests.run \
        subscription-handler-tests.run
    TESTS = \
        types-tests.run \
        event-broker-tests.run\
        subscription-handler-factory-tests.run \
        subscription-handler-tests.run
endif

event_broker_tests_run_SOURCES = event-broker/event-broker-tests.cpp
types_tests_run_SOURCES = types-tests.cpp
subscription_handler_factory_tests_run_SOURCES = event-broker/subscription-handler-factory-tests.cpp
subscription_handler_tests_run_SOURCES = event-broker/subscription-handler-tests.cpp

default_deps = ../src/libbattleship.a $(SDL_LIBS) $(GTEST_LIBS)
event_broker_tests_run_LDADD = $(default_deps)
subscription_handler_factory_tests_run_LDADD = $(default_deps)
subscription_handler_tests_run_LDADD = $(default_deps)
types_tests_run_LDADD = $(default_deps)