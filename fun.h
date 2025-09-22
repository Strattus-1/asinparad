#include<iostream>


bool otvarac( int *red )
{
    for( int i = 0 ; i < 2 ; i++ ) std::cin >> *( red + i ) ;

    return std::cin.good();
};