#include "services/message_processor.h"

MessageProcessor::MessageProcessor(unsigned char* message) {
  this->message = message;
}

void MessageProcessor::process() {
  string log = "receiving int: ";
  log.append(to_string(buffToInteger(message)));
  LoggerConfig::info(log);
}

int MessageProcessor::buffToInteger(unsigned char* buffer) {
  int value = static_cast<int>(static_cast<unsigned char>(buffer[0]) << 24 |
      static_cast<unsigned char>(buffer[1]) << 16 | 
      static_cast<unsigned char>(buffer[2]) << 8 | 
      static_cast<unsigned char>(buffer[3]));
  return value;
}

