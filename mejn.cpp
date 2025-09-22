#include<iostream>

#include"CGeneracija.h"


int main( int argc, char** argv ){


    int n = atoi( *( argv + 1 ) );

    Tabla tabla( n );
    
    tabla.ucitajKoordinate();

    std::cout << "Pocetna generacija:\n";
    tabla.printTabla( 1 );

    for (int i = 1; i <= 5; i++) {
        Generacija g(i);
        g.evoluiraj(tabla);
        std::cout << "Generacija " << g.getBrojGeneracije()
             << " (zivih: " << g.getBrojZivih() << "):\n";
        tabla.printTabla( 1 );
    }


    return 0;

};