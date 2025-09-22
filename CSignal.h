    #include<iostream>

    class Tocak{

        public:
            int signal[4] = {0};

        public:

            Tocak(){};
            Tocak( int *);
            ~Tocak(){};


            void printTocak( bool );
    };

    Tocak::Tocak( int *niz ){

        for( int i = 0; i < 4; i++ ){
            *( signal + i ) = *( niz + i );
        };

    };


    void Tocak::printTocak( bool ind){

        for( int i = 0; i < 4; i++ ){

            std::cout << *( signal + i ) << " ";

        };

        if( ind ) std::cout << std::endl;
    };