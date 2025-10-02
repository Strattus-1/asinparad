class Prskotina : virtual Polinom
{
    public:
        Polinom korektivni;
        std::vector<double> tacke;
        std::vector<double> vrednost_korektivnog;

    public:
        Prskotina(){};
        Prskotina( Polinom, std::vector<double> & );

       ~Prskotina(){};

       double SumaKorektivnog();
       void Print( bool );
};

Prskotina::Prskotina( Polinom k, std::vector<double> &t ) : korektivni( k ), tacke( t )
{
    int granica_korektivnog = korektivni.stepen_polinoma + 1;
    int broj_tacaka = tacke.size();
    int j;

    double suma = 0.0;
    // suma = suma * vrednost + i; HORNEROVA SHEMA

    for( int i = 0 ; i < broj_tacaka ; i++ ){

        for( j = 0; j < granica_korektivnog; j++ ){
        suma = suma * tacke.at(i) + korektivni.koeficijenti.at(j);
        };

        vrednost_korektivnog.push_back( suma );
    };
};

double Prskotina::SumaKorektivnog()
{
    double suma = 0.0;
    int granica = vrednost_korektivnog.size();

    for( int i = 0 ; i < granica ; i++ ) suma += vrednost_korektivnog.at(i);

    return suma;
};

void Prskotina::Print( bool ind )
{
    int broj_tacaka = tacke.size();

    for( int i = 0 ; i < broj_tacaka ; i++ )
    {
        std::cout << tacke.at(i) << "->" << " " << vrednost_korektivnog.at(i) << " ";
    };
    if( ind ) std::cout << std::endl;
};