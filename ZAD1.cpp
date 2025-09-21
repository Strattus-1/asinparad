#include <iostream>

#include "CZPojava.h"

int main( int argc, char** argv )
{
    ZPojava Pojava;

    char znak;

    bool indikator = !std::cin.eof() && std::cin >> znak;
    while( indikator )
    {
        if( znak != '\n' && ( znak > '9' || znak < '0' ) ) Pojava.PostaviDodaj( znak );

        indikator = !std::cin.eof() && std::cin >> znak;
    };

    Pojava.Print( false );

    return 0;
}
