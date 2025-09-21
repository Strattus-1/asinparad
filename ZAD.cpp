#include <iostream>

#include "CIgra.h"
#include "fun.h"

int main( int argc, char** argv )
{
    Igra I;

    I.PrintTabla( true );

    int red[4] = {0}, kockica[4] = {0};
    bool indikator = !std::cin.eof() && citac( red, kockica );
    while( indikator )
    {
        I.KrugBacanjaKockice( red, kockica );
        I.PrintTabla( true );

        indikator = !std::cin.eof() && citac( red, kockica );
    };

    return 0;
}
