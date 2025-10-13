#include <iostream>
#include <vector>
#include <cmath>
#include "CPolinomi.h"

class Racun : virtual Polinomi
{
    public:
        int indeksPolinoma;             // koji polinom se koristi (i % n)
        std::vector<double> x;          // x-koordinate
        std::vector<double> y;          // y-koordinate

    public:
        Racun(){};
        Racun( Polinomi &, int, std::vector<double> & );
        ~Racun(){};

    void Print( bool );
};

Racun::Racun( Polinomi &skup, int indeks, std::vector<double> &vx ) : Polinomi( skup ), indeksPolinoma( indeks ), x( vx )
{
    Polinom &P = niz.at( indeksPolinoma % niz.size() );

    int broj_tacaka = x.size();
    int broj_koef = P.koeficijenti.size();


    for( int i = 0; i < broj_tacaka; i++ )
    {
        double rezultat = P.koeficijenti.at( 0 );
        for( int j = 1; j < broj_koef; j++ )
        {
            rezultat = rezultat * x.at( i ) + P.koeficijenti.at( j );
        };

        y.emplace_back( rezultat );
    };
};

void Racun::Print( bool ind )
{
    std::cout << "polinom (" << indeksPolinoma << "): ";
    for( int i = 0; i < niz[indeksPolinoma].koeficijenti.size(); i++ )
    {
        std::cout << niz[indeksPolinoma].koeficijenti.at( i ) << " ";
    };
    std::cout << std::endl;

    std::cout << "x: ";
    for( int i = 0; i < x.size(); i++ )
    {
        std::cout << x.at( i ) << " ";
    };
    std::cout << std::endl;

    std::cout << "y: ";
    for( int i = 0; i < y.size(); i++ )
    {
        std::cout << y.at( i ) << " ";
    };
    std::cout << std::endl;

    if( ind ) std::cout << std::endl;
};


