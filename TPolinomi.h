class Polinomi{

    public:
    
    std::vector<Polinom> polinomi;

    public:

    void Dodaj( Polinom& );
    void Print( bool );

    double Izracunaj( Polinom& p, double x);
};

void Polinomi::Dodaj( Polinom& p) {
     polinomi.push_back(p); 
};

double Polinomi::Izracunaj( Polinom &p, double x ){
    double suma = p.koeficijenti.at(p.stepen_polinoma);

        for (int i = p.stepen_polinoma - 1; i >= 0; i--)
            suma = suma * x + p.koeficijenti.at(i);

    return suma;

};
void Polinomi::Print(bool ind) { 
    for( int i = 0 ; i < polinomi.size() ; i++ ) polinomi.at(i).Print( true );
    if( ind ) std::cout << std::endl;
};