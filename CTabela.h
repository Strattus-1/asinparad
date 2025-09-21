#include <iostream>

class Tabla
{
public:
    int Ploca[11][11] = {
                         {  0,  0,  0,  0,  5,  5,  5,  0,  0,  0,  0  },
                         {  0,  0,  0,  0,  5,  1,  5,  0,  0,  0,  0  },
                         {  0,  0,  0,  0,  5,  1,  5,  0,  0,  0,  0  },
                         {  0,  0,  0,  0,  5,  1,  5,  0,  0,  0,  0  },
                         {  5,  5,  5,  5,  5,  1,  5,  5,  5,  5,  5  },
                         {  5,  4,  4,  4,  4,  0,  2,  2,  2,  2,  5  },
                         {  5,  5,  5,  5,  5,  3,  5,  5,  5,  5,  5  },
                         {  0,  0,  0,  0,  5,  3,  5,  0,  0,  0,  0  },
                         {  0,  0,  0,  0,  5,  3,  5,  0,  0,  0,  0  },
                         {  0,  0,  0,  0,  5,  3,  5,  0,  0,  0,  0  },
                         {  0,  0,  0,  0,  5,  5,  5,  0,  0,  0,  0  }
                        };

    int Put[40][2]    = {
                         { 0, 5}, { 0, 6}, { 1, 6}, { 2, 6}, { 3, 6}, { 4, 6}, { 4, 7}, { 4, 8}, { 4, 9}, { 4,10},
                         { 5,10}, { 6,10}, { 6, 9}, { 6, 8}, { 6, 7}, { 6, 6}, { 7, 6}, { 8, 6}, { 9, 6}, {10, 6},
                         {10, 5}, {10, 4}, { 9, 4}, { 8, 4}, { 7, 4}, { 6, 4}, { 6, 3}, { 6, 2}, { 6, 1}, { 6, 0},
                         { 5, 0}, { 4, 0}, { 4, 1}, { 4, 2}, { 4, 3}, { 4, 4}, { 3, 4}, { 2, 4}, { 1, 4}, { 0, 4}
                        };

    int ZetoniIPut[40] = {0};

    int Zetoni1[4][2]  = { {1,5}, {2,5}, {3,5}, {4,5} };
    int Zetoni2[4][2]  = { {5,9}, {5,8}, {5,7}, {5,6} };
    int Zetoni3[4][2]  = { {9,5}, {8,5}, {7,5}, {6,5} };
    int Zetoni4[4][2]  = { {5,1}, {5,2}, {5,3}, {5,4} };

    char Znakovi[6]   = { '.','C', 'B', 'Z', 'P', 'O' };

public:
    Tabla(){};
    ~Tabla(){};

    void PostaviZetone();
    void PrintTabla( bool );
};

void Tabla::PostaviZetone()
{
    for( int i = 0 ; i < 40 ; i++ )         // ceo put se obrise
    {
        int i_Put = *( *( Put + i ) + 0 );
        int j_Put = *( *( Put + i ) + 1 );
        *( *( Ploca + i_Put ) + j_Put ) = 5;
    };

    for( int i = 0 ; i < 40 ; i++ )         // i postavi ponovo...
    {
        int i_Put = *( *( Put + i ) + 0 );
        int j_Put = *( *( Put + i ) + 1 );
        int sadrzaj = *( ZetoniIPut + i );
        *( *( Ploca + i_Put ) + j_Put ) = ( !sadrzaj ) ? 5 : sadrzaj;
    };
};

void Tabla::PrintTabla( bool ind )
{
    PostaviZetone();

    for( int i = 0 ; i < 11 ; i++ )
    {
        for( int j = 0 ; j < 11 ; j++ )
        {
            int sadrzaj = *( *( Ploca + i ) + j );
            std::cout << " " << *( Znakovi + sadrzaj ) << " ";
        };

        std::cout << std::endl;
    };

    if( ind ) std::cout << std::endl;
};
