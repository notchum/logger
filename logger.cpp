/** 
 * @file   logger.cpp
 * 
 * @author Morgan Chumbley
 * 
 * @date   December 12th, 2020
 */

#include "logger.hpp"

#include <fmt/color.h>
#include <fmt/core.h>

fmt::v7::color level_colors[] = {
   fmt::color::cyan,       // "\x1b[36m",
   fmt::color::lime_green, // "\x1b[32m",
   fmt::color::yellow,     // "\x1b[33m",
   fmt::color::red,        // "\x1b[31m",
   fmt::color::magenta     // "\x1b[35m"
} ;

static const char *level_names[] = {
   "DEBUG",
   "INFO ",
   "WARN ",
   "ERROR",
   "FATAL"
} ;

namespace LOG
{

   std::FILE *file = NULL   ;
   bool is_file_set = false ;

   void set_file_name ( const char *file_name )
   {
      if ( !is_file_set )
      {
         file = std::fopen(file_name, "w");
         if (!file)
         {
            throw fmt::system_error(errno, "cannot open file '{}'", file_name);
         }
         is_file_set = true ; 
         fmt::print(
         "┌{0:─^{2}}┐\n"
         "│{1: ^{2}}│\n"
         "└{0:─^{2}}┘\n", "", file_name, 6 + strlen(file_name));
      }
   }

   void LOG_LOG( int log_level, const char* str )
   {
      static bool otf = false ;
      if ( !is_file_set && !otf )
      {
         fmt::print( "hey uh you never set a file to log broh" ) ;
         otf = true ;
         return ;
      }
      else if ( is_file_set )
      {
            // get time
         time_t t = time(NULL) ;
         struct tm *info = localtime(&t) ;
         char buf[16] ;
         buf[strftime(buf, sizeof(buf), "%H:%M:%S", info)] = '\0' ;
 
            // print time -> log level -> message
         fmt::print( "{} ", buf ) ;
         fmt::print( fmt::fg(level_colors[log_level]) | fmt::emphasis::bold, "{} ", level_names[log_level] ) ;
         fmt::print( "{}\n", str ) ;

            // write the same stuff to file
         fmt::print( file, "{} ", buf ) ;
         fmt::print( file, "{} ", level_names[log_level] ) ;
         fmt::print( file, "{}\n", str ) ;
      }
   }

   void INFO  ( const char *str ) { LOG_LOG( LOG_INFO,  str ) ; }
   void DEBUG ( const char *str ) { LOG_LOG( LOG_DEBUG, str ) ; }
   void WARN  ( const char *str ) { LOG_LOG( LOG_WARN,  str ) ; }
   void ERROR ( const char *str ) { LOG_LOG( LOG_ERROR, str ) ; }
   void FATAL ( const char *str ) { LOG_LOG( LOG_FATAL, str ) ; }

} // end namespace LOG
