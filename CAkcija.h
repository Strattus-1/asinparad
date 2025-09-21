#include <iostream>

#include "fun1.h"
#include "CKontrola.h"

class Akcija : public Kontrola
{
    public:
        bool PL, PD, ZL, ZD;
        Kontrola A;

    public:
        Akcija( bool *, POZ * );
        ~Akcija(){};

        void Print( bool );
};

Akcija::Akcija( bool *pniz, POZ *niz ) : A( niz )
{
    PL = *( pniz + 0 );
    PD = *( pniz + 1 );
    ZL = *( pniz + 2 );
    ZD = *( pniz + 3 );
};

void Akcija::Print( bool ind )
{
    A.Print( false );
    std::cout << "-> " << PL << PD << ZL << ZD;
    if( ind ) std::cout << std::endl;
};
