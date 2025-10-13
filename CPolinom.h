class Polinom
{
    public:
        std::vector<double> koeficijenti;
        int stepen_polinoma = 0;

    public:
        Polinom(){};
        Polinom( std::vector<double>, int );
        Polinom( std::vector<double> );

       ~Polinom(){};

       void Print( bool );
};

Polinom::Polinom( std::vector<double> v, int d ) : koeficijenti( v ), stepen_polinoma( d - 1 )
{};

Polinom::Polinom(std::vector<double> v) : koeficijenti(v), stepen_polinoma((int)v.size() - 1) {};

void Polinom::Print( bool ind )
{
    std::cout << "(" << stepen_polinoma << ")" << std::endl;
    for( int i = 0 ; i <= stepen_polinoma ; i++ ) std::cout << koeficijenti.at(i) << " ";
    if( ind ) std::cout << std::endl;
};
