#include "Menu.h"

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <time.h>

//CLASE CREADA
#include "Juego.h"
#include "Texto.h"
#include "Fondo.h"

using namespace sf;

Menu::Menu (int _ancho, int _alto,std::string _nombre)
{
    fps=80;

    menu1 = new RenderWindow(VideoMode(_ancho,_alto), _nombre);

    menu1-> setFramerateLimit(fps);

    menu_fond=new Fondo(nombre_carpeta,nombre_fondo);
    text_menu= new Texto;
    text_menu->mens_tam_pos(Mensaje1,45,45,100);

    //txt_boton = new Texture;
    //spr_boton = new Sprite;
    //txt_boton->loadFromFile("Imagenes/Menu/boton jugar.png");
    //spr_boton->setTexture(*txt_boton);

    //textura3 = new Texture;
    //sprite3 = new Sprite;
    //textura3->loadFromFile("Imagenes/Menu/cursor.png");
    //sprite3->setTexture(*textura3);

    evento1 = new Event;

    GameLoop();

}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Menu::GameLoop()
{
    while(menu1->isOpen())
    {
        Iniciar_Eventos();
        Mostrar();
    }

}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Menu::Mostrar()
{
    menu1->clear();

    menu1->draw(menu_fond->dev_spr_fond());

    //spr_boton->setPosition(320,547);
    //menu1->draw(*spr_boton);

    //menu1->draw(*sprite3);

    menu1->draw(text_menu->dev_text());

    menu1->display();
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

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
            }

            if(Keyboard::isKeyPressed(Keyboard::Escape))
            {
                menu1->close();
                exit(1);
                break;
            }

        /*case Event::MouseMoved:
            sprite3->setPosition((Vector2f)Mouse::getPosition(*menu1));
            break;*/


        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

/*Menu::~Menu()
{
    delete menu1;
    delete menu_fond;
    delete text_menu;
}*/
