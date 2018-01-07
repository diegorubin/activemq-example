#include <gmock/gmock.h>

#include <services/message_processor.h>

class MockMessageProcessor : public MessageProcessor {
  public:
    MockMessageProcessor(unsigned char *message);

    MOCK_METHOD1(logInfo, void(string logMessage));
};

