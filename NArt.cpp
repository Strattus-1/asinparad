#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

#include "fun_glavni.h"
#include "fun.h"
#include "otvarac.h"

#include"VMPolinomi.h"

int main( int argc, char** argv )
{
    std::fstream datoteka = otvarac( *( argv + 1 ), "in" );

    std::string linija;
    std::string prva_podniska;

    std::vector<Polinom> polinom;

    bool indikator = !datoteka.eof() && std::getline( datoteka, linija );
    while ( indikator )
    {
        std::istringstream strujanje_linije( linija );
        strujanje_linije >> prva_podniska;

        int tacka = prva_podniska.find( '.' );
        if( tacka != std::string::npos )
        {
            std::vector<double> niz = napravi_niz<double>( prva_podniska, strujanje_linije );
            polinom.emplace_back( niz , niz.size() );
            //PrintVektor<double>( niz, true );
        };
        

        indikator = !datoteka.eof() && std::getline( datoteka, linija );
    };

    Polinomi kolekcija;

    for( int i = 0; i < polinom.size(); i++ ){
        kolekcija.dodajPolinom( polinom[ i ] );
    };

    kolekcija.PrintVrednostSvih( 2 );
    

    PrintVektor< std::vector<Polinom> >( polinom, true );

    std::vector<Polinom>().swap( polinom );
    //std::vector<Polinomi>().swap( kolekcija );

    datoteka.close();
    return 0;
}
