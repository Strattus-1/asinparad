
class Polinomi{
    public:
        std::vector<Polinom> polinomi;

    public:
        Polinomi(){};
        Polinomi(  std::vector<Polinom> & );
       ~Polinomi(){};

        void Print( bool );
};

Polinomi::Polinomi(  std::vector<Polinom> &p ) : polinomi( p ){};

void Polinomi::Print( bool ind ){
    for( int i = 0 ; i < polinomi.size() ; i++ )
    {
        std::cout << "Polinom " << i << ": ";
        polinomi.at(i).Print( true );
    }

    if( ind ) std::cout << std::endl;
};


