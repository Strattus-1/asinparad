#include<iostream>

//#include"CSignal.h"
#include"otvarac.h"

class Kocenje : public Tocak{

    public:
        bool P1, P2, Z1, Z2;
        Tocak T;
    
    public:

        Kocenje(){};
        ~Kocenje(){};

        Kocenje( bool *, int* );
        void printKocenje( bool );

};

Kocenje::Kocenje(bool *bniz, int *niz) : T( niz ){

    P1 = *( bniz + 0 );
    P2 = *( bniz + 1 );
    Z1 = *( bniz + 2 );
    Z2 = *( bniz + 3 );

};

void Kocenje::printKocenje( bool ind ){

    T.printTocak( 0 );

    std::cout << " == " << P1 << P2 << Z1 << Z2;

    if( ind ) std::cout << std::endl;
 
};