#include <iostream>

#include "CKZnak.h"

class ZPojava : virtual KZnak
{
public:
    bool pojava[127] = { false };
    KZnak niz[127];

public:
    ZPojava(){};
    ~ZPojava(){};

    void PostaviDodaj( char );
    void Print( bool );
};

void ZPojava::PostaviDodaj( char znak )
{
    if( *( pojava + znak ) )
    {
        ( niz + znak )->ucestanost++;
    }
    else
    {
        *( pojava + znak ) = true;
        ( niz + znak )->simbol = znak;
        ( niz + znak )->ucestanost = 1;
    };
};

void ZPojava::Print( bool ind )
{
    for( int i = 0 ; i < 127 ; i++ )
    {
        if( *( pojava + i ) ) ( niz + i )->Print( true );
    };
    if( ind ) std::cout <<std::endl;
};
