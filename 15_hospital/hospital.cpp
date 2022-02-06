#include <iostream>
#include <memory>
#include <map>

class IPaciente{
public:
    virtual std::string getId() = 0;
    virtual void addMedico (std::shared_ptr<IMedico> medico) = 0;
    virtual void rmMedico (std::shared_ptr<IMedico> medico) = 0;
    virtual std::map<std::string, std::shared_ptr<IMedico>> getMedicos () = 0;
    virtual std::string getDianostico () = 0;

};

class IMedico{
public:
    virtual std::string getId () = 0;
    virtual void addPaciente (std::shared_ptr<IPaciente> paciente) = 0;
    virtual void rmPaciente (std::shared_ptr<IPaciente> paciente) = 0;
    virtual std::map<std::string, std::shared_ptr<IPaciente>> getPacientes () = 0;
    virtual std::string getClasse( ) = 0;
};


class Medico : public IMedico{
    std::string classe;
    std::map <std::string, std::shared_ptr<IPaciente>> pacientes;
    std::string idMed;
    public:
    Medico (std::string Id, std::string classe) : idMed(idMed), classe(classe){}
    void addPaciente (std::shared_ptr<IPaciente> paciente){
          
    }
    void rmPaciente(std::string Idpaciente){
        
    }

    std::string getClasse(){
        return classe;
    }
    std::map <std::string, std::shared_ptr<IPaciente>> getPacientes(){
        return pacientes;
    }
    std::string getId(){
        return idMed;
    }

};

class Paciente : public IPaciente{
    std::string diagnostico;
    std::string idPac;
    std::map <std::string, std::shared_ptr<IMedico>> medicos;
    public:
    Paciente (std::string Id, std::string dianostico) : idPac(idPac), diagnostico(dianostico){}
    void addMedico(std::shared_ptr<IMedico> medico){
      
    }
    void rmMedico(std::string idMedico){}

    

    std::string getDianostico (){
        return diagnostico;
    }
    
    std::map<std::string, std::shared_ptr<IMedico>> getMedicos (){
        return medicos;
    }

    std::string getId (){
        return idPac;
    }

};


class Hospital{
    std::map <std::string, std::shared_ptr<IMedico>> medicos;
    std::map <std::string, std::shared_ptr<IPaciente>> pacientes;
    public:
    Hospital(){
        std::cout << "Hospital criado" << std::endl;
    }
    
    void rmPaciente(std::string Id){}
    void rmMedico(std::string Id){}
    void addPaciente(std::shared_ptr<IPaciente> paciente){
    }
    void addMedico(std::shared_ptr<IMedico> medico){
    }
    void vincular(std::string nomeMedico, std::string nomePaciente){}
    
};

int main (){

    while(true){

    }
    return 0;
}