#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

template< typename T >
void obradi_liniju_u_brojeve( std::istringstream &strujanje_niski, std::vector<T> &v )
{
    T broj;

    while( strujanje_niski >> broj ) v.push_back( broj );     // ?
};

template< typename T >
std::vector<T> napravi_niz( std::string &podniska, std::istringstream &strujanje_niski )
{
    T broj;

    std::stringstream struja_niske( podniska );
    struja_niske >> broj;                                     // ?

    std::vector<T> v = { broj };                              // ?
    obradi_liniju_u_brojeve<T>( strujanje_niski, v );

    return v;
};

template< typename T >
void PrintVektor( T niz, bool ind )
{
    typename T::iterator i, p = niz.begin(), k = niz.end();

    for( i = p ; i != k ; i++ ) i->Print( true );

    if( ind ) std::cout << std::endl;
};
