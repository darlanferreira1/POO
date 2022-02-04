#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <memory>
#include <map>

using namespace std;

class cliente{
    string nome;
    string id;
    public:
    
    cliente(string nome,  string id){
        this->nome = nome;
        this->id = id;
    }
    string getNome(){
        return nome;
    }

    string getid(){
        return id;
    }

};

class sala{
    
    int capacidade = 0;
    std::map<int,std::shared_ptr<cliente>> cadeiras = {   };


    public:
    
    sala(int capacidade){
        this->capacidade = capacidade;
        
    }

    bool validar(int cadeira){
        if(cadeira > capacidade || cadeira < 0){
            return false;
        }
        else{
            return true;
        }
    }

    bool idsIguais(string id){
        for(auto it = cadeiras.begin(); it != cadeiras.end(); it++){
            if(it->second->getid() == id){
                return true;
            }
        }
        return false;
    }


    void reservar(shared_ptr<cliente> cliente, int cadeira){
       
        if((validar(cadeira) && cadeiras[cadeira] == nullptr)){
            cadeiras[cadeira] = cliente;
            cout<< cliente->getNome() <<" reservou a cadeira " << cadeira <<endl;
        }else if(cadeiras[cadeira] != nullptr){
            cout << "Cadeira ocupada" << endl;
        }else if(!validar(cadeira)){
            cout << "Cadeira inexistente" << endl;
        }else if (cadeiras[cadeira] == cliente){
            cout << cliente->getNome() << " ja esta no cinema" << endl;
        }else{
            cout << "Erro desconhecido" << endl;
        }

    }

    void cancelar(int cadeira){
        if(!validar(cadeira)){
            cout << "cadeira inexistente" << endl;
        }else
        if(cadeiras[cadeira] == nullptr){
            cout << "cadeira nao ocupada" << endl;
        }else{
        cadeiras[cadeira] = nullptr;
        cout << "cadeira " << cadeira << " cancelada" << endl;
        }
    }


    void imprimir(){
        
        cout <<"[ ";
        for(auto i = cadeiras.begin(); i != cadeiras.end(); i++){
            if(i->second != nullptr){
                cout << i->first << ":" << i->second->getNome() << ":" << i->second->getid() << " ";
            }else{
                cout << " - ";
            }
        }
        cout << "]" << endl;
    }

};

class cinema{  
    sala sala1;
    public:
    cinema(sala sala): sala1(sala){}
    
    
    void nova_sala(){
            while (true){
                string comando;
                cout<< "Digite o comando: "<<endl;
                cout << "show, res, cancel, sair" << endl;
                cin >> comando;

                if(comando == "show"){
                    sala1.imprimir();
                }else if(comando == "res"){
                    cout<< "digite nome, id e a cadeira:" <<endl;
                    string nome, id;
                    int cadeira;
                    cin >> nome >> id >> cadeira;
                    if(sala1.idsIguais(id)){
                        cout << "id ja existente" << endl;
                    }else{
                    sala1.reservar(make_shared<cliente>(nome, id), cadeira);
                    }
                }else if(comando == "cancel"){
                    cout<< "digite o numero da cadeira:" <<endl;
                    int cadeira;
                    cin >> cadeira;
                    sala1.cancelar(cadeira);
                }else if(comando == "sair"){
                    break;
                }else{
                    std::cout << "Comando invalido" << std::endl;
                }
            }            
    }

};

int main(){
   /*  sala sala1(10);
    sala1.cu(); */
    cinema c = cinema(sala(10));
    c.nova_sala();



    return 0;
}