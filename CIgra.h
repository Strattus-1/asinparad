#include <iostream>

#include "CZeton.h"

class Igra : public Zeton, public virtual Tabla
{
public:
    Zeton CZetoni[4], BZetoni[4], ZZetoni[4], PZetoni[4];

public:
    Igra();
    ~Igra(){}

    void KrugBacanjaKockice( int *, int * );
    void PostaviGaNaPut( int * );
    void UkloniGaSaPut( int * );
    void UkloniGaIzKucice( int * );
};

Igra::Igra()
{
    for( int i = 0 ; i < 4 ; i++ ) ( CZetoni + i )->Boja = 1;
    for( int i = 0 ; i < 4 ; i++ ) ( BZetoni + i )->Boja = 2;
    for( int i = 0 ; i < 4 ; i++ ) ( ZZetoni + i )->Boja = 3;
    for( int i = 0 ; i < 4 ; i++ ) ( PZetoni + i )->Boja = 4;
};

void Igra::KrugBacanjaKockice( int *red, int *kockica )
{
    UkloniGaSaPut( red );

    ( CZetoni + *( red + 0 ) - 1 )->PostaviPozicija( *( kockica + 0 ) );
    ( BZetoni + *( red + 1 ) - 1 )->PostaviPozicija( *( kockica + 1 ) );
    ( ZZetoni + *( red + 2 ) - 1 )->PostaviPozicija( *( kockica + 2 ) );
    ( PZetoni + *( red + 3 ) - 1 )->PostaviPozicija( *( kockica + 3 ) );

    UkloniGaIzKucice( red );
    PostaviGaNaPut( red );
};

void Igra::UkloniGaSaPut( int *red )
{
    *( ZetoniIPut +  0 + CZetoni[red[0]-1].Pozicija - 1 ) = 0;  // orginal kako izgleda -1 da se dobro pozicionira u nizu
    *( ZetoniIPut + 10 + BZetoni[red[1]-1].Pozicija - 1 ) = 0;  // 0 , 10, 20, 30 pomeraj u nizu
    *( ZetoniIPut + 20 + ZZetoni[red[2]-1].Pozicija - 1 ) = 0;  // ? kongruencija jer niz je cikličan
    *( ZetoniIPut + 30 + PZetoni[red[3]-1].Pozicija - 1 ) = 0;
};

void Igra::PostaviGaNaPut( int *red )
{
    *( ZetoniIPut +  0 + ( CZetoni + *( red + 0 ) - 1 )->Pozicija - 1 ) = ( CZetoni + *( red + 0 ) - 1 )->Boja;
    *( ZetoniIPut + 10 + ( BZetoni + *( red + 1 ) - 1 )->Pozicija - 1 ) = ( BZetoni + *( red + 1 ) - 1 )->Boja;
    *( ZetoniIPut + 20 + ( ZZetoni + *( red + 2 ) - 1 )->Pozicija - 1 ) = ( ZZetoni + *( red + 2 ) - 1 )->Boja;
    *( ZetoniIPut + 30 + ( PZetoni + *( red + 3 ) - 1 )->Pozicija - 1 ) = ( PZetoni + *( red + 3 ) - 1 )->Boja;
};

void Igra::UkloniGaIzKucice( int *red )
{
    *( *( Ploca + *( *( Zetoni1 + *( red + 0 ) - 1 ) + 0 ) ) + *( *( Zetoni1 + *( red + 0 ) - 1 ) + 1 ) ) = 0;
    *( *( Ploca + *( *( Zetoni2 + *( red + 1 ) - 1 ) + 0 ) ) + *( *( Zetoni2 + *( red + 1 ) - 1 ) + 1 ) ) = 0;
    *( *( Ploca + *( *( Zetoni3 + *( red + 2 ) - 1 ) + 0 ) ) + *( *( Zetoni3 + *( red + 2 ) - 1 ) + 1 ) ) = 0;
    *( *( Ploca + *( *( Zetoni4 + *( red + 3 ) - 1 ) + 0 ) ) + *( *( Zetoni4 + *( red + 3 ) - 1 ) + 1 ) ) = 0;
};
