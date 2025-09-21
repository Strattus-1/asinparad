#include <iostream>

#include "CTabela.h"

class Zeton
{
public:
    int Pozicija = 0;
    int Boja     = 0;

public:
    Zeton(){};
    ~Zeton(){};

    void PostaviPozicija( int );
};

void Zeton::PostaviPozicija( int pomeraj )
{
    Pozicija += pomeraj;
};

