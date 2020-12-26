/**
 * @file   logger.hpp
 *
 * @author Morgan Chumbley
 *
 * @date   December 12th, 2020
 */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <fmt/color.h>

enum {
   LOG_DEBUG,
   LOG_INFO,
   LOG_WARN,
   LOG_ERROR,
   LOG_FATAL
} ;

namespace LOG
{
   extern std::FILE *file  ;
   extern bool is_file_set ;

   void set_file_name ( const char *file_name ) ;

   void LOG_LOG( int log_level, const char* str ) ;

   void DEBUG ( const char *str ) ;
   void INFO  ( const char *str ) ;
   void WARN  ( const char *str ) ;
   void ERROR ( const char *str ) ;
   void FATAL ( const char *str ) ;
}

#endif // LOGGER_HPP
