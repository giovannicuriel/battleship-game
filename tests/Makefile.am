
if UNIT_TESTS_ENABLED
check_PROGRAMS = battleship-tests
TESTS = battleship-tests
endif

battleship_tests_SOURCES = \
    event-broker/event-broker-tests.cpp

battleship_tests_LDADD = $(SDL_LIBS) $(GTEST_LIBS) ../src/libbattleship.a
