#ifndef MENU_H
#define MENU_H

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

//CLASE CREADA
#include "Juego.h"
#include "Texto.h"
#include "Fondo.h"

using namespace sf;

class Menu
{
    public:
        Menu(int _ancho, int _alto,std::string _nombre);
        virtual void GameLoop();
        virtual void Iniciar_Eventos();
        virtual void Mostrar();
        //virtual ~Menu Principal();

    private:
        RenderWindow *menu1;
        int fps;
        Event *evento1;

        Fondo *menu_fond;
        std::string nombre_carpeta="Menu";
        std::string nombre_fondo="menufondo";
        Texto *text_menu;
        std::string Mensaje1="Press space to play or escape to exit";

        //Texture *txt_boton;
        //Texture *textura3;
        //Sprite *spr_boton;
        //Sprite *sprite3;

};

#endif // MENU_H
