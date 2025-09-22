#include<iostream>

#include"CKocenje.h"


int main( int argv, char** argc ){

     int niz[4] = { 0 };

    bool *bniz, stampajbate;

    bool indikator = !std::cin.eof() && otvarac( niz );

    while( indikator ){

        bniz = dvaesposto( niz );

        stampajbate = 1;

        for( int i =0; i < 4; i++ ){

            stampajbate = stampajbate && *( bniz + i );

        };

        if( !stampajbate ){
            Kocenje K( bniz, niz );
            K.printKocenje( 1 );
        };

        indikator = !std::cin.eof() && otvarac( niz );
    };

    return 0;

};