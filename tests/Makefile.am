AUTOMAKE_OPTIONS = subdir-objects 

TESTS = tests
check_PROGRAMS = tests
tests_SOURCES = main.cc \
	services/message_processor_test.cc

ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

AM_CPPFLAGS = ${ActiveMQExample_CFLAGS}

AM_LIBS = ${ActiveMQExample_LIBS}

tests_CPPFLAGS = \
	-I/usr/include \
	-I$(includedir) \
	-I$(top_builddir)/src \
	$(AM_CPPFLAGS)

tests_LDADD = $(top_builddir)/src/services/consumer-message_processor.o \
	/usr/local/lib/libgtest.a \
	$(top_builddir)/src/config/consumer-logger_config.o \
	$(top_builddir)/src/config/consumer-application_config.o \
	${AM_LIBS} 

