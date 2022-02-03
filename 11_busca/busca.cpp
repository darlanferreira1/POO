#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Telefone{
    string label = "";
    string numero = "";
    
    public:
    
    Telefone(string label, string numero){
        this->label = label;
        this->numero = numero;
    }
    
    bool onlynumbers(string s){
        string numbers = "0123456789()";
        for(int i = 0; i < s.length(); i++){
            if (numbers.find(s[i]) == string::npos){ 
                return false;
            }

        }
        return true;
    }


    string getLabel(){
        this->label = label;
        return label;
    } 

    string getNumero(){
        this->numero = numero;
        return numero;
    } 

    string setLabel(string label){
        this->label = label;
        return label;
    }

    string setNumero(string numero){
        onlynumbers(numero);
        if(numero.size() == 11 && onlynumbers(numero)==true){
            this->numero = numero;
            return numero;
        }
        else{
            cout << "Numero invalido" << endl;
            return "";
        }
    }

};

class Contato{
    vector<Telefone> fones;
    string nome;

    public:

    Contato (string nome){
        this->nome = nome;
    }
    
    void addfone (Telefone telefone){
        fones.push_back(telefone);
    }

    void rmfone (int fone){
        fones.erase(fones.begin()+fone);
    }
    
    void listfones(){
        cout << nome << " ";
        for(int i = 0; i < fones.size(); i++){
            cout << "["<< i << ":" <<fones[i].getLabel() << ":" << fones[i].getNumero() << "] ";
        }
        cout << endl;
    }
     
    vector<Telefone> getFone(){
        this->fones = fones;
        return fones;
    }

    string getNome(){
        this->nome;
        return nome;
    }

    string setNome(string nome){
        this->nome = nome;
        return nome;
    }


};

class Agenda{
    vector<Contato> contatos;
    public:
    
    
    void ordenarcontatos(){
        sort(contatos.begin(), contatos.end(), [](Contato a, Contato b){
            return a.getNome() < b.getNome();
        });
    }
    
    void addContato(Contato c){
        contatos.push_back(c);
        ordenarcontatos();
    }

    void rmContato(int contato){
        contatos.erase(contatos.begin()+contato);
    }
    
    
    void buscarcontato (string padrao){
        vector<Contato> resultado;
        cout<<"\nResultado da busca por: " << padrao <<endl;
        for(auto contato : contatos){

            stringstream ss;
            ss << contato.getNome();
            for(auto fone : contato.getFone()){
                ss << fone.getLabel() << fone.getNumero();
            }
            string s = ss.str();
            if(s.find(padrao) != string::npos){
                resultado.push_back(contato);
                resultado[resultado.size()-1].listfones();

            }
        }
    }

    void printContatos(){
        cout <<"Contatos: "<<endl;
        for(auto contato : contatos){
            contato.listfones();
        }
    }

    
};

int main (){
    Agenda agenda;
    Telefone fone1("Casa", "988888888");
    Telefone fone2("Trabalho", "977777777");
    Telefone fone3("Celular", "955555555");
    
    Contato contato1("Joao silva guerra");
    Contato contato2("Joao jaime guerra");
    Contato contato3("Cassia santos");

    contato1.addfone(fone1);
    contato1.addfone(fone2);
    contato2.addfone(fone3);

    agenda.addContato(contato1);
    agenda.addContato(contato2);
    agenda.addContato(contato3);

    agenda.printContatos();
    agenda.buscarcontato("Joao");


    return 0;
}