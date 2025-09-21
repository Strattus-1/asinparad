#include <iostream>
#include <fstream>

std::fstream otvarac( auto ime, auto mod )                                   // std::string ime, std::ios_base::openmode kako
{
    std::fstream datoteka;
    
    datoteka.open( ime, mod );                                               // in, out, binary, ate, app, trunc
    if ( !datoteka.is_open() )
    {
        std::cout << "Greška u otvaranju datoteke " << ime << std::endl;
        exit( EXIT_FAILURE );
    };
    
    return datoteka;
};
