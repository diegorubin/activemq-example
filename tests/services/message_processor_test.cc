#include <gtest/gtest.h>
#include <services/message_processor.h>

#include "services/mocks/mock_message_processor.h"

namespace {

  using ::testing::_;

  class MessageProcessorTest : public ::testing::Test {
   protected:
    MessageProcessorTest() {
      LoggerConfig::init();
    }
  
    virtual ~MessageProcessorTest() {
    }
  
    virtual void SetUp() {
    }
  
    virtual void TearDown() {
    }
  
  };
  
  TEST_F(MessageProcessorTest, Process) {
    unsigned char *message = new unsigned char[4];
    message[0] = 0x0;
    message[1] = 0x0;
    message[2] = 0x0;
    message[3] = 0x1f;
    MockMessageProcessor processor(message);

    string expected = "receiving int: 31";
    EXPECT_CALL(processor, logInfo(expected)).Times(1);

    processor.process();
  }

}
