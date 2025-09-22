#include<iostream>


class Zeton{

    public:
        int x, y;
        char oznaka;

    public:
        Zeton(){};
        Zeton( int, int, char );
        ~Zeton(){};

        int getX();
        int getY();
        char getOznaka();

        void setPozicija( int, int, char);
        void printZeton( bool );

};

Zeton::Zeton( int x, int y, char oznaka ) : x( x ), y( y ), oznaka( oznaka ) {};

int Zeton::getX(){
  return x;  
};

int Zeton::getY(){
    return y;
};

char Zeton::getOznaka(){
    return oznaka;
};

void Zeton::setPozicija( int x, int y, char oznaka){
    this -> x = x;
    this -> y = y;
    this -> oznaka = oznaka;
};

void Zeton::printZeton( bool ind ){
    std::cout << "(x, y) -> " << x << ", " << y;

    if( bool ) std::cout << std::endl;
};