ActiveMQ Example
================

## Install dependencies

### Ubuntu

Running activemq

```
wget http://mirror.nbtelecom.com.br/apache/activemq/5.15.2/apache-activemq-5.15.2-bin.tar.gz
tar -zxvf apache-activemq-5.15.2-bin.tar.gz
cd apache-activemq-5.15.2
sudo bin/activemq start
```

Install activemq-cpp

`sudo apt-get install libgnutls-dev libapr1 libapr1-dev libtool build-essential
libcppunit libcppunit-dev liblog4cxx10v5 liblog4cxx10-dev`

```
wget http://ftp.unicamp.br/pub/apache/activemq/activemq-cpp/3.9.4/activemq-cpp-library-3.9.4-src.tar.gz
tar -zxvf activemq-cpp-library-3.9.4-src.tar.gz
cd activemq-cpp-library-3.9.4
./configure --prefix=/usr
make
sudo make install
```

## To Build

```
autoreconf -vi
./configure --prefix=/usr
make
```

## To Run

`src/consumer`

`src/producer`

With activemq running.

## To Run Tests

Install libgtest dependency

```
git clone https://github.com/google/googletest.git
cd googletest
cmake CMakeLists.txt
make
sudo make install
```

Run tests with

```
./configure --prefix=/usr --with-tests
make
make check
```

