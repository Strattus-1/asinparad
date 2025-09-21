
#include <iostream>

#include "fun1.h"
#include "fun.h"
#include "CAkcija.h"

int main( int argc, char **argv )
{
    POZ niz[4] = {0};
    bool *pniz, ne_postoji_blokiran_tocak;

    bool indikator = !std::cin.eof() && Citac( niz );
    while( indikator )
    {
        pniz = mozda_blokira_tocak( niz );
        ne_postoji_blokiran_tocak = true;
        for( POZ i = 0 ; i < 4 ; i++ ) ne_postoji_blokiran_tocak = ne_postoji_blokiran_tocak && *( pniz + i );

        if( !ne_postoji_blokiran_tocak )
        {
            Akcija A( pniz, niz );                   // moze to bolje, mnogo bolje
            A.Print( 1 );
        };

        indikator = !std::cin.eof() && Citac( niz );
    };

    return 0;
}
