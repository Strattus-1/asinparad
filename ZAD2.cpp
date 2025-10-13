#include <iostream>
#include <fstream>
#include <vector>

#include "CPolinomi.h"
#include "otvarac.h"
#include "fun.h"

int main( int argc, char** argv )
{
    std::fstream init = otvarac( *( argv + 1 ), "in" );

    int stepen_polinoma;     
    int brojevi_koef_u_redu;     

    init >> stepen_polinoma >> brojevi_koef_u_redu;
    init.close();


    std::fstream datoteka = otvarac( *( argv + 2 ), "in" );
    std::vector<Polinom> polinomi;
    ucitaj_polinome( datoteka, stepen_polinoma, brojevi_koef_u_redu, polinomi );
    datoteka.close();

    Polinomi svi( polinomi );
    svi.Print( true );

    std::vector<Polinom>().swap( polinomi );

    return 0;
}
