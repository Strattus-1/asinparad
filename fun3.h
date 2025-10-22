
std::vector<Polinom> ucitajPolinome( std::fstream& ulaz, int n, int m ){
    std::vector<Polinom> p;
    for (int i = 0; i < m; i++) {
        std::vector<double> koeficijenti;
        for (int j = 0; j <= n; j++) {
            double k;
            ulaz >> k;
            koeficijenti.push_back(k);
        };
        Polinom polinom(koeficijenti, n);
        p.push_back(polinom);
    }
    return p;
};

std::vector<Racun> ucitajRacune( std::fstream& ulaz, Polinomi& polinomi, int m ){

    std::vector<Racun> racuni;

    for ( int i = 0; i < 10; i++ ) {
        std::vector<double> x;
        for ( int j = 0; j < m; j++ ) {
            double xi;
            ulaz >> xi;
            x.push_back(xi);
        };
        Racun racun(polinomi, i % m, x);
        racuni.push_back(racun);
    };
    return racuni;
};

void ispisiRacune( std::vector<Racun>& racuni){

    for ( int i = 0; i < racuni.size(); i++ ){
        std::cout << "Racun " << i + 1 << ":" << std::endl;
        racuni.at(i).Print(true);
    };

};