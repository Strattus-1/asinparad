#include <iostream>

#include "CPartija.h"

typedef unsigned short int POZ;

class Pobeda : public Partija
{
    public:
        POZ pobeda;
        Partija A;

    public:
        Pobeda( POZ * );
        ~Pobeda(){};

        void printPobeda( bool );
};

Pobeda::Pobeda( POZ *niz ) : A( niz ) // nema ? sledeci put
{
    pobeda = 7;                       // samo da radi i sa ovim je sve gotovo!
};

void Pobeda::printPobeda( bool ind )
{
    A.printPartija( false );
    std::cout << "-> " << pobeda;
    if( ind ) std::cout << std::endl;
};
