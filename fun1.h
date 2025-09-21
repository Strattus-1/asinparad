#include <iostream>

typedef unsigned short int POZ;

bool MaliPrelepiCitac( POZ *niz, int u_jednom_redu )
{
    bool indikator = true;
	for( POZ i = 0 ; i < u_jednom_redu ; i++ )
    {
		indikator = indikator && std::cin >> *( niz + i );
    };

    return indikator;
};
