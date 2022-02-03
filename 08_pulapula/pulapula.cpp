#include <iostream>
#include <list>
#include <memory>

using namespace std;

class Kid{
    string nome = "";
    int idade = 0;
    int conta = 0;
    
    public:
    
    Kid(string nome = "", int idade = 0, int conta =0):
    nome(nome), idade(idade), conta(conta){}

    int getIdade(){
        return idade;
    }

    string getNome(){
        return nome;
    }

    int getConta(){
        return conta;
    }

    void setConta(){
        this->conta +=1;
    }

};

class Trampolim{
    list <shared_ptr<Kid>> esperando;
    list <shared_ptr<Kid>> brincando;
    int saldo = 0;

    
    public:

    Trampolim():esperando(esperando),brincando(brincando){}


    
    void chegada(shared_ptr<Kid> kid){
        //cout << kid->getNome() << " chegou" << endl;
        this->esperando.push_back(kid);
    }

    void entrar(shared_ptr<Kid> kid){
        if(brincando.size() <2){
        this->brincando.push_back(esperando.front());
        esperando.pop_front();
        cout << kid->getNome() << " entrou" << endl;
        kid->setConta();
        }else{
            cout << "Nao ha vagas, " <<kid->getNome() << endl;
        }
    }

    void sair(shared_ptr<Kid> kid){
        this->esperando.push_back(brincando.front());
        brincando.pop_front();
        
        cout << "Saindo " << kid->getNome() << ", conta: " << kid->getConta() << endl;
        entrar(esperando.front());
    }

    void papaichegou(shared_ptr<Kid> kid){
        cout << "O Papai de " << kid->getNome() << " chegou" << endl;
        

        for(auto it = esperando.begin(); it != esperando.end(); it++){
            if((*it)->getNome() == kid->getNome()){
                esperando.erase(it);
                cout<< kid->getNome() << " estava na lista de espera" << endl;
                break;
            }
        }

        for(auto it = brincando.begin(); it != brincando.end(); it++){
            if((*it)->getNome() == kid->getNome()){
                brincando.erase(it);
                cout<< kid->getNome() << " estava no pula pula" << endl;
                break;
            }
        }

        cout << kid->getNome() << " deve " << kid->getConta() << " reais" << endl;

        saldo += kid->getConta();
    }

    int getSaldo(){
        return saldo;
    }

    void imprimir(){
        cout << "Esperando:\n" << "[ ";
        for(auto it = esperando.begin(); it != esperando.end(); it++){
            cout << (*it)->getNome() << " : ";
        }
        cout << "]\n";
        
        cout << "Brincando:\n" << "[ ";
        for(auto it = brincando.begin(); it != brincando.end(); it++){
            cout << (*it)->getNome() << " : ";
        }
        cout << "]\n";
    }

    void fechar_pula_pula(){
        cout << "Fechando pula pula" << endl;
        cout << "Saldo: " << saldo << endl;

    }
   
};

//chegar entra sair papaichegou

int main (){
    Kid k1("Pedro", 10);
    Kid k2("Luiza", 8);
    Kid k3("Joao", 5);

    shared_ptr<Kid> p1(&k1);
    shared_ptr<Kid> p2(&k2);
    shared_ptr<Kid> p3(&k3);

    Trampolim t;

    t.chegada(p1); t.chegada(p2); t.chegada(p3);
    t.imprimir();

    t.entrar(p1); t.entrar(p2); t.entrar(p3);
    t.imprimir();

    t.sair(p1); t.sair(p2);
    t.imprimir();

    t.papaichegou(p1); t.papaichegou(p2); t.papaichegou(p3);
    t.imprimir();

    cout << "Saldo do dia: " << t.getSaldo() << endl;

    return 0;
}