class Racun : public Polinom{
    public:
        Polinom polinom;
        std::vector<double> x_koordinate;
        std::vector<double> y_koordinate;
    
        public:
        Racun(){};
        Racun( Polinom&, std::vector<double>&, Polinomi& );
       ~Racun(){};

        void Print( bool );

};

Racun::Racun( Polinom& p, std::vector<double>& x, Polinomi& pi ) : polinom( p ), x_koordinate( x )
{
    double xi;
    for( double i = 0; i < x_koordinate.size(); i++ ) {
        xi = x_koordinate.at(i);
    y_koordinate.push_back( pi.Izracunaj( p, xi ) );
    };
};

void Racun::Print( bool ind )
{
    std::cout << "Polinom: ";
    polinom.Print( true );
    std::cout << "X: ";
    PrintVektorBrojeva( x_koordinate, true );
    std::cout << "Y: ";
    PrintVektorBrojeva( y_koordinate, true );
    if( ind ) std::cout << std::endl;
};