#ifndef MENU_H
#define MENU_H

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

//CLASE CREADA
#include "Juego.h"
#include "Texto.h"
#include "Fondo.h"
#include "Sonidos.h"

using namespace sf;

class Menu
{
    public:
        Menu(int _ancho, int _alto,std::string _nombre);
        virtual void GameLoop();
        virtual void Iniciar_Eventos();
        virtual void Mostrar();

        virtual ~Menu ();

    private:
        RenderWindow *menu1;
        int fps;
        int person;
        Event *evento1;

        Sonidos *snd_menu;

        Sonidos *musica;

        Fondo *menu_fond;

        Texto *text_menu;
        std::string Mensaje1="Press space to play or escape to exit";
        //Texture *txt_boton;
        //Texture *textura3;
        //Sprite *spr_boton;
        //Sprite *sprite3;

};

#endif // MENU_H
