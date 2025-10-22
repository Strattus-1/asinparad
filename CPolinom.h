
class Polinom{

    public:
        std::vector<double> koeficijenti;
        int stepen;
    
    public:
        Polinom(){};
        Polinom( std::vector<double>, int );
        ~Polinom(){};

        void Print( bool );
        
};

Polinom::Polinom( std::vector<double> k, int s ) : koeficijenti( k ){
    stepen = koeficijenti.size() - 1;
};

void Polinom::Print( bool ind ){
    std::cout << "Stepen " << stepen << ": ";

    for( int i = 0; i <= stepen; i++ ){
        std::cout << koeficijenti.at(i) << " ";
    };
    if( ind ) std::cout << std::endl;
};
