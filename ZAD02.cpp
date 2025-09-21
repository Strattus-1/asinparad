#include <iostream>
#include <stdlib.h>

#include "CGeneracija.h"

int main( int argc, char** argv )
{
    int n = atoi( *( argv + 1 ) );

    Generacije Generacija_1( n );    // sada postoji virtuelna tabla i objekat prve generacije koji je prikazan
                                     // usledice pravljenje objekata Generacije...
    return 0;
}

