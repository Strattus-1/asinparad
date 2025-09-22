#include<iostream>

class Matrica{

    private:
        int n;
        double a;
    
    public: 
        Matrica(){};
        Matrica(int, double);
        void setMatrica(int, double);
        ~Matrica(){};


        const Matrica & operator= (const Matrica &);
        Matrica operator +( Matrica );
        Matrica operator *( Matrica );

        void printMatrica( bool );

};

Matrica::Matrica(int n, double a){

    this -> n = n;
    this -> a = a;

};

void Matrica::setMatrica( int n, double a){

    this -> n = n;
    this -> a = a;

};

const Matrica& Matrica::operator =( const Matrica &mat ){

    if( &mat == this ) return *this;

    n = mat.n;
    a = mat.a;
    
    return *this;

};

Matrica Matrica::operator +( Matrica mat ){

    Matrica temp;

    temp.n = n;
    temp.a = a + mat.a;

    return temp;

};

Matrica Matrica::operator *( Matrica mat ){

    Matrica temp;

    temp.n = n;
    temp.a = a * mat.a * n;

    return temp;

};

void Matrica::printMatrica( bool ind ){

    std::cout << "(" << n << ", " << a << ")";
    if( ind ) std::cout << std::endl;

};