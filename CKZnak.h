#include <iostream>

class KZnak
{
public:
    char simbol;
    int  ucestanost;

public:
    KZnak(){};
    KZnak( char );
    ~KZnak(){};

    void Print( bool );
};

KZnak::KZnak( char znak )
{
    simbol = znak;
    ucestanost = 1;
};

void KZnak::Print( bool ind )
{
    std::cout << simbol << " --> " << ucestanost;
    if( ind ) std::cout <<std::endl;
};
