class Kugla : public Racun {

    public:
        std::vector<double> x_u_kugli;
        std::vector<double> y_u_kugli;

    public:

    Kugla() {};

    Kugla(std::vector<Racun>& tacke) {
        for (int r = 0; r < tacke.size(); r++) {
            for (int i = 0; i < tacke[r].x_koordinate.size(); i++) {
                double x = tacke[r].x_koordinate[i];
                double y = tacke[r].y_koordinate[i];
                if (x * x + y * y <= 1.0) {
                    x_u_kugli.push_back(x);
                    y_u_kugli.push_back(y);
                }
            }
        }
    }

    void Print(bool ind) {
        std::cout << "Tacke unutar jedinicne kugle:" << std::endl;
        std::cout << "X: ";
        for (int i = 0; i < x_u_kugli.size(); i++)
            std::cout << x_u_kugli[i] << " ";
        std::cout << std::endl;
        std::cout << "Y: ";
        for (int i = 0; i < y_u_kugli.size(); i++)
            std::cout << y_u_kugli[i] << " ";
        std::cout << std::endl;
        if (ind) std::cout << std::endl;
    }
};