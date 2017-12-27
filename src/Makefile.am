AUTOMAKE_OPTIONS = subdir-objects 

ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

AM_CPPFLAGS = ${Gnomato_CFLAGS} -std=c++11 -DGNOMATO_LOCALEDIR=\"${GNOMATO_LOCALEDIR}\"

bin_PROGRAMS = activemqexample

activemqexample_CPPFLAGS = \
	-I$(includedir)					\
	$(AM_CPPFLAGS)

activemqexample_SOURCES = main.cc 

