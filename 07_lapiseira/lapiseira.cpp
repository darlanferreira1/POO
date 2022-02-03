#include <iostream>
    struct Grafite {
        float calibre = 0;
        int tamanho = 0;
        std::string dureza = "";

        Grafite(float calibre = 0, int tamanho = 0, std::string dureza="0"):
        calibre{calibre}, tamanho{tamanho}, dureza{dureza} {
        }

    };

    struct Lapiseira {
        std::string marca{""};
        std::string cor {""};
        Grafite grafites;
        
        Lapiseira(std::string marca, std::string cor):
        marca{marca}, cor{cor}{
        }

        void inserir_grafite(float calibre, int tamanho, std::string dureza) {
            this->grafites.calibre = calibre;
            this->grafites.tamanho = tamanho;
            this->grafites.dureza = dureza;
        }

        void remover_grafite() {
            this->grafites.calibre = 0;
            this->grafites.tamanho = 0;
            this->grafites.dureza = "0";
        }
        
        friend std::ostream& operator<<(std::ostream& os, const Lapiseira& lapiseira) {
            os << "Marca: " << lapiseira.marca << "\n"
            << "Cor: " << lapiseira.cor << "\n"
            << "Grafite:" <<"\n"
            << "Calibre: " << lapiseira.grafites.calibre << "\n"
            << "Tamanho: " << lapiseira.grafites.tamanho << "\n"
            << "Dureza: " << lapiseira.grafites.dureza << "\n";
            return os;
        }
        

        void escrever (int folhas) {
            //tem ou não tem?
            if(grafites.calibre == 0) { 
                std::cout << "Não há grafite para escrever" << std::endl;
            } else {
                std::cout << "Escrevendo " << folhas << " folhas" << std::endl;
            }
            //reduzindo o grafite
            if(grafites.dureza == "HB"){ grafites.tamanho-=(1*folhas);}
            else if(grafites.dureza == "2B"){ grafites.tamanho-=(2*folhas);}
            else if(grafites.dureza == "4B"){ grafites.tamanho-=(3*folhas);}
            else if(grafites.dureza == "6B"){ grafites.tamanho-=(4*folhas);}
            //se o grafite ficar vazio, ele é removido
            if(grafites.tamanho < 0){
                std::cout << "Grafite insuficiente para escrever, faltaram: " << abs(grafites.tamanho) << " folhas" << std::endl;

            }else{
                std::cout << "O grafite suficiente para escrever" << std::endl;
            }
        }
    
    };

int main() {
    int folhas = 4;
    Grafite grafite_1(0.5, 3, "HB");
    Lapiseira lapiseira {"Bic", "Azul"};
    lapiseira.inserir_grafite(0.5, 3, "HB");
    std::cout << lapiseira;
    lapiseira.escrever(folhas);
    return 0;
}