/** 
 * @file   main.cpp
 * 
 * @author Morgan Chumbley
 * 
 * @date   December 12th, 2020
 */

#include "logger.hpp"
#include <string>

#if defined(_WIN32)
    #define PATH_DELIM "\\"
#elif defined(__linux__)
    #define PATH_DELIM "/"
#endif

int main ( int argc, char **argv )
{
    std::string file_path = __FILE__ ;
    std::string src_path = file_path.substr(0, file_path.rfind(PATH_DELIM)) ;
    std::string top_path = src_path.substr(0, src_path.rfind(PATH_DELIM)) ;
    LOG::set_file_name( (top_path + PATH_DELIM + "log.log").c_str() ) ;
    LOG::DEBUG( "damn" ) ;
    LOG::INFO( "yo" ) ;
    LOG::WARN( (top_path + PATH_DELIM + "log.log").c_str() ) ;
    LOG::ERROR( "Hello" ) ;
    LOG::FATAL( "Hello" ) ;
} // end main
