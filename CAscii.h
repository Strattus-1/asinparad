#include <iostream>
#include <fstream>

class BrojaciAscii
{
    public:
        int lgranica;
        int dgranica;

        long brojaci[26] = {0};
        long brojac      = 0;

    public:
        BrojaciAscii( int, int, std::fstream& );
        ~BrojaciAscii(){};

        void printBrojaciAscii( bool );
        void addToBrojaciAscii( char );
};
void BrojaciAscii::addToBrojaciAscii( char znak )
{
    ( *( brojaci + ( znak - lgranica ) ) )++;     //niz je niz je, nije [] da bi mislio o kontejneru
    brojac++;
};

BrojaciAscii::BrojaciAscii( int lg, int dg, std::fstream &datoteka )
{
    lgranica = lg;
    dgranica = dg;

    char znak;

    bool indikator = datoteka >> znak && !datoteka.eof();

    while( indikator )
    {
        if( lgranica <= znak && znak <= dgranica ) addToBrojaciAscii( znak );

        indikator = datoteka >> znak && !datoteka.eof();
    };
};

void BrojaciAscii::printBrojaciAscii( bool indikator )
{
    for( int i = 0 ; i < 26 ; i++ )
    {
        if ( *( brojaci + i ) )
        {
            std::cout << std::endl << (char)(i + lgranica) << "->" << *( brojaci + i ) ;
        };
    };
    std::cout << std::endl << "( " << brojac << " )";

    if( indikator ) std::cout << std::endl;
};
