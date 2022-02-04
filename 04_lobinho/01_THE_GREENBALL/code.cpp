#include <sfml/graphics.hpp>
#include <iostream>

int main (){
    sf::RenderWindow window(sf::VideoMode(800,500),"o jogo"); //define o tamanho da janela
    //os parametros sao videomode:tamanho, seguido do nome da janela

    while(window.isOpen()){ //laço pra manter a janela
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        sf::CircleShape shape(100.f);   //INICIANDO UM CIRCULO
        shape.setFillColor(sf::Color::Red); //COR
        shape.setPosition(300,300);     //POSIÇÃO
        shape.setOutlineColor(sf::Color(134,200,60)); //COR DA BORDA
        shape.setOutlineThickness(5.f); //LARGURA DA BORDA
        
        window.clear();//LIMPA TELA
        window.draw(shape); //DESENHA A FORMA NA TELA
        window.display();   //MOSTRA AS COISA
    }

    return 0;
}