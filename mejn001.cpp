#include<iostream>

#include"CIgra.h"


int main( int argc, char** argv )
{
    Igra I;

    int red[8];

    I.pocetak();


    bool indikator = !std::cin.eof() && citac( red );
    char a = 'R';

    while( indikator )
    {
        I.potez( red );
        std::cout << std::endl << a++ << std::endl;
        indikator = !std::cin.eof() && citac( red );
    };

    std::cout << std::endl;

    return 0;
}

/*

....OOO....
....OCO....
....OCO....
....OCO....
OOOOOCOOOOO
OPPPP.BBBBO
OOOOOZOOOOO
....OZO....
....OZO....
....OZO....
....OOO....

*/