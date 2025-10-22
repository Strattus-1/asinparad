#include<iostream>
#include<vector>
#include<fstream>

#include"CPolinom.h"
#include"CPolinomi.h"
#include"CRacun.h"
#include"CKugla.h"
#include"fun3.h"

int main( int argc, char** argv ){

    std::fstream ulaz( *( argv + 1) );

    int n, m;
    std::cin >> n >> m;

    std::vector<Polinom> p = ucitajPolinome( ulaz, n, m );

    Polinomi polinomi( p );

    std::vector<Racun> racuni;
    racuni = ucitajRacune( ulaz, polinomi, m );
    ulaz.close();

    Kugla unutar( racuni, true );
    std::cout << "Racuni cije sve koordinate upadaju u jedinicnu kuglu:" << std::endl;
    unutar.Print( racuni, true );

    Kugla van( racuni, false );
    std::cout << "Racuni cije bar jedna koordinata ne upada u jedinicnu kuglu:" << std::endl;
    van.Print( racuni, false );

    std::vector<Polinom>().swap(p);
    std::vector<Racun>().swap(racuni);
    return 0;
};