#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <Arduino.h>
#include "port_log.h"

#define DEBUG_SERIAL_BAUDRATE   (115200UL)

static struct {
    enum LogLevel level;
}sg_log_context;

static int8_t log_init(void* param){
    if(param == NULL){
        return -1;
    }
    sg_log_context.level = (*(enum LogLevel*)param);
    Serial.begin(DEBUG_SERIAL_BAUDRATE);
    return 0;
}
static int8_t log_print(const char *format,va_list arg){
    char temp[200] = {0};
    memset(temp, 0, sizeof(temp));
    int8_t len = vsnprintf(temp, sizeof(temp), format, arg);
    if (len > (sizeof(temp) - 1)) {
        Serial.println("Log buffer overflow.");
        return -1;
    }
    Serial.print(temp);
    return len;
}

static int8_t log_debug(const char *format, ...){
    if(sg_log_context.level > LOG_DEBUG_LEVEL){
        return -1;
    }
    va_list arg;
    va_start(arg, format);
    int8_t result = log_print(format, arg);
    va_end(arg);
    return result;
}
static int8_t log_info(const char *format, ...){
    if(sg_log_context.level > LOG_INFO_LEVEL){
        return -1;
    }
    va_list arg;
    va_start(arg, format);
    int8_t result = log_print(format, arg);
    va_end(arg);
    return result;
}
static int8_t log_warn(const char *format, ...){
    if(sg_log_context.level > LOG_WARN_LEVEL){
        return -1;
    }
    va_list arg;
    va_start(arg, format);
    int8_t result = log_print(format, arg);
    va_end(arg);
    return result;
}
static int8_t log_error(const char *format, ...){
    if(sg_log_context.level > LOG_ERROR_LEVEL){
        return -1;
    }
    va_list arg;
    va_start(arg, format);
    int8_t result = log_print(format, arg);
    va_end(arg);
    return result;
}
static int8_t log_fatal(const char *format, ...){
    if(sg_log_context.level > LOG_FATAL_LEVEL){
        return -1;
    }
    va_list arg;
    va_start(arg, format);
    int8_t result = log_print(format, arg);
    va_end(arg);
    return result;
}
struct Logger g_logger = {
    .init   = log_init,
    .debug  = log_debug,
    .info   = log_info,
    .warn   = log_warn,
    .error  = log_error,
    .fatal  = log_fatal,
};
