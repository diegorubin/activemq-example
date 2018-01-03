#include "gateways/activemq/consumer.h"

Consumer::Consumer(const string& brokerURI, const string& queueName) : 
  brokerURI(brokerURI),
  queueName(queueName) {
}

Consumer::~Consumer() {
  cleanup();
}

void Consumer::close() {
  this->cleanup();
}

void Consumer::connect() {

  try {

    // Create a ConnectionFactory
    unique_ptr<ConnectionFactory> connectionFactory(
      ConnectionFactory::createCMSConnectionFactory(brokerURI));

    // Create a Connection
    connection = connectionFactory->createConnection();
    connection->setExceptionListener(this);
    connection->start();

    // Create a Session
    session = connection->createSession(Session::AUTO_ACKNOWLEDGE);
    destination = session->createQueue(queueName);

    // Create a MessageConsumer from the Session to the Queue
    consumer = session->createConsumer(destination);

    LoggerConfig::info("consumer connected!");
    while(true) {
      this->onMessage(consumer->receive());
    }

  } catch (CMSException& e) {
    e.printStackTrace();
  }
}

void Consumer::onMessage(const Message* message) {

  try {
      const BytesMessage* bytesMessage = dynamic_cast<const BytesMessage*> (message);

      if (bytesMessage != NULL) {
        unsigned char buffer[4];
        bytesMessage->readBytes(buffer, 4);
        string log = "receiving int: ";
        log.append(to_string(buffToInteger(buffer)));
        LoggerConfig::info(log);
      } else {
        LoggerConfig::info("NOT A BINARYMESSAGE!");
      }

  } catch (CMSException& e) {
      e.printStackTrace();
  }
}

void Consumer::cleanup() {
  if (connection != NULL) {
    try {
      connection->close();
    } catch (cms::CMSException& ex) {
      ex.printStackTrace();
    }
  }

  // Destroy resources.
  try {
    delete destination;
    destination = NULL;
    delete consumer;
    consumer = NULL;
    delete session;
    session = NULL;
    delete connection;
    connection = NULL;
  } catch (CMSException& e) {
    e.printStackTrace();
  }
}

void Consumer::onException(const CMSException& ex AMQCPP_UNUSED) {
  cerr << "CMS Exception occurred. Shutting down client." << endl;
  ex.printStackTrace();
}

int Consumer::buffToInteger(unsigned char* buffer) {
    int value = static_cast<int>(static_cast<unsigned char>(buffer[0]) << 24 |
        static_cast<unsigned char>(buffer[1]) << 16 | 
        static_cast<unsigned char>(buffer[2]) << 8 | 
        static_cast<unsigned char>(buffer[3]));
    return value;
}
