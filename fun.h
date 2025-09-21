#include <iostream>

#include "fun1.h"

bool Citac( POZ *niz )
{
    bool indikator = true;

	for( POZ i = 0 ; i < 4 ; i++ ) indikator = indikator && std::cin >> *( niz + i );

    return indikator;
};

POZ najveci( POZ *niz )
{
    POZ max = *( niz + 0 );

    for( POZ i = 1 ; i < 4 ; i++ ) if( *( niz + i ) > max ) max = *( niz + i ) ;

    return max;
};

bool *mozda_blokira_tocak( POZ *niz )
{
    bool *nadjeno = ( bool * )malloc( 4 * sizeof( bool ) );
    POZ max_g = najveci( niz );
    POZ max_d = max_g - max_g * 0.2;

    for( POZ i = 0 ; i < 4 ; i++ ) *( nadjeno + i ) = max_d <= *( niz + i ) && *( niz + i ) <= max_g;

    return nadjeno;
};
