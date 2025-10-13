#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>


#include "otvarac.h"
#include "fun.h"
#include "CPolinom.h"
#include "TPolinomi.h"
#include "CRacun.h"
#include "CKugla.h"



int main( int argc, char** argv )
{
    // argv[1] = Init0.dat
    // argv[2] = Ulaz1.dat
    // argv[3] = Ulaz2.dat
    std::fstream datoteka0 = otvarac( *( argv + 1 ), "in" );
    std::fstream datoteka1 = otvarac( *( argv + 2 ), "in" );
    std::fstream datoteka2 = otvarac( *( argv + 3 ), "in" );

    int D, R, X, Q;
    datoteka0 >> D >> R >> X >> Q;
    datoteka0.close();

    std::vector<Polinom> polinomi_v;
    ucitaj_polinome( datoteka1, D, R, polinomi_v );
    datoteka1.close();

    Polinomi kolekcija;
    for( int i = 0; i < polinomi_v.size(); i++ ) kolekcija.Dodaj( polinomi_v.at( i ) );

    std::cout << "Procitani polinomi:" << std::endl;
    PrintVektor< std::vector<Polinom> >( polinomi_v, true );

    std::vector<Racun> Tacke;
    std::vector<double> xs(X);
    bool indikator = !datoteka2.eof() && citac_u_redu<double>(datoteka2, X, Q, xs);

    int i = 0;
    while (indikator)
    {
        Polinom& odabrani = kolekcija.polinomi[i % kolekcija.polinomi.size()];
        Tacke.emplace_back(odabrani, xs, kolekcija);

        indikator = !datoteka2.eof() && citac_u_redu<double>(datoteka2, X, Q, xs);
        i++;
    }
    datoteka2.close();

    std::cout << "\nIzracunati rezultati (Racun):" << std::endl;
    PrintVektor< std::vector<Racun> >( Tacke, true );

    Kugla k( Tacke );
    std::cout << "\nObjekti unutar jedinicne kugle:" << std::endl;
    k.Print( true );

    std::vector<Polinom>().swap( polinomi_v );
    std::vector<Racun>().swap( Tacke );

    return 0;
}