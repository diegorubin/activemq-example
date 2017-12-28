#include "gateways/activemq/producer.h"

Producer::Producer(const string& brokerURI) : 
  brokerURI(brokerURI) {
}

Producer::~Producer() {
  cleanup();
}

void Producer::close() {
  this->cleanup();
}

void Producer::connect() {
  try {

    // Create a ConnectionFactory
    unique_ptr<ConnectionFactory> connectionFactory(
      ConnectionFactory::createCMSConnectionFactory(brokerURI));

    // Create a Connection
    connection = connectionFactory->createConnection();
    connection->start();

    session = connection->createSession(Session::AUTO_ACKNOWLEDGE);

    destination = session->createQueue("activemq.example.Queue");

    // Create a MessageProducer from the Session to the Topic or Queue
    producer = session->createProducer(destination);
    producer->setDeliveryMode(DeliveryMode::NON_PERSISTENT);

  } catch (CMSException& e) {
    e.printStackTrace();
  }
}

void Producer::publishText(string text) {
  std::unique_ptr<TextMessage> message(session->createTextMessage(text));
  message->setIntProperty("Integer", 0);
  producer->send(message.get());
}

void Producer::cleanup() {
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
      delete producer;
      producer = NULL;
      delete session;
      session = NULL;
      delete connection;
      connection = NULL;
  } catch (CMSException& e) {
      e.printStackTrace();
  }
}

