#include <iostream>

#include "CPobeda.h"
#include "fun1.h"

int main( int argc, char **argv )
{
    POZ u_jednom_redu = atoi( *( argv + 1 ) );
    POZ niz[9];

    bool indikator = !std::cin.eof() && MaliPrelepiCitac( niz, u_jednom_redu );
    while( indikator )
    {
        Pobeda prva( niz );

        prva.printPobeda( true );

        indikator = !std::cin.eof() && MaliPrelepiCitac( niz, u_jednom_redu );
    };

    return 0;
}
