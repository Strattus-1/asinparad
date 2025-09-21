#include <iostream>
#include <fstream>

#include "fun.h"
#include "CAscii.h"

int main( int argc, char **argv )
{
    std::fstream ulaz = otvarac( *( argv + 1 ), std::fstream::in );  // nije mesto u mojoj klasi, ili je global ili parametar

    BrojaciAscii mala( 'a', 'z', ulaz );                             // umetnost

    mala.printBrojaciAscii( 1 );

    ulaz.close();

    return 0;
};
