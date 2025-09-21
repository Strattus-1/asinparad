#include <iostream>

#include "fun1.h"

class Kontrola
{
    public:
        POZ signali[4] = {0};

    public:
        Kontrola(){};
        Kontrola( POZ * );
        ~Kontrola(){};

        void Print( bool );
};

Kontrola::Kontrola( POZ *niz )
{
    for( POZ i = 0 ; i < 4 ; i++ ) *( signali + i ) = *( niz + i );
};

void Kontrola::Print( bool ind )
{
    for( POZ i = 0 ; i < 4 ; i++ ) std::cout << *( signali + i ) << " ";
    if( ind ) std::cout << std::endl;
};
