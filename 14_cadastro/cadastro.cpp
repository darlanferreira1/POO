#include <iostream>
#include <map>
#include <vector>
#include <memory>

class Conta{
    protected:
        float balance;
        std::string clientId;
        int id;
        std::string type;

    public:
    Conta(int id, std::string clientId){
        this->id = id;
        this->clientId = clientId;
    };

    virtual void monthlyUpdate() = 0;

    void deposit(float value){
        this->balance += value;
    }

    void withdraw(float value){
        if(value>this->balance){
            std::cout << "Saldo insuficiente" << std::endl;       
        }else{
            this->balance -= value;
        }
    }

    void transfer(std::shared_ptr<Conta> destino, float valor){
        if(destino == nullptr){
            std::cout << "Conta não encontrada" << std::endl;
        }else{
            this->withdraw(valor);
            destino->deposit(valor);
        }

    }

    float getBalance(){
        return this->balance;
    }

    std::string getClientId(){
        return this->clientId;
    }

    int getId(){
        return this->id;
    }

    std::string getType(){
        return this->type;
    }

    friend std::ostream& operator<<(std::ostream& os, Conta& conta){
        os<< "Dados do cliente: " << std::endl;
        os << "Id: " << conta.getId() << " Cliente: " << conta.getClientId() << " Saldo: " << conta.getBalance() << std::endl;
        return os;
    }

};

class Poupanca : public Conta{
    private:

    public:
    Poupanca (int id,std::string clientId) : Conta(id, clientId){
        this->type = "ContaP";
    }

    void monthlyUpdate(){
        this->balance += 0.01;
    }
};

class Corrente : public Conta{
    private:

    public:

    Corrente (int id,std::string clientId) : Conta(id, clientId){
        this->type = "ContaC";
    }

    void monthlyUpdate(){
        this->balance -= 20;
    }

    
};

class Cliente{
    private:
    std::vector <std::shared_ptr<Conta>> contas;
    std::string clientId;
    public:
    Cliente(std::string clientId){
        this->clientId = clientId;
    };

    void addConta(std::shared_ptr<Conta> account){
        this->contas.push_back(account);
    }


    std::vector<std::shared_ptr<Conta>> getContas(){
        return this->contas;
    }

    std::string getClientId(){
        return this->clientId;
    }

    friend std::ostream& operator<<(std::ostream& os, Cliente& cliente){
        os << "Cliente:  " << cliente.clientId << " [";

        for (int i = 0; i < (int) cliente.contas.size(); i++) {
            if (i > 0) {
                os << ", " << cliente.contas[i]->getId();
            } else {
                os << cliente.contas[i]->getId();
            }
        }
        os << "]";
        return os;
    }
};

class Banco {
    private:
        std::map<int, std::shared_ptr<Conta>> contas;
        std::map<std::string,std::shared_ptr<Cliente>> clientes;
        int nextAccountId;
    public:
    
    Banco(){}
    
    void addCliente(std::string clientId){
        this->clientes.insert(std::pair<std::string,std::shared_ptr<Cliente>>(clientId,std::make_shared<Cliente>(clientId)));

        std::shared_ptr<Conta> cCorrente = std::make_shared<Corrente>(this->nextAccountId,clientId);
        this->contas.insert(std::pair<int,std::shared_ptr<Conta>>(this->nextAccountId,cCorrente));
        this->clientes[clientId]->addConta(cCorrente);
        this->nextAccountId++;

        std::shared_ptr<Conta> cPoupanca = std::make_shared<Poupanca>(this->nextAccountId,clientId);
        this->contas.insert(std::pair<int,std::shared_ptr<Conta>>(this->nextAccountId,cPoupanca));
        this->clientes[clientId]->addConta(cPoupanca);
        this->nextAccountId++;

    }
    void deposit(int Idconta, float valor){
        this->contas[Idconta]->deposit(valor);   

    }
    void monthlyUpdate(){
        for(auto &c : this->contas){
            c.second->monthlyUpdate();
        }
    }
    
    void transfer(int contaDe, int contaPara, float valor){
        this->contas[contaDe]->transfer(this->contas[contaPara],valor);
    }
    void withdraw(int idConta, float Valor){
        this->contas[idConta]->withdraw(Valor); 
    }

    friend std::ostream& operator<<(std::ostream& os, Banco& banco){
        os << "Clientes: " << std::endl;
        for(auto &c : banco.clientes){
            os << *(c.second) << std::endl;
        }
        os << "Contas: " << std::endl;
        for(auto &c : banco.contas){
            os << *(c.second) << std::endl;
        }
        return os;
    }
        
};

int main (){
    Banco b;
    b.addCliente("123");

    b.deposit(0,100);

    b.monthlyUpdate();

    std::cout << b << std::endl;






    return 0;
}