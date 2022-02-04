#include <iostream>
#include <vector>

using namespace std;

class Telefone{
    string label = "";
    string numero = "";
    
    public:
    
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
        if(numero.size()<10 && onlynumbers(numero)==true){
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
    Contato(string nome){
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
    }
     
    vector<Telefone> getFone(){
        this->fones = fones;
        return fones;
    }

    string getNome(){
        this->nome;
        return nome;
    }


};

int main (){
    Contato contato {"Josias"};
    Telefone telefone;
    telefone.setLabel("Celular");
    telefone.setNumero("(88)98765");
    contato.addfone(telefone);
    telefone.setLabel("Fixo");
    telefone.setNumero("(88)98365");
    contato.addfone(telefone);
    telefone.setLabel("Celular");
    telefone.setNumero("(88)984d3485");
    contato.addfone(telefone);
    contato.listfones();
    contato.rmfone(0);
    contato.listfones();

    return 0;
}