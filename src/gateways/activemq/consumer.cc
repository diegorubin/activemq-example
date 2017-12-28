#include "gateways/activemq/consumer.h"

Consumer::Consumer(const string& brokerURI) : 
  brokerURI(brokerURI) {
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
    destination = session->createQueue("activemq.example.Queue");

    // Create a MessageConsumer from the Session to the Queue
    consumer = session->createConsumer(destination);

    cout << "consumer connected!" << endl;
    while(true) {
      this->onMessage(consumer->receive());
    }

  } catch (CMSException& e) {
    e.printStackTrace();
  }
}

void Consumer::onMessage(const Message* message) {

  try {
      const TextMessage* textMessage = dynamic_cast<const TextMessage*> (message);
      string text = "";

      if (textMessage != NULL) {
          text = textMessage->getText();
      } else {
          text = "NOT A TEXTMESSAGE!";
      }

      cout << "Message received: " << text << endl;
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
