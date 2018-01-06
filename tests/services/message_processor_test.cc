#include <gtest/gtest.h>
#include <services/message_processor.h>
#include <iostream>

namespace {

  class MessageProcessorTest : public ::testing::Test {
   protected:
    MessageProcessorTest() {

    }
  
    virtual ~MessageProcessorTest() {
    }
  
    virtual void SetUp() {
    }
  
    virtual void TearDown() {
    }
  
  };
  
  TEST_F(MessageProcessorTest, Process) {

    ASSERT_TRUE(true);
  }

}
