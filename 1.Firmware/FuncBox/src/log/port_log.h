#ifndef PORT_LOG_H
#define PORT_LOG_H
#include <stdint.h>

enum LogLevel{
    LOG_DEBUG_LEVEL,
    LOG_INFO_LEVEL,
    LOG_WARN_LEVEL,
    LOG_ERROR_LEVEL,
    LOG_FATAL_LEVEL,
};
struct Logger{
    int8_t (*init)(void*);
    int8_t (*debug)(const char *format, ...);
    int8_t (*info) (const char *format, ...);
    int8_t (*warn) (const char *format, ...);
    int8_t (*error)(const char *format, ...);
    int8_t (*fatal)(const char *format, ...);
};

extern struct Logger g_logger;

#define LOG_DEBUG(format, ...)  g_logger.debug("%s:%d: " format "\r\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define LOG_INFO(format, ...)   g_logger.info ("%s:%d: " format "\r\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define LOG_WARN(format, ...)   g_logger.warn ("%s:%d: " format "\r\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define LOG_ERROR(format, ...)  g_logger.error("%s:%d: " format "\r\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define LOG_FATAL(format, ...)  g_logger.fatal("%s:%d: " format "\r\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif