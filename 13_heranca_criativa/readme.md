## Herança criativa 

```cpp
#include <iostream>


class Periferico{
    private:
    
    bool Plugged = false;
    
    public:

    Periferico(){
        std::cout << "Periferico criado" << std::endl;
    }
    
    bool isPlugged(){
       return Plugged;
    }
    
    virtual void plug(){
        Plugged = true;
        std::cout << "Plugged" << std::endl;
    }

};

class headset : public Periferico{
    private:
    
    std::string marca {"sony"};
    bool MicIsOn = false;
    
    public:

    headset(std::string marca): marca(marca){
        std::cout << "Headset criado" << std::endl;
    }



    bool isMicOn(){
        return MicIsOn;
    }
    
    void TurnOnMic(){
        if(this->isPlugged()){
            MicIsOn = true;
            std::cout << "Mic is on" << std::endl;
        }else{
            std::cout << "Plug the headset" << std::endl;
        }
    }
    
    virtual void listen(){
        if (isPlugged()){
            std::cout << "Listening" << std::endl;
            }else{
                std::cout << "Not plugged" << std::endl;
            }
    }
    
    virtual void talk(){
        if (isPlugged()){
            if(MicIsOn){
                std::cout << "Falando" << std::endl;
            }else{
                std::cout << "Microfone Desligado" << std::endl;
            }
        }else{
                std::cout << "Not plugged" << std::endl;
        }        
    }

    std::string getMarca(){
        return marca;
    }
};

class headset_wireless : public headset{
    private:
    
    int battery = 3;
    bool wirelessIsOn = false;
    
    public:

    headset_wireless(std::string marca): headset{marca}{
        std::cout << "Headset_wireless criado" << std::endl;
    }
    
    void turnOnWireless(){
        wirelessIsOn = true;
        std::cout << "now, the wireless is on" << std::endl;
    }
    
    void plug(){
        if(wirelessIsOn){
            Periferico::plug();
        }else{
            std::cout << "Wireless is off" << std::endl;
        }
    }

    void listen(){
        if(battery>0 && isPlugged()){
            headset::listen();
            battery--;
        }else if(battery==0){
            std::cout << "Sem bateria" << std::endl;
        }else{
            std::cout << "Not plugged" << std::endl;
        }
    }

    void talk(){
        if(battery>0 && isPlugged()&& isMicOn()){
            headset::talk();
            battery--;
        }else if(battery==0){
            std::cout << "Sem bateria" << std::endl;
        }else if(!isPlugged()){
            std::cout << "Not plugged" << std::endl;
        }else{
            std::cout << "Microfone Desligado" << std::endl;
        }
    }
    
    void charge(){
        battery = 3;
        std::cout << "batery fully charged" << std::endl;
    }
};

int main(){
    
    headset_wireless fone {"sony"};
    Periferico &periferico1 = fone;
    headset &headset1 = fone;

 


    
    periferico1.plug();
    fone.turnOnWireless();
    periferico1.plug();
    headset1.listen();
    headset1.talk();
    fone.TurnOnMic();
    headset1.talk();
    headset1.talk();
    headset1.listen();
    fone.charge();
    

    return 0;
}
```