#include <iostream>
#include <vector>
    struct Pessoa{
        std::string nome {""};
        int idade {0};

        Pessoa(std::string nome, int idade):
            nome(nome), idade(idade){
                //std::cout << "Uma nova Pessoa Chegou" << std::endl;
            }
        ~Pessoa(){
            //std::cout << "Uma Pessoa Saiu" << std::endl;
        }
    };

    struct Moto{
        int potencia {1};
        int tempo {0};
        Pessoa pivete {"", 0};
        
        Moto(int potencia =1, int tempo =0):
            potencia(potencia), tempo(tempo){
                std::cout << "Uma moto esta disponivel" << std::endl;
            }
        //insrir pessoa:
        void subir(std::string nome, int idade){
            std::cout << "Uma nova Pessoa Chegou" << std::endl;
            if(idade>13 && pivete.nome ==""){
            pivete.nome = nome;
            pivete.idade = idade;
            std::cout << pivete.nome <<" Nao pode subir, mt velho" << std::endl;
            pivete.nome = "";
            pivete.idade = 0;
            }else{
                pivete.nome = nome;
                pivete.idade = idade;
                std::cout << pivete.nome << " pode subir" << std::endl;
            }
        }

        //descer:
        void descer(){
            if(pivete.nome !=""){
            std::cout << pivete.nome << " desceu" << std::endl;
            }else{
                std::cout << "Nao ha ninguem para descer" << std::endl;
            }
        }

        //comprar tempo:
        void comprarTempo(int tempo){
            if(pivete.nome !=""){
            this->tempo += tempo;
            std::cout << pivete.nome <<" comprou mais " << tempo << " minutos" << std::endl;
            }else{
                std::cout << "Nao ha ninguem para comprar tempo" << std::endl;
            }
        }

        //buzinar:
        void buzinar(int potencia){
            char buzina[potencia];
            if(pivete.nome !=""){for(int i=0; i<potencia; i++){
                buzina[i] = 'e';
            }
            std::cout << "P";
            for(int i=0; i<potencia ; i++){
                if(buzina[i]=='e')std::cout << buzina[i];
            }
            std::cout << "m" << std::endl;
            }else{
                std::cout << "sem buzinas hoje ;-;" << std::endl;
            }
        }
    };
    
int main(){
    Pessoa pessoa   ( "Joao", 15);
    Moto moto   (5, 10);
    moto.subir("Joao", 15);
    moto.comprarTempo(10);
    moto.buzinar(5);
    moto.descer();
    return 0;
}