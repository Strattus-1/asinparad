class Polinom;
class Racun;
class Polinomi;

template < typename T >
void PrintVektorP( T v, bool ind )
{
	typename T::iterator i, p = v.begin(), k = v.end();

    for( i = p ; i != k; i++ ) i->Print( true );
    if( ind ) std::cout << std::endl;
};

template< typename T >
void PrintVektor( T niz, bool ind )
{
    typename T::iterator i, p = niz.begin(), k = niz.end();

    for( i = p ; i != k ; i++ ) i->Print( true );

    if( ind ) std::cout << std::endl;
};
template < typename T >
void PrintVektorBrojeva(std::vector<T> v, bool ind) {
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    if (ind) std::cout << std::endl;
}

template< typename T >
bool citac_u_redu( std::fstream &datoteka, int granica, int brojeva_u_redu, std::vector<T> &niz )
{
    T nepotrebni;
    int preskoci = brojeva_u_redu - granica;

    for( int i = 0 ; i < granica  ; i++ ) datoteka >> niz.at(i);
    for( int i = 0 ; i < preskoci ; i++ ) datoteka >> nepotrebni;

    return datoteka.good();
};

template < typename T >
bool mali_citac(std::fstream &dat1, int D, int R, std::vector<T> &niz)
{
    
    for (int i = 0; i <= D; i++) {
        dat1 >> niz[i];
    }

    
    T nepotrebni;
    for (int j = D + 1; j < R; j++) {
        dat1 >> nepotrebni;
    }
    return dat1.good();
}

void ucitaj_polinome( std::fstream &datoteka, int stepen_polinoma, int brojeva_u_redu, std::vector<Polinom> &niz )
{
    std::vector<double> koeficijenti( stepen_polinoma + 1 );

    bool indikator = !datoteka.eof() && mali_citac<double>( datoteka, stepen_polinoma, brojeva_u_redu, koeficijenti );
    while ( indikator )
    {
        niz.emplace_back( koeficijenti );
        indikator = !datoteka.eof() && mali_citac<double>( datoteka, stepen_polinoma, brojeva_u_redu, koeficijenti );
    };
};

/*
void ucitaj_polinome( std::fstream &datoteka, int stepen_polinoma, int brojeva_u_redu, std::vector<Polinom> &niz )
{
    std::vector<double>koeficijenti( stepen_polinoma + 1 );

    bool indikator = !datoteka.eof() && citac_u_redu<double>( datoteka, stepen_polinoma + 1, brojeva_u_redu, koeficijenti );
    while ( indikator )
    {
        niz.emplace_back( koeficijenti );
        indikator = !datoteka.eof() && citac_u_redu<double>( datoteka, stepen_polinoma + 1, brojeva_u_redu, koeficijenti );
    };
};
*/

/*
void ucitaj_x_ove( std::fstream &datoteka, int broj_koordinata, int brojeva_u_redu, std::vector<Polinom> &polinomi, std::vector<Racun> &niz )
{
    int broj_polinoma = polinomi.size();
    std::vector<double>tacke( broj_koordinata );

    bool indikator = !datoteka.eof() && citac_u_redu<double>( datoteka, broj_koordinata, brojeva_u_redu, tacke );
    int  rb_polinoma_po_kome_ce_biti_racunato = 0;
    while ( indikator )
    {
        niz.emplace_back( polinomi.at( rb_polinoma_po_kome_ce_biti_racunato % broj_polinoma ), tacke );
        indikator = !datoteka.eof() && citac_u_redu<double>( datoteka, broj_koordinata, brojeva_u_redu, tacke );
        rb_polinoma_po_kome_ce_biti_racunato++;
    };
};
*/

void ucitaj_x_ove( std::fstream &datoteka, int broj_koordinata, int brojeva_u_redu, std::vector<Polinom> &polinomi, std::vector<Racun> &niz, Polinomi& kolekcija )
{
    int broj_polinoma = polinomi.size();
    std::vector<double>tacke( broj_koordinata );

    bool indikator = !datoteka.eof() && citac_u_redu<double>( datoteka, broj_koordinata, brojeva_u_redu, tacke );
    int  rb_polinoma_po_kome_ce_biti_racunato = 0;
    while ( indikator )
    {
        niz.emplace_back( polinomi.at( rb_polinoma_po_kome_ce_biti_racunato % broj_polinoma ), tacke, kolekcija );
        indikator = !datoteka.eof() && citac_u_redu<double>( datoteka, broj_koordinata, brojeva_u_redu, tacke );
        rb_polinoma_po_kome_ce_biti_racunato++;
    };
};


