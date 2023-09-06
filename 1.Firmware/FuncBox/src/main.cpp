#include <Arduino.h>
#include "log/port_log.h"

void setup() {
  enum LogLevel log_level = LOG_DEBUG_LEVEL;
  g_logger.init(&log_level);
}

void loop() {
  delay(500);
}