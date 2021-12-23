AM_CXXFLAGS=
if UNIT_TESTS_ENABLED
    AM_CXXFLAGS += -fprofile-arcs -ftest-coverage -coverage
    check_PROGRAMS = \
        event-broker-tests.run \
        subscription-handler-factory-tests.run
    TESTS = \
        event-broker-tests.run \
        subscription-handler-factory-tests.run
endif

event_broker_tests_run_SOURCES = event-broker/event-broker-tests.cpp
subscription_handler_factory_tests_run_SOURCES = event-broker/subscription-handler-factory-tests.cpp

default_deps = $(SDL_LIBS) $(GTEST_LIBS) ../src/libbattleship.a

event_broker_tests_run_LDADD = $(default_deps)
subscription_handler_factory_tests_run_LDADD = $(default_deps)
