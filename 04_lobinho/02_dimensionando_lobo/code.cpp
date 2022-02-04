#include <sfml/graphics.hpp>
#include <iostream>

    
int main (){
    sf::RenderWindow window(sf::VideoMode(800,500),"o jogo"); //define o tamanho da janela
    //os parametros sao videomode:tamanho, seguido do nome da janela

    sf::Texture wolf_tex; //criando um objeto que será a textura
    // wolf_tex.loadFromFile("lobol.png"); primeiro jeito importando a foto ao objeto

    if(!wolf_tex.loadFromFile("lobol.png")){
        std::cout << "Error loading texture " <<std::endl;
        exit(1);
    }


    sf::Sprite wolf(wolf_tex);//mandando mostrar o lobo criando tipo uma função
    wolf.setPosition(100,100);
    sf::FloatRect rect = wolf.getGlobalBounds(); //variavel rect que recebe a função que retorna as dimensões da imagem
    wolf.setScale(100 / rect.width, 100/rect.height); //a escala é dada por um numero opreado(+-/*) pelos parametros de Floatrect
    //no caso rect recebe height e width
    while(window.isOpen()){ //laço pra manter a janela
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        
        
        window.clear();//LIMPA TELA
        window.draw(wolf); //mandando desenhar a função lobo
        window.display();   //MOSTRA AS COISA
    }

    return 0;
}