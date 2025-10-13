#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "CKugla.h"
#include "otvarac.h"
#include "fun.h"

int main( int argc, char **argv )
{
    std::fstream init = otvarac( *( argv + 1 ), "in" );
    int D, R, X, Q;
    init >> D >> R >> X >> Q;
    init.close();

    std::fstream datoteka1 = otvarac( *( argv + 2 ), "in" );
    std::vector<Polinom> niz;
    ucitaj_polinome( datoteka1, D, R, niz );
    datoteka1.close();

    Polinomi sviPolinomi( niz );

    std::fstream datoteka2 = otvarac( *( argv + 3 ), "in" );
    std::vector<Racun> Tacke;
    ucitaj_x_ove( datoteka2, X, Q, sviPolinomi, Tacke );                
    datoteka2.close();

    Kugla kuglaUnutar( Tacke, true );
    Kugla kuglaSpolja( Tacke, false );

    std::cout << " KUGLA UNUTRA " << std::endl;
    kuglaUnutar.Print( Tacke, true );

    std::cout << " KUGLA SPOLJA " << std::endl;
    kuglaSpolja.Print( Tacke, true );

    std::vector<Polinom>().swap( niz );
    std::vector<Racun>().swap( Tacke );

    return 0;
}
