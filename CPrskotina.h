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

       void Print( bool );
};

Prskotina::Prskotina( Polinom k, std::vector<double> &t ) : korektivni( k ), tacke( t )
{
    int granica_korektivnog = korektivni.stepen_polinoma + 1;
    int broj_tacaka = tacke.size();
    int j;

    double suma;
    for( int i = 0 ; i < broj_tacaka ; i++ )
    {
        vrednost_korektivnog.push_back( 0.0 ); // naucite sami
    };
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
