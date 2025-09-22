#include<iostream>

#include<vector>
#include<cmath> 

class Polinom{

    public:
        int stepen;
        std::vector<double> koeficijenti = { 0 };

    public:
        
        Polinom( std::vector<double> v, int s  ): koeficijenti(v), stepen( s - 1 ) {};

        ~Polinom(){};

        double vrednost( double );

        void PrintPolinom( bool );

};

double Polinom::vrednost( double d ){

    double rez = 0.0;
    for( int i = 0; i <= stepen; i++ ){
        rez += koeficijenti[ i ] * pow( d, i);
    };

    return rez;

};

void Polinom::PrintPolinom( bool ind ){
    for( int i = 0; i <= stepen; i++){
        std::cout << koeficijenti.at( i ) << ", ";
    };
    if( ind )std::cout << std::endl;
};