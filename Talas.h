class Talas : virtual Polinom
{
    public:
        std::vector<Polinom> polinomi;
        std::vector<double> tacke;
        std::vector<std::vector<double>> vrednost_polinoma;

    public:
        Talas(){};
        Talas( std::vector<Polinom>&, std::vector<double> & );

       ~Talas(){};

       void Print( bool );
};

Talas::Talas( std::vector<Polinom> &p, std::vector<double> &t ) : polinomi( p ), tacke( t )
{
    int granica_polinoma = polinomi.size();
    int broj_tacaka = tacke.size();
    
    double suma = 0.0;
    // suma = suma * x + j; HORNEROVA SHEMA
    for( int k = 0 ; k < granica_polinoma ; k++ ){
        std::vector<double> red;
        int granica = polinomi.at(k).stepen_polinoma + 1;
        for( int i = 0 ; i < broj_tacaka ; i++ ){

            for( int j = 0; j < granica; j++ ){
            suma = suma * tacke.at(i) + polinomi.at(k).koeficijenti.at(j);
        };

        red.push_back( suma );
        };
        vrednost_polinoma.push_back( red );
    };
};

void Talas::Print( bool ind )
{
    int broj_polinoma = vrednost_polinoma.size();
    int broj_tacaka = tacke.size();
    for( int i = 0 ; i < broj_polinoma ; i++ )
        for( int j = 0 ; j < broj_tacaka ; j++ ) std::cout << tacke.at(j) << "->" << vrednost_polinoma.at(i).at(j) << " ";
    if( ind ) std::cout << std::endl;
};
