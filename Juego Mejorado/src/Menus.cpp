#include "Menus.h"
#include "Juego.h"
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

Menus::Menus (int _ancho, int _alto,std::string _nombre)
{
    fps=80;

    menu1 = new RenderWindow(VideoMode(_ancho,_alto), _nombre);

    menu1-> setFramerateLimit(fps);

    menu1->setMouseCursorVisible(true);

    textura1 = new Texture;

    textura2 = new Texture;

    //textura3 = new Texture;

    sprite1 = new Sprite;

    sprite2 = new Sprite;

    //sprite3 = new Sprite;

    textura1->loadFromFile("menufondo.png");

    textura2->loadFromFile("boton jugar.png");

    //textura3->loadFromFile("cursor.png");

    sprite1->setTexture(*textura1);

    sprite2->setTexture(*textura2);

    //sprite3->setTexture(*textura3);

    menu1->setMouseCursorVisible(false);

    evento1 = new Event;

    GameLoop();

}





void Menus::GameLoop()
{
    while(menu1->isOpen())
    {
        Iniciar_Eventos();
        Mostrar();
    }

}






void Menus::Mostrar()
{
    menu1->clear();

    menu1->draw(*sprite1);

    sprite2->setPosition(320,547);

    menu1->draw(*sprite2);

    //menu1->draw(*sprite3);

    menu1->display();
}






void Menus::Iniciar_Eventos()
{
    while(menu1->pollEvent(*evento1))
    {
        switch(evento1->type)
        {
        case Event::Closed:
            menu1->close();
            exit(1);
            break;

        case Event::KeyPressed:
            if(Keyboard::isKeyPressed(Keyboard::Space))
            {
                Juego *partida1;
                partida1 = new Juego(600,697,"Jump Mario!!");
                //Juego();
            }
            if(Keyboard::isKeyPressed(Keyboard::Escape))
            {
                menu1->close();
                exit(1);
                break;
            }
        /*case Event::MouseMoved:
            sprite3->setPosition((Vector2f)Mouse::getPosition(*menu1));
            break;
*/

        }
    }
}


/*Texture Menus:: getTexture()
{
    return textura2;
}




Sprite Menus:: get_sprite()
{
    return sprite2;
}

/*Menus::~Menus()
{
    //dtor
}*/
