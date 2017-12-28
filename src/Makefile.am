AUTOMAKE_OPTIONS = subdir-objects 

ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

AM_CPPFLAGS = ${ActiveMQExample_CFLAGS} -std=c++11 -Wno-deprecated-declarations

bin_PROGRAMS = activemqexample

activemqexample_CPPFLAGS = \
	-I$(includedir)					\
	$(AM_CPPFLAGS)

activemqexample_SOURCES = main.cc \
	config.cc \
	gateways/activemq/consumer.cc \
	gateways/activemq/producer.cc

activemqexample_LDADD = ${ActiveMQExample_LIBS}

