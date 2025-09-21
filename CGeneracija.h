#include <iostream>

#include "CTabla.h"

class Generacije : virtual TablaZivota
{
public:
    int   dim_pre      = 0;
    int** zivot_pre    = NULL;
    int   dim_posle    = 0;
    int** zivot_posle  = NULL;

public:
    Generacije( int );
    ~Generacije();

    void NovaGeneracija();   //pravi novu generaciju puneci zivot_posle kompletira se objekat Generacije
};

Generacije::~Generacije()
{
    for( int i = 0 ; i < dim_pre ; i++ ) free( *( zivot_pre + i ) );
    free( zivot_pre );

    for( int i = 0 ; i < dim_posle ; i++ ) free( *( zivot_posle + i ) );
    free( zivot_posle );
};

Generacije::Generacije( int n ) : TablaZivota( n )
{
    int vrsta, kolona, dim = 0;
    int *koordinate;

    bool indikator = !std::cin.eof() && std::cin >> vrsta >> kolona;
    while( indikator )
    {
        koordinate = ( int* ) malloc( 2 * sizeof( int ) );
        //
        *( koordinate + 0 ) = vrsta;
        *( koordinate + 1 ) = kolona;

        zivot_pre = ( int ** )realloc( zivot_pre, sizeof( koordinate ) * ( dim_pre + 1 ) );

        *( zivot_pre + dim_pre++ ) = koordinate;

        indikator = !std::cin.eof() && std::cin >> vrsta >> kolona;
    };

    TablaZivota::PrimiZivot( zivot_pre, dim_pre );       // tabla prihvati pocetni zivot i
    TablaZivota::Print( true );                          // prikaze ga

    NovaGeneracija();                                    // kompletira se prvi objekat Generacije ! puni zivot_posle
    TablaZivota::MrtvaTabla();                           // cisti se tabla

    TablaZivota::PrimiZivot( zivot_posle, dim_posle );   // tabla prihvati novi zivot i
    TablaZivota::Print( true );                          // prikaze ga
};

void Generacije::NovaGeneracija()                           // bilo kakva promena, ali ovde je ispostovan zivot i nastanak novog zivota
{
    int *celija;

    for( int i = 1 ; i < dimenzija_table - 1 ; i++ )
    {
        for( int j = 1 ; j < dimenzija_table - 1 ; j++ )    // ispitujemo tablu bez ivica
        {
            int stanje = 0;                                 //
            for( int k = -1 ; k < 2 ; k++ )                 //
            {                                               //       ( i - 1, j + k=-1 ) ( i - 1, j + k=0 ) ( i - 1, j + k=1 )
                stanje += *( *( tabla + i - 1 ) + j + k );  //       ( i    , j - 1    ) ( i    , j       ) ( i    , j + 1   )
                stanje += *( *( tabla + i + 1 ) + j + k );  //       ( i + 1, j + k=-1 ) ( i + 1, j + k=0 ) ( i + 1, j + k=1 )
            };                                              //
            stanje += *( *( tabla + i ) + j - 1 );          //
            stanje += *( *( tabla + i ) + j + 1 );          //

            if(
                ( *( *( tabla + i ) + j ) && ( stanje == 2 || stanje == 3 ) ) || // polje je zivo i ima 2 ili 3 suseda ostaje zivo
                ( !( *( *( tabla + i ) + j ) ) && stanje == 3 )                  // mrtvo je ali ima tri suseda bice zivo
              )
            {
                std::cout << *( *( tabla + i ) + j ) << "-> (" << i << "," << j << ") " << stanje << std::endl;  // kontrola
                celija = ( int* ) malloc( 2 * sizeof( int ) );
                //
                *( celija + 0 ) = i;
                *( celija + 1 ) = j;
                zivot_posle = ( int ** ) realloc( zivot_posle, sizeof( celija ) * ( dim_posle + 1 ) );
                //
                *( zivot_posle + dim_posle++ ) = celija;
            };
        };
    };
};
