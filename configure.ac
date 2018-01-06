AC_INIT([ActiveMQExample],[0.1])

AC_CONFIG_SRCDIR([src])

AM_INIT_AUTOMAKE

AC_PROG_CC
AC_PROG_CXX

AC_PROG_INSTALL

PKG_CHECK_MODULES([ActiveMQExample],[activemq-cpp, liblog4cxx])

AC_ARG_WITH([tests], AS_HELP_STRING([--with-tests], [Check tests dependencies]))
AS_IF([test "x$with_tests" = "xyes"], [
  PKG_CHECK_MODULES([ActiveMQExampleTest], [gtest])
])

AC_CONFIG_FILES([
  src/Makefile
  tests/Makefile
])

AC_OUTPUT(Makefile)

