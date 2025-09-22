#include<iostream>

#include<string>

class Tabla{

    public:
        char polja[11][11];
    
    public:
        Tabla();
        ~Tabla(){};

        void iscrtaj();
        void staviZeton(int , int , char );
        void ocistiPolje(int , int );

        void start();


};

Tabla::Tabla(){

    std::cout << " KONSTRUKTOR TABELE \n";

    for( int i = 0; i < 11; i++){
        for( int j = 0; j < 11; j++){
            polja[i][j] = '.';
           // std::cout << polja[i][j];
        };
      //  std::cout << std::endl;
    };

    polja[1][5] = 'C'; polja[2][5] = 'C'; polja[3][5] = 'C'; polja[4][5] = 'C';        //[1,5], {2,5}. {3,5}, {4,5}
    polja[5][9] = 'B'; polja[5][8] = 'B'; polja[5][7] = 'B'; polja[5][6] = 'B';        //{5,9}, {5,8}, {5,7}, {5,6}
    polja[9][5] = 'Z'; polja[8][5] = 'Z'; polja[7][5] = 'Z'; polja[6][5] = 'Z';        //{9,5}, {8,5}, {7,5}, {6,5}
    polja[5][1] = 'P'; polja[5][2] = 'P'; polja[5][3] = 'P'; polja[5][4] = 'P';        //{5,1}, {5,2}, {5,3}, {5,4}


        for( int i = 0; i < 11; i++){
        for( int j = 0; j < 11; j++){
            std::cout << polja[i][j];
           // std::cout<< std:: endl;
        };
        
        std::cout << std::endl;
    };

};

void Tabla::start(){

    for( int i = 0; i < 11; i++){
        for( int j = 0; j < 11; j++){
            std::cout << '.';
           // std::cout<< std:: endl;
        };
        
        std::cout << std::endl;
    };
}

void Tabla::iscrtaj(){

    for( int i = 0; i < 11; i++){
        for( int j = 0; j < 11; j++){
            std::cout << polja[i][j];
           // std::cout<< std:: endl;
        };
        
        std::cout << std::endl;
    };

};

void Tabla::staviZeton( int x, int y, char oznaka ){

    polja[x][y] = oznaka;

};

void Tabla::ocistiPolje( int x, int y ){

    polja[x][y] = 'O';

};