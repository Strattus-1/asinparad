
class Kugla{
    public:
        std::vector<int> tacke;  
    public:
        Kugla(){};
        Kugla( std::vector<Racun> &, bool );
        ~Kugla(){};

    void Print( std::vector<Racun> &, bool );
};

Kugla::Kugla( std::vector<Racun> &racuni, bool jedinicni ){

    for( int i = 0; i < racuni.size(); i++ ){

        double suma = 0.0;

        for( int j = 0; j < racuni[i].x.size(); j++ ){
            suma += racuni.at(i).x.at(j)*racuni.at(i).x.at(j) + racuni.at(i).y.at(j)*racuni.at(i).y.at(j);
        };

        if( ( jedinicni && suma <= 1.0 ) || ( !jedinicni && suma > 1.0 ) ){
            tacke.emplace_back( i );
        };
    };
};

void Kugla::Print( std::vector<Racun> &svi, bool ind ){

    for( int i = 0; i < tacke.size(); i++ ){
        std::cout << "Racun " << tacke.at(i)+1 << ":" << std::endl;
        svi.at(tacke.at(i)).Print( true );
    };

    if(ind) std::cout << std::endl;
};