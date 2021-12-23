#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([battleship], [0.0.1], [giovannicuriel@gmail.com])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AM_PROG_AR
AC_PROG_RANLIB

PKG_PROG_PKG_CONFIG

# Checks for libraries.
PKG_CHECK_MODULES([SDL], [
    sdl2
])

CXXFLAGS="$CXXFLAGS --std=c++20"

# Building also tests
AC_ARG_ENABLE([unit_tests], AS_HELP_STRING([--enable-unit-tests], [Build unit tests too]))
AM_CONDITIONAL([UNIT_TESTS_ENABLED], [test x$enable_unit_tests == xyes])
AS_IF([test x$enable_unit_tests == xyes],
    [PKG_CHECK_MODULES([GTEST], [ gtest_main, gmock ])]
)


# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 tests/Makefile
                 src/Makefile])
AC_OUTPUT
