#include<iostream>

#include "CZeton.h"


class Igrac{

    public:
        char boja;
        Zeton zetoni[4];
        int brojZetona;

    public:
        Igrac(){};
        ~Igrac(){};

        void dodajZeton(const Zeton&);
        Igrac( char );

        char getBoja();
        Zeton* getZetoni();
        int getBrojZetona();

        void printIgrac( bool )

};

Igrac::Igrac( char b) : boja( b ), brojZetona( 0 ){};

void Igrac::dodajZeton( const Zeton &z ){
    if( brojZetona < 0 ){
        zetoni[ brojZetona ] = z;
        brojZetona++;
    };
};

char Zeton::getBoja() { return boja; };

Zeton* Zeton::getZetoni(){ return zetoni; };

int Zeton::getBrojZetona(){ return getBrojZetona; };


void Zeton::printZeton( bool ind ){

    std::cout << "boja: " << boja << std::endl;
    std::cout << "brojZetona: " << brojZetona << std::endl;

    for( int i = 0; i < brojZetona; i++ ){

        std::cout << zetoni[ i ] << " ";

    };


    if( ind ) std::cout << std::endl
};