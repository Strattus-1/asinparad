#include <iostream>
#include <vector>

class Polinom
{
    public:
        std::vector<double> koeficijenti;
        int stepen;

    public:
        Polinom(){};
        Polinom( std::vector<double> );

       ~Polinom(){};

       void Print( bool );
};

Polinom::Polinom( std::vector<double> v ) : koeficijenti( v )
{
    stepen = koeficijenti.size() - 1;
};

void Polinom::Print( bool ind )
{
    std::cout << "(" << stepen << ")" << std::endl;
    for( int i = 0 ; i <= stepen ; i++ ) std::cout << koeficijenti.at(i) << " ";
    if( ind ) std::cout << std::endl;
};