#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

#include "fun_glavni.h"
#include "fun.h"
#include "otvarac.h"

#include "CPolinom.h"

int main( int argc, char** argv )
{
    std::fstream datoteka = otvarac( *( argv + 1 ), "in" );

    std::vector<Polinom> polinomi;                                                             // dodata linija

    std::string linija;
    std::string prva_podniska;

    bool indikator = !datoteka.eof() && std::getline( datoteka, linija );
    while ( indikator )
    {
        std::istringstream strujanje_linije( linija );
        strujanje_linije >> prva_podniska;

        int tacka = prva_podniska.find( '.' );
        if( tacka != std::string::npos )
        {
            std::vector<double> niz = napravi_niz<double>( prva_podniska, strujanje_linije );
            polinomi.emplace_back( niz, niz.size() );                                          // dodata linija
        };

        indikator = !datoteka.eof() && std::getline( datoteka, linija );
    };

    PrintVektor< std::vector<Polinom> >( polinomi, true );                                     // dodata linija

    std::vector<Polinom>().swap( polinomi );                                                   // dodata linija
    datoteka.close();

    return 0;
}
