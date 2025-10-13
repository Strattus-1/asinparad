#include <iostream>
#include <vector>
#include "CPolinom.h"

class Polinomi 
{
    public:
        std::vector<Polinom> niz;

    public:
        Polinomi(){};
        Polinomi(  std::vector<Polinom> & );
       ~Polinomi(){};

        void Print( bool );
};

Polinomi::Polinomi(  std::vector<Polinom> &polinomi ) : niz( polinomi )
{};

void Polinomi::Print( bool ind ) 
{
    for( int i = 0 ; i < niz.size() ; i++ )
    {
        std::cout << "Polinom " << i << ": ";
        niz[i].Print( true );
    }

    if( ind ) std::cout << std::endl;
};


