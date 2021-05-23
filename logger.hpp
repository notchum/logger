/**
 * @file   logger.hpp
 *
 * @author Morgan Chumbley
 *
 * @date   December 12th, 2020
 * 
 * @brief  For ANSI color usage in Windows use this reghack -- 
 *         in HKCU\Console create a DWORD named VirtualTerminalLevel 
 *         and set it to 0x1; then restart cmd.exe/powershell.exe
 */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <stdarg.h>
#include <stdio.h>
#include <time.h>

#include <fmt/color.h>
#include <fmt/format.h>
#include <fmt/core.h>

typedef enum
{
   DEBUG,
   INFO,
   WARN,
   ERROR,
   FATAL
} LogLevel ;

extern std::FILE *log_file  ;
extern bool is_file_set ;

void set_log_file( const char *file_name ) ;
void vlog( int log_level, const char* file, int line, fmt::string_view str, fmt::format_args args ) ;

template <typename S, typename... Args>
void log_log( int log_level, const char *file, int line, const S& format, Args&&... args )
{
   vlog(log_level, file, line, format, fmt::make_args_checked<Args...>(format, args...));
}

#define LOG_DEBUG(format, ...) log_log(DEBUG, __FILE__, __LINE__, FMT_STRING(format), ##__VA_ARGS__)
#define LOG_INFO(format, ...)  log_log(INFO , __FILE__, __LINE__, FMT_STRING(format), ##__VA_ARGS__)
#define LOG_WARN(format, ...)  log_log(WARN , __FILE__, __LINE__, FMT_STRING(format), ##__VA_ARGS__)
#define LOG_ERROR(format, ...) log_log(ERROR, __FILE__, __LINE__, FMT_STRING(format), ##__VA_ARGS__)
#define LOG_FATAL(format, ...) log_log(FATAL, __FILE__, __LINE__, FMT_STRING(format), ##__VA_ARGS__)

#endif // LOGGER_HPP
