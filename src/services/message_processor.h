#ifndef __SERVICES_MESSAGE_PROCESSOR_H__
#define __SERVICES_MESSAGE_PROCESSOR_H__

#include "config/logger_config.h"

class MessageProcessor {

private:
  // attributes
  unsigned char* message;

  // methods
  int buffToInteger(unsigned char* buffer);

public:
  MessageProcessor(unsigned char* message);

  void process();
};

#endif

