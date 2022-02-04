#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

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
    vector <Telefone> fones;
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
    map<string,Contato> contatos;
    public:
    
    
    void ordenarcontatos(){
        map<string,Contato>::iterator it;
        for(it = contatos.begin(); it != contatos.end(); it++){
            cout << it->first << " ";
        }
        cout << endl;
    }
    
    void addContato(Contato c){
        contatos.insert(pair<string,Contato>(c.getNome(),c));
    }

    void rmContato(string contato){
        contatos.erase(contato);
    }
    
     /* void buscarcontato (string padrao){
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
    } */
    

    void printContatos(){
        for(auto it = contatos.begin(); it != contatos.end(); it++){
            cout << it->first << endl;
        }
    }

    
};

int main (){
    Agenda agenda;
    Contato c1("Joao meneses");
    c1.addfone(Telefone("Celular","(11) 99999-9999"));

    Contato c2("Maria meneses");
    c2.addfone(Telefone("Celular","(11) 99999-9999"));
    c2.addfone(Telefone("Fixo","(11) 99999-9999"));

    agenda.addContato(c1);
    agenda.addContato(c2);

    agenda.printContatos();


    return 0;
}