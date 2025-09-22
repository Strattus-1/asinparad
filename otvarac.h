#include<iostream>

#include"CSignal.h"

bool otvarac( int *niz ){

    bool ind = true;

    for( int i = 0; i < 4; i++ )

        ind = ind && (std::cin >> *( niz + i ));

    return ind; 

};

int maximum( int *niz ){
    int max = *( niz + 0 );

    for( int i = 0; i < 4; i++)
        if( *( niz + i ) >= max )
            max = *( niz + i );

        return max;
};



bool* dvaesposto( int *niz ){

    bool *biz = ( bool * ) malloc ( 4 *  (sizeof( bool )));

    int m = maximum ( niz );
    int miki = m * 0.8;

    for( int i = 0; i < 4 ; i++ ){

        if( *( niz + i) < miki )

            *( biz + i ) = 0;

        else
            *( biz + i ) = 1;


    };

    return biz;

};
