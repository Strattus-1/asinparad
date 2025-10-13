class Polinomi{

    public:
        std::vector<Polinom> listaPolinoma;
    
    public:
        Polinomi(){};
        ~Polinomi(){};

        void dodajPolinom( Polinom  );

        void PrintVrednostSvih( double  );

};

void Polinomi::dodajPolinom( Polinom P ){
    listaPolinoma.push_back( P );
};

// k1 x^3 + k2 x^2 + k3 x + k4 2

void Polinomi::PrintVrednostSvih( double d ){
    
    for( int i = 0; i < listaPolinoma.size(); i ++ ){
        std::cout << "Polinom: " << i + 1 << "vrednost: "<< listaPolinoma[ i ].vrednost( d );
        std::cout << std::endl;   
    };

};