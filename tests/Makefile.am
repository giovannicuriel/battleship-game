AM_CXXFLAGS= $(SDL_CFLAGS)
bin_PROGRAMS = battleship-tests

battleship_tests_SOURCES = \
    event-broker/event-broker-tests.cpp

battleship_tests_LDADD = $(SDL_LIBS) $(GTEST_LIBS) ../src/libbattleship.a
