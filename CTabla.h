#include <iostream>

class TablaZivota
{
public:
    int   dimenzija_table = 0;
    int** tabla = NULL;

public:
    TablaZivota( int );
    ~TablaZivota();

    void MrtvaTabla();
    void PrimiZivot( int**, int );

    void Print( bool );
};

void TablaZivota::PrimiZivot( int** zivot, int dim )
{
    for( int i = 0 ; i < dim ; i++ )
    {
        int vrsta  = *( *( zivot + i ) + 0 );
        int kolona = *( *( zivot + i ) + 1 );
        *( *( tabla + vrsta ) + kolona ) = 1;
    };
};

void TablaZivota::MrtvaTabla()
{
    for( int i = 0 ; i < dimenzija_table ; i++ )
    {
        for( int j = 0 ; j < dimenzija_table ; j++ ) *( *( tabla + i ) + j ) = 0;

    };
};

TablaZivota::~TablaZivota()
{
    for( int i = 0 ; i < dimenzija_table ; i++ ) free( *( tabla + i ) );
    free( tabla );
};

TablaZivota::TablaZivota( int dim )
{
    dimenzija_table = dim;
    int*  celije = ( int*  )calloc( dimenzija_table, sizeof( int ) );
    tabla = ( int** )malloc( dimenzija_table * sizeof( celije ) );

    for( int i = 0 ; i < dimenzija_table ; i++ )
    {
        celije = ( int* )calloc( dimenzija_table, sizeof( int ) );
        *( tabla + i ) = celije;
    };
};

void TablaZivota::Print( bool ind )
{
    for( int i = 0 ; i < dimenzija_table ; i++ )
    {
        for( int j = 0 ; j < dimenzija_table ; j++ ) std::cout << *( *( tabla + i ) + j ) << " ";
        std::cout << std::endl;
    };
    if( ind ) std::cout << std::endl;
};


