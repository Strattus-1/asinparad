#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

#include "fun_gl1.h"
#include "fun.h"
#include "otvarac.h"

#include "CPolinom.h"
#include "CPrskotina.h"
#include "CTalasi.h"
#include "fun_gl2.h"

int main( int argc, char** argv )
{
    std::fstream datoteka1 = otvarac( *( argv + 1 ), "in" );
    std::fstream datoteka2 = otvarac( *( argv + 2 ), "in" );
    int izbrojano_u_redu = atoi( *( argv + 3 ) );


    std::vector<Polinom> polinomi;
    ucitaj_polinome( polinomi, datoteka1 );
//  PrintVektor< std::vector<Polinom> >( polinomi, true );
    datoteka1.close();


    std::vector<Prskotina> naprsline;
    Polinom Poslednji = polinomi.at( polinomi.size() - 1 );
    ucitaj_tacke( Poslednji, naprsline, datoteka2, izbrojano_u_redu );
//    PrintVektor< std::vector<Prskotina> >( naprsline, true );
    datoteka2.close();


    std::vector<Talas> talasi;
    for( int i = 0 ; i < naprsline.size() ; i++ )
    {

        double suma_korektivnog = 0.0;
        for( int j = 0 ; j < naprsline.at(i).vrednost_korektivnog.size() ; j++ )
        {
            suma_korektivnog += naprsline.at(i).vrednost_korektivnog.at(j);
        }

        std::cout << "Suma kor: " << suma_korektivnog << std::endl;

        if( suma_korektivnog <= 1.0 )
        {
            talasi.emplace_back( polinomi, naprsline.at(i).tacke );
            //talasi.back().PrintTalas( true );
        }
    }

    PrintVektor< std::vector <Talas>>(talasi, 1);

    std::vector<Polinom>().swap( polinomi );
    std::vector<Prskotina>().swap( naprsline );
    std::vector<Talas>().swap( talasi );

    return 0;
}
