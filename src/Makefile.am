AUTOMAKE_OPTIONS = subdir-objects 

ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

AM_CPPFLAGS = ${ActiveMQExample_CFLAGS} -std=c++11 -Wno-deprecated-declarations

bin_PROGRAMS = consumer producer

consumer_CPPFLAGS = \
	-I$(includedir)					\
	$(AM_CPPFLAGS)

producer_CPPFLAGS = \
	-I$(includedir)					\
	$(AM_CPPFLAGS)

consumer_SOURCES = consumer.cc \
	config/application_config.cc \
	gateways/activemq/consumer.cc

producer_SOURCES = producer.cc \
	config/application_config.cc \
	gateways/activemq/producer.cc

consumer_LDADD = ${ActiveMQExample_LIBS}
producer_LDADD = ${ActiveMQExample_LIBS}

