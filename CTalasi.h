
class Talas : virtual public Prskotina
{
    public:
        std::vector<std::vector<double>> vrednosti_ostalih_polinoma;

    public:
        Talas(){};
        Talas( std::vector<Polinom> polinomi, std::vector<double> t );
       ~Talas(){};

       void PrintTalas( bool ind );
};

Talas::Talas(std::vector<Polinom> polinomi, std::vector<double> t ) : Prskotina( polinomi.back(), t ){

    int broj_polinoma = polinomi.size();
    int broj_tacaka = t.size();


    for( int i = 0 ; i < broj_polinoma - 1 ; i++ )
    {
        Polinom trenutni_polinom = polinomi.at(i);
        std::vector<double> vrednosti_trenutnog_polinoma;

        for( int j = 0 ; j < broj_tacaka ; j++ )
        {
            double tacka = t.at(j);
            double vrednost = 0.0;

            for( int k = trenutni_polinom.stepen_polinoma; k >= 0 ; k-- ) vrednost = vrednost * tacka + trenutni_polinom.koeficijenti.at(k);

            vrednosti_trenutnog_polinoma.push_back( vrednost );
        };

        vrednosti_ostalih_polinoma.push_back( vrednosti_trenutnog_polinoma );
    }
};

void Talas::PrintTalas( bool ind )
{
    int broj_polinoma = vrednosti_ostalih_polinoma.size();
    int broj_tacaka = tacke.size();

    for( int i = 0 ; i < broj_polinoma ; i++ )
        for( int j = 0 ; j < broj_tacaka ; j++ ) std::cout << tacke.at(j) << "->" << vrednosti_ostalih_polinoma.at(i).at(j) << " ";

    if( ind ) std::cout << std::endl;
};
