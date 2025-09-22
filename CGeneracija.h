#include<iostream>

#include "CTabla.h"
#include "fun.h"

class Generacija : virtual Tabla {

    private:
        int brojGeneracije;
        int brojZivih;

    public:

        Generacija( int );
        ~Generacija(){};

        int getBrojGeneracije();
        int getBrojZivih();

        int brojSuseda( Tabla& , int, int );
        void evoluiraj( Tabla &);


};

Generacija::Generacija( int broj ) : brojGeneracije( broj ), brojZivih( 0 ), Tabla( broj ){};

int Generacija::getBrojGeneracije(){
    return brojGeneracije;
};

int Generacija::getBrojZivih(){
    return brojZivih;
};

int Generacija::brojSuseda( Tabla &tabla, int x, int y ){

    int br = 0;
    int dim = tabla.getDimenzija();
    int **matrica = tabla.getTabla();

    int nx, ny ;

    for( int i = -1; i <= 1; i++ ){
        for( int j = -1; j <= 1; j++){
            if( i == 0 || j == 0 ) continue;
                nx = x + i;
                ny = y + j;

                if( nx >= 0 && nx < dim && ny >= 0 && ny < dim ){
                    br += *( *( matrica + nx ) + ny );
                }
        };
    };

    return br;

};

void Generacija::evoluiraj( Tabla &tabla ){

    int dim = tabla.getDimenzija();
    int **matrica = tabla.getTabla();

    int **temp = ( int ** ) calloc( dim, sizeof( int * ) );

    for( int i = 0; i < dim; i++ ){
        *( temp + i ) = ( int * ) calloc ( dim, sizeof( int ) );
    };

    brojZivih = 0;

    for( int i = 0; i < dim; i++ ){
        for( int j = 0; j < dim; j++ ){
            int sused = brojSuseda( tabla , i , j );
            if( *( *( matrica + i) + j) == 1 ){
                if( sused < 2 || sused > 3 ) 
                    *( *( temp + i) + j ) = 0;
                else
                    *( *( temp + i) + j ) = 1;
            } else {
                if( sused == 3 )
                    *( *( temp + i) + j ) = 1;
                else
                    *( *( temp + i) + j ) = 0;
            }
            if( *( *( temp + i) + j ) == 1 ) 
                brojZivih++;
        };
    };

    for( int i = 0; i < dim; i++ ){
        for( int j = 0; j < dim; j++){
             *( *( matrica + i) + j ) = *( (* temp + i) + j );
        };
        free ( *( temp + i ) );
    };

    free( temp );


};