#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

void ucitaj_polinome( std::vector<Polinom> &polinomi, std::fstream &datoteka )
{
    std::string linija;
    std::string prva_podniska;

    bool indikator = !datoteka.eof() && std::getline( datoteka, linija );
    while ( indikator )
    {
        std::istringstream strujanje_linije( linija );
        strujanje_linije >> prva_podniska;

        std::vector<double> niz = napravi_niz<double>( prva_podniska, strujanje_linije );
        polinomi.emplace_back( niz, niz.size() );

        indikator = !datoteka.eof() && std::getline( datoteka, linija );
    };
};


bool mali_citac( std::fstream &datoteka, std::vector<double> &niz, int izbrojano_u_redu )
{
    bool indikator;
    double broj;

    for( int i = 0 ; i < izbrojano_u_redu ; i++ )
    {
        indikator = datoteka.good() && datoteka >> broj;
        niz.push_back( broj );
    };

    return indikator;
};

void ucitaj_tacke( Polinom &Poslednji, std::vector<Prskotina> &naprsline, std::fstream &datoteka, int izbrojano_u_redu )
{
    std::vector<double>niz;

    bool indikator = !datoteka.eof() && mali_citac( datoteka, niz, izbrojano_u_redu );

    while ( indikator )
    {
        naprsline.emplace_back( Poslednji, niz );

        std::vector<double>().swap( niz );
        indikator = !datoteka.eof() && mali_citac( datoteka, niz, izbrojano_u_redu );
    };
};
