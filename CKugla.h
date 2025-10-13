#include <iostream>
#include <vector>
#include "CRacun.h"

class Kugla 
{
    public:
        std::vector<int> tacke;  

    public:
        Kugla(){};
        Kugla( std::vector<Racun> &, bool );
        ~Kugla(){};

    void Print( std::vector<Racun> &, bool );
};

Kugla::Kugla( std::vector<Racun> &ulaz, bool unutar )
{
    for( int i = 0; i < ulaz.size(); i++ )
    {
        double suma = 0.0;
        for( int j = 0; j < ulaz[i].x.size(); j++ )
        {
            suma += ulaz[i].x[j]*ulaz[i].x[j] + ulaz[i].y[j]*ulaz[i].y[j];
        };

        if( ( unutar && suma <= 1.0 ) || ( !unutar && suma > 1.0 ) )
        {
            tacke.emplace_back( i );
        };
    };
};

void Kugla::Print( std::vector<Racun> &svi, bool ind )
{
    for( int i = 0; i < tacke.size(); i++ )
    {
        std::cout << "Racun " << tacke[i]+1 << ":" << std::endl;
        svi[tacke[i]].Print( true );
    };

    if(ind) std::cout << std::endl;
};




