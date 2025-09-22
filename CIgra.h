#include<iostream>

#include "fun.h"
#include "CTabla.h"

class Igra{

    public:

        Tabla T;

        std::pair<int, int> putanja[ 40 ];

        int pozC, pozB, pozZ, pozP;
    
        public:
            
            Igra();
            ~Igra(){};

            void pocetak();
            void potez( int *);

};

Igra::Igra() {

/*
    int idx = 0;
    for ( int j = 1; j <= 9; j++ ) putanja[ idx++ ] = { 1, j };   
    for ( int i = 2; i <= 9; i++ ) putanja[ idx++ ] = { i, 9 };   
    for ( int j = 8; j >= 1; j-- ) putanja[ idx++ ] = { 9, j };   
    for ( int i = 8; i >= 2; i-- ) putanja[ idx++ ] = { i, 1 };
*/


/*  
     // GORE ↓ (od gornjeg centra naniže)
putanja[0]  = {1,5};   // start C
putanja[1]  = {2,5};
putanja[2]  = {3,5};
putanja[3]  = {4,5};
putanja[4]  = {5,5};   // centar

// DESNO → (od centra nadesno)
putanja[5]  = {5,6};
putanja[6]  = {5,7};
putanja[7]  = {5,8};
putanja[8]  = {5,9};
putanja[9]  = {5,10};  // start B

// DOLE ↓ (od desnog centra nadole)
putanja[10] = {6,9};
putanja[11] = {7,9};
putanja[12] = {8,9};
putanja[13] = {9,9};
putanja[14] = {10,9};
putanja[15] = {10,8};
putanja[16] = {10,7};
putanja[17] = {10,6};
putanja[18] = {10,5};
putanja[19] = {10,4};  // start Z

// LEVO ← (od donjeg centra nalevo)
putanja[20] = {9,5};
putanja[21] = {8,5};
putanja[22] = {7,5};
putanja[23] = {6,5};
putanja[24] = {5,5};   // opet centar
putanja[25] = {5,4};
putanja[26] = {5,3};
putanja[27] = {5,2};
putanja[28] = {5,1};
putanja[29] = {5,0};   // start P

// GORE ↑ (od levog centra nagore)
putanja[30] = {4,1};
putanja[31] = {3,1};
putanja[32] = {2,1};
putanja[33] = {1,1};
putanja[34] = {0,1};
putanja[35] = {0,2};
putanja[36] = {0,3};
putanja[37] = {0,4};
putanja[38] = {0,5};
putanja[39] = {0,6};   // vraća se gore desno
*/

        std::cout << "KONSTRUTOR IGRE!!! \n";

   std::pair<int, int> tmp[40]  = {
                         { 0, 5}, { 0, 6}, { 1, 6}, { 2, 6}, { 3, 6}, { 4, 6}, { 4, 7}, { 4, 8}, { 4, 9}, { 4,10},
                         { 5,10}, { 6,10}, { 6, 9}, { 6, 8}, { 6, 7}, { 6, 6}, { 7, 6}, { 8, 6}, { 9, 6}, {10, 6},
                         {10, 5}, {10, 4}, { 9, 4}, { 8, 4}, { 7, 4}, { 6, 4}, { 6, 3}, { 6, 2}, { 6, 1}, { 6, 0},
                         { 5, 0}, { 4, 0}, { 4, 1}, { 4, 2}, { 4, 3}, { 4, 4}, { 3, 4}, { 2, 4}, { 1, 4}, { 0, 4}
                        };


    for (int i = 0; i < 40; i++) {
        putanja[i] = tmp[ i ];
    T.staviZeton(putanja[i].first, putanja[i].second, 'O');
};

    pozC = 0;
    pozB = 10;
    pozZ = 20;
    pozP = 30;

    T.staviZeton( putanja[ pozC ].first, putanja[ pozC ].second, 'C');
    T.staviZeton( putanja[ pozB ].first, putanja[ pozB ].second, 'B');
    T.staviZeton( putanja[ pozZ ].first, putanja[ pozZ ].second, 'Z');
    T.staviZeton( putanja[ pozP ].first, putanja[ pozP ].second, 'P');


};

void Igra::pocetak(){

    T.iscrtaj();

};

void Igra::potez( int *bacanja ){

    
    T.ocistiPolje( putanja[ pozC].first , putanja[ pozC ].second);
    pozC = (pozC + bacanja [1] ) % 40;
    T.staviZeton(putanja[ pozC ].first, putanja[ pozC ].second, 'C');


    T.ocistiPolje( putanja[ pozB ].first , putanja[ pozB ].second);
    pozB = (pozB + bacanja[ 3 ] ) % 40;
    T.staviZeton(putanja[ pozB ].first, putanja[ pozB ].second, 'B');

    
    T.ocistiPolje( putanja[ pozZ ].first , putanja[ pozZ ].second);
    pozZ = (pozZ +  bacanja[ 5 ] ) % 40;
    T.staviZeton(putanja[ pozZ ].first, putanja [pozZ ].second, 'Z');


    T.ocistiPolje( putanja[ pozP ].first , putanja[ pozP ].second);
    pozP = (pozP + bacanja[ 7 ] ) % 40;
    T.staviZeton(putanja[ pozP ].first, putanja[ pozP ].second, 'P');


    T.iscrtaj();


};