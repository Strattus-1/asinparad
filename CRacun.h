
class Racun : virtual Polinomi{
    public:
        int id;
        std::vector<double> x;
        std::vector<double> y;
    public:
        Racun( Polinomi &, int, std::vector<double> );
        Racun(){};
        ~Racun(){};

        void Print( bool );

};

Racun::Racun( Polinomi& p, int idp, std::vector<double> vx ) : Polinomi( p ), id( idp ), x ( vx ){

    int n = polinomi.at(id).stepen;             // nanjizi stepen polinoma
    int m = polinomi.size();                    // broj polinoma
    
    for( int i = 0 ; i < x.size() ; i++ )
        {
            double xi = x.at(i);
            std::vector<double> P(m+1);
            P[0] = 1;
            if(m > 0) P[1] = xi;
            for(int k = 2; k <= m; ++k) {
                P[k] = 2 * xi * P[k-1] - P[k-2];
            };
            // od stepena n do n+m-1
            for(int k = n; k < n+m; ++k) {
                if(k <= m) y.push_back(P[k]);
            };
        };

};

void Racun::Print( bool ind ){

    std::cout << "polinom (" << id << "): ";
    for( int i = 0; i < polinomi.at(id).koeficijenti.size(); i++ ){
        std::cout << polinomi.at(id).koeficijenti.at( i ) << " ";
    };
    std::cout << std::endl;

    std::cout << "x: ";
    for( int i = 0; i < x.size(); i++ ){
        std::cout << x.at( i ) << " ";
    };
    std::cout << std::endl;

    std::cout << "y: ";
    for( int i = 0; i < y.size(); i++ ){
        std::cout << y.at( i ) << " ";
    };

    if( ind ) std::cout << std::endl;
};