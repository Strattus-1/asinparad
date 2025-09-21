#include<iostream>

typedef unsigned short int POZ;

class Partija
{
    public:
        POZ potezi[9] = {0};

    public:
        Partija(){};
        Partija( POZ * );
        ~Partija(){};

        void printPartija( bool );
};

Partija::Partija( POZ *niz )
{
    for( POZ i = 0 ; i < 9 ; i++ ) *( potezi + i ) = *( niz + i );
};

void Partija::printPartija( bool ind )
{
    for( POZ i = 0 ; i < 9 ; i++ ) std::cout << *( potezi + i ) << " ";

    if( ind ) std::cout << std::endl;
};
