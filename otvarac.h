//
// path - ime fajla, ili putanja, npr "test.txt" ili "folder_name/test.txt"
// modu - modovi otvaranja datoteke => in, out, app, trunc, ate, bin, noreplace, string se interpretira u openmode tip
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

std::fstream otvarac( const std::string& path, const std::string& modu )
{   
	int i = 0;
	int j = 0;

	std::string mod;
	std::fstream datoteka;
    std::ios_base::openmode mode;

    mod = ukloni_znak( modu, ' ' );
	
    bool ind = true;

    if( ind && mod == "in" )               { mode = std::ios_base::in;                                                  ind = false; };
    if( ind && mod == "out" )              { mode = std::ios_base::out;                                                 ind = false; };
    if( ind && mod == "app" )              { mode = std::ios_base::app;                                                 ind = false; };
    if( ind && mod == "trunc" )            { mode = std::ios_base::trunc;                                               ind = false; };
    if( ind && mod == "bin" )              { mode = std::ios_base::binary;                                              ind = false; };
    if( ind && mod == "ate" )              { mode = std::ios_base::ate;                                                 ind = false; };
    if( ind && mod == "out|trunc" )        { mode = std::ios_base::out    | std::ios_base::trunc;                       ind = false; };
    if( ind && mod == "in|out" )           { mode = std::ios_base::in     | std::ios_base::out;                         ind = false; };
    if( ind && mod == "in|out|trunc" )     { mode = std::ios_base::in     | std::ios_base::out | std::ios_base::trunc;  ind = false; };
    if( ind && mod == "in|out|app" )       { mode = std::ios_base::in     | std::ios_base::out | std::ios_base::app;    ind = false; };
    if( ind && mod == "bin|out" )          { mode = std::ios_base::binary | std::ios_base::out;                         ind = false; };
    if( ind && mod == "bin|app" )          { mode = std::ios_base::binary | std::ios_base::app;                         ind = false; };
    if( ind && mod == "bin|in" )           { mode = std::ios_base::binary | std::ios_base::in;                          ind = false; };
    if( ind && mod == "bin|out|app" )      { mode = std::ios_base::binary | std::ios_base::out | std::ios_base::app;    ind = false; };
    if( ind && mod == "bin|in|app" )       { mode = std::ios_base::binary | std::ios_base::in  | std::ios_base::app;    ind = false; };
    if( ind && mod == "bin|in|out|trunc" ) { mode = std::ios_base::binary | std::ios_base::in  |
                                                    std::ios_base::out    | std::ios_base::trunc;                       ind = false; };
//  if( ind && mod == "noreplace" )        { mode = std::ios_base::noreplace;                                           ind = false; }; // C++ 23 standard


    if( ind ) exit( EXIT_FAILURE );

    datoteka.open( path, mode );

    if ( !datoteka.is_open() ) exit( EXIT_FAILURE );

    return datoteka;
};

/*
*  +---------------------------------------------------------+
*  | ios_base Flag combination            stdio equivalent   |
*  |binary  in  out  trunc  app                              |
*  +---------------------------------------------------------+
*  |             +                        w                  |
*  |             +           +            a                  |
*  |                         +            a                  |
*  |             +     +                  w                  |
*  |         +                            r                  |
*  |         +   +                        r+                 |
*  |         +   +     +                  w+                 |
*  |         +   +           +            a+                 |
*  |         +               +            a+                 |
*  +---------------------------------------------------------+
*  |   +         +                        wb                 |
*  |   +         +           +            ab                 |
*  |   +                     +            ab                 |
*  |   +         +     +                  wb                 |
*  |   +     +                            rb                 |
*  |   +     +   +                        r+b                |
*  |   +     +   +     +                  w+b                |
*  |   +     +   +           +            a+b                |
*  |   +     +               +            a+b                |
*  +---------------------------------------------------------+
*  
*/
