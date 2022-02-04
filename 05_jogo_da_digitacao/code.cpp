#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

struct Pincel{
    RenderWindow& window;
    Font font;
    Text text;

    Pincel(RenderWindow& window): window(window){

    }

    void escrever(string str, int x, int y, int size = 20, Color color = Color::Black){

    }
    
};
struct Bolha{
    static const int raio {15};

    int x;
    int y;
    char letra;
    int velocidade;
    bool alive {true};

    Bolha(int x, int y, char letra, int velocidade){

    }

    void atualizar (){

    }

    void desenhar (RenderWindow& window){

    }
};
struct Quadro{
    RenderWindow& janela;
    vector<Bolha> bolhas;
    int new_buble_timeout {30};
    int new_buble_timer {0};
    int acertos {0};
    int erros {0};

    Quadro(RenderWindow& janela): janela(janela){

    }

    bool check_new_bubble(){

    }

    void add_new_bubble(){

    }

    void update(){

    }

    void remove_dead_bubble(){

    }

    void hit_bubbles(char letra){

    }

    void desenhar(){

    }

};
struct Jogo{
    Quadro quadro;
    RenderWindow& janela;
    //function<void()> on_update;

    Jogo(RenderWindow& window): quadro(window), janela(window){

    }

    void main_loop(){
        
    }

    void gameplay(){
        this->quadro.update();
        this->quadro.desenhar();
        if(this->quadro.erros > 5){

        }
    }

    void gameover(){

    }
};

void processar_eventos(RenderWindow& window, Jogo &game){

}
int main (){
    RenderWindow janela {VideoMode(800,800), "Bubble sort"};
    janela.setFramerateLimit(30);
    Jogo game(janela);

    while(janela.isOpen()){
        processar_eventos(janela,game);
        janela.clear();
        //game.on_update();
        janela.display();
    }

    return 0;
}