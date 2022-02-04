#include <sfml/graphics.hpp>
#include <iostream>

    void setSize(sf::Sprite& sprite, int width, int height) {
        auto dim = sprite.getLocalBounds();
        sprite.setScale((float) width / dim.width, (float) height / dim.height);
    }

//o lobo e o coelho serao armazenados em structs

    struct Entity{ //entidades(lobo coelho e talz)
        //três atributos, dimensões, tamanho dos passos
        int x {0};  
        int y {0};
        int step {0};
        sf::Sprite sprite;
        
        Entity(int x, int y, int step, sf::Texture& texture) { //construtor
            //recebe a posição xy, tamanho do passo e a imagem
            this->x = x;
            this->y = y;
            this->step = step;
            this->sprite.setTexture(texture);
        }

        void draw(sf::RenderWindow& window) {//método, pode ser chamado varias vezes
            //draw recebe o mapa
            this->sprite.setPosition(x * step, y * step);
            setSize(this->sprite, step, step);/*  */
            window.draw(this->sprite);
        }

    };
//plano de fundo
    struct Board {
        int nc {0};
        int nl {0};
        int step {0};//atributos
        sf::Sprite sprite;
        sf::RectangleShape rect;
        //parametros
        Board(int nc, int nl, int step, sf::Texture& texture) {
            this->nc = nc;
            this->nl = nl;
            this->step = step;
            this->sprite.setTexture(texture);
            setSize(this->sprite, nc * step, nl * step);
            this->sprite.setPosition(0, 0);

            this->rect.setSize(sf::Vector2f(step, step));
            this->rect.setFillColor(sf::Color::Transparent);
            this->rect.setOutlineColor(sf::Color::Black);
            this->rect.setOutlineThickness(1);
        }
        void draw(sf::RenderWindow& window) {
            window.draw(this->sprite);
            for (int i = 0; i < nc; i++) {
                for (int j = 0; j < nl; j++) {
                    rect.setPosition(i * step, j * step);
                    window.draw(rect);
                }
            }
        }
    };

    //função recebendo tecla, entidade e votor move keys
    void moveEntity(sf::Keyboard::Key key, Entity& entity, std::vector<sf::Keyboard::Key> move_keys) {
        if (key == move_keys[0])
            entity.x--;
        else if (key == move_keys[1])
            entity.y--;
        else if (key == move_keys[2])
            entity.x++;
        else if (key == move_keys[3])
            entity.y++;
    }

    //crregador de texturas
    sf::Texture loadTexture(std::string path){
        sf::Texture texture;
        if(!texture.loadFromFile(path)){
        std::cout << "Error loading texture " <<std::endl;
        exit(1);
    }
    return texture;
    }

int main (){
    const int STEP {100};

    sf::Texture wolf_tex {loadTexture("lobol.png")};  

    /* if(!wolf_tex.loadFromFile("lobol.png")){
        std::cout << "Error loading texture " <<std::endl;
        exit(1);
    } */

    //textura coelho:
    sf::Texture rabbit_tex { loadTexture("coelho.png")};
    sf::Texture grass_tex {loadTexture("grama.jpg")};
    /* 
        outro jeito de importar textura
        if(!wolf_tex.loadFromFile("coelho.png")){
        std::cout << "Error loading texture " <<std::endl;
        exit(1);
    } */

    //criando seres do joguinho

    Entity wolf(1,1,STEP,wolf_tex); //chamando o construtor do lobo para cria a entidade lobo
    Entity rabbit(3,3,STEP,rabbit_tex);
    Board board(7,5,STEP,grass_tex); //fundo
    sf::RenderWindow window(sf::VideoMode(board.nc*STEP,board.nl*STEP),"o jogo"); //desenhando janela de acordo com as dimensões do quadrado

    while(window.isOpen()){ //laço pra manter a janela
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            //movimentação
            } else if((event.type == sf::Event::KeyPressed) ){
                if((rabbit.x!=wolf.x) && (rabbit.y!=wolf.y)){
                moveEntity(event.key.code,wolf,{sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Right, sf::Keyboard::Down});
                moveEntity(event.key.code,rabbit,{sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::D, sf::Keyboard::S});
                }
                
            }
                
                /*
                movimentção só do lobo
                 else if(event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Left){
                    wolf.x--;
                } else if (event.key.code == sf::Keyboard::Up){
                    wolf.y--;
                } else if (event.key.code == sf::Keyboard::Right){
                    wolf.x++;
                } else if (event.key.code == sf::Keyboard::Down){
                    wolf.y++;
                } */ 
        }
        
        
        window.clear();//LIMPA TELA
        board.draw(window);//desenhar o quadrado
        wolf.draw(window); //mandando desenhar a função lobo
        rabbit.draw(window);
        window.display();   //MOSTRA AS COISA
    }

    return 0;
}