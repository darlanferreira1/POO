#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <memory>

using namespace std;

class cliente{
    string nome;
    string id;
    public:
    
    cliente(string nome, string id){
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
    vector<shared_ptr<cliente>> cadeiras;


    public:
    sala(int capacidade): cadeiras(capacidade,nullptr){

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
        for(int i = 0; i < cadeiras.size(); i++){
            if(cadeiras[i] != nullptr){
                if(cadeiras[i]->getid() == id){
                    return true;
                }
            }
        }
        return false;
    }

    void reservar(shared_ptr<cliente> cliente, int cadeira){
        int cont=0;
        if(cadeiras[cadeira] != nullptr){
            cout<< "Cadeira ocupada" <<endl;
        }
        if(cadeira >= cadeiras.size()){
            cout<< "Cadeira inexistente"<<endl;
        }
        
        for(int i = 0; i < cadeiras.size(); i++){
            if(cadeiras[i] != nullptr){
                if(cadeiras[i] == cliente){
                    cout<< cliente->getNome() <<" ja esta no cinema"<<endl;
                    cont+=1;
                }
            }
        }
        if(cadeiras[cadeira] == nullptr && cont == 0){
            cadeiras[cadeira] = cliente;
            cout<< cliente->getNome() <<" reservou a cadeira " << cadeira <<endl;
        }

    }

    void cancelar(int cadeira){
        if(cadeira >= cadeiras.size()){
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
        for(int i = 0; i < cadeiras.size(); i++){
            if(cadeiras[i] != nullptr){
                cout << cadeiras[i]->getNome() << ":" << cadeiras[i]->getid() << " ";
            }else{
                cout << "-";
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
                cout << "mostrar, reservar, cancelar, sair" << endl;
                cin >> comando;

                if(comando == "mostrar"){
                    sala1.imprimir();
                }else if(comando == "reservar"){
                    cout<< "digite nome, id e a cadeira:" <<endl;
                    string nome, id;
                    int cadeira;
                    cin >> nome >> id >> cadeira;
                    if(sala1.idsIguais(id)){
                        cout << "id ja existente" << endl;
                    }else{
                    sala1.reservar(make_shared<cliente>(nome, id), cadeira);
                    }
                }else if(comando == "cancelar"){
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
    cinema c = cinema(sala(10));
    c.nova_sala();


    return 0;
}