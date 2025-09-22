#include<iostream>

#include "CMatrica.h"

int main( int argv, char **argc){

    int n1, n2;
    double a1,a2;

    std::cin >> n1 >> a1 >> n2 >> a2;

    Matrica a(n1, a1), b(n2, a2);

    Matrica c = a + b;
    Matrica d = a * b;

    a.printMatrica( 1 );
    b.printMatrica( 1 );

    std::cout << std::endl;

    c.printMatrica( 1 );
    d.printMatrica( 1 );

    return 0;

};