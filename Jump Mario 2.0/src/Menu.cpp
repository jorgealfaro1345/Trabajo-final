#include "Menu.h"

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <time.h>

//CLASE CREADA
#include "Juego.h"
using namespace sf;

Menu::Menu (int _ancho, int _alto,std::string _nombre)
{
    fps=80;

    menu1 = new RenderWindow(VideoMode(_ancho,_alto), _nombre);

    menu1-> setFramerateLimit(fps);

    menu1->setMouseCursorVisible(true);

    txt_fond = new Texture;

    txt_boton = new Texture;

    //textura3 = new Texture;

    spr_fond = new Sprite;

    spr_boton = new Sprite;

    //sprite3 = new Sprite;

    txt_fond->loadFromFile("Imagenes/Menu/menufondo.png");

    txt_boton->loadFromFile("Imagenes/Menu/boton jugar.png");

    //textura3->loadFromFile("cursor.png");

    spr_fond->setTexture(*txt_fond);

    spr_boton->setTexture(*txt_boton);

    //sprite3->setTexture(*textura3);

    menu1->setMouseCursorVisible(false);

    evento1 = new Event;

    GameLoop();

}





void Menu::GameLoop()
{
    while(menu1->isOpen())
    {
        Iniciar_Eventos();
        Mostrar();
    }

}






void Menu::Mostrar()
{
    menu1->clear();

    menu1->draw(*spr_fond);

    spr_boton->setPosition(320,547);

    menu1->draw(*spr_boton);

    //menu1->draw(*sprite3);

    menu1->display();
}






void Menu::Iniciar_Eventos()
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
                break;
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



/*Menus::~Menus()
{
    //dtor
}*/
