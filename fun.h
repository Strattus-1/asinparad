#include <iostream>

bool citac( int *red, int *kockica )
{
    for( int i = 0 ; i < 4 ; i++ ) std::cin >> *( red + i ) >> *( kockica + i );

    return std::cin.good();
};
