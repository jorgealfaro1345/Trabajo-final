#include "menu.h"
#include "Juego.h"
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

menu ::menu (int _ancho, int _alto,std::string _nombre)
{
    fps=80;

    menus = new RenderWindow(VideoMode(_ancho,_alto), _nombre);

    menus-> setFramerateLimit(fps);

    menus->setMouseCursorVisible(true);

    textura1 = new Texture;

    textura2 = new Texture;

    textura3 = new Texture;

    sprite1 = new Sprite;

    sprite2 = new Sprite;

    sprite3 = new Sprite;

    textura1->loadFromFile("menufondo.png");

    textura2->loadFromFile("boton jugar.png");

    textura3->loadFromFile("cursor.png");

    sprite1->setTexture(*textura1);

    sprite2->setTexture(*textura2);

    sprite3->setTexture(*textura3);

    evento1 = new Event;

    gameloop();

}

void menu::gameloop()
{
    while(menus->isOpen())
    {
        iniciar_eventos();
        dibujar();
    }

}

void menu::dibujar()
{
    menus->clear();

    menus->draw(*sprite1);

    sprite2->setPosition(320,547);

    menus->draw(*sprite2);

    menus->draw(*sprite3);

    menus->display();
}

void menu::iniciar_eventos()
{
    while(menus->pollEvent(*evento1))
    {
        switch(evento1->type)
        {
        case Event::Closed:
            menus->close();
            exit(1);
            break;

        case Event::MouseButtonPressed:
            sprite3->setPosition(Mouse::getPosition(*menus));
            break;
        }
    }
}
