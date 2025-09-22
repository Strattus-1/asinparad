#include<iostream>


class Tabla{

    private:
        int **tabla;
        int dimenzija;
    
    public:
        Tabla( int );
        ~Tabla();

        int getDimenzija();
        int **getTabla();

        void ucitajKoordinate();

        void printTabla( bool );

};

Tabla::Tabla( int n ) : dimenzija ( n ) {

    tabla = ( int** ) calloc( dimenzija, sizeof( int* ) );
    
    for( int i = 0; i < dimenzija; i++ ){
        *( tabla + i ) = ( int* ) calloc( dimenzija, sizeof( int ));
    };


};

Tabla::~Tabla(){

    for( int i = 0; i < dimenzija; i++ ){
        free( *(tabla + i ) );
    };

    free ( tabla );

};

int Tabla::getDimenzija(){
    return dimenzija;
};

int** Tabla::getTabla(){
    return tabla;
};

void Tabla::ucitajKoordinate(){
    int vrsta, kolona;

    bool indikator = !std::cin.eof() && std::cin >> vrsta >> kolona;
    while( indikator )
    {

        *( *(tabla + vrsta ) + kolona ) = 1;

        indikator = !std::cin.eof() && std::cin >> vrsta >> kolona;
    };

};

void Tabla::printTabla( bool ind ){

    for( int i = 0 ; i < dimenzija ; i++ )
    {
        for( int j = 0 ; j < dimenzija ; j++ ) std::cout << *( *( tabla + i ) + j ) << " ";
        std::cout << std::endl;
    };
    if( ind ) std::cout << std::endl;

};