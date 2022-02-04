#include <iostream>
#include <map>

class IPaciente{
    public:
        virtual void addMedico(IMedico*) = 0;
        virtual std::string getDiagnostico();
        virtual std::string getId();
        virtual void removeMedico(std::string) = 0;
};

class Paciente{
    std::string diagnostico;
    std::string sender;
    std::map <std::string, IMedico*> medicos;

    Paciente(){}
    void addMedico(IMedico*){}
    
};



class IMedico{

};

class Medico{

};


class Hospital{

};