#include <iostream>

bool citac( int *red )
{
    for( int i = 0 ; i < 8 ; i++ ) std::cin >> *( red + i );

    return std::cin.good();
};
