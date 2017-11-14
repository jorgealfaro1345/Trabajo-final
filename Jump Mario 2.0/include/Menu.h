#ifndef MENU_H
#define MENU_H

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

//CLASE CREADA
#include "Juego.h"

using namespace sf;


class Menu
{
    public:
        Menu(int _ancho, int _alto,std::string _nombre);
        virtual void GameLoop();
        virtual void Iniciar_Eventos();
        virtual void Mostrar();
        //virtual ~Menu Principal();

    protected:
        RenderWindow *menu1;
        Texture *txt_fond;
        Texture *txt_boton;
        //Texture *textura3;
        Sprite *spr_fond;
        Sprite *spr_boton;
        //Sprite *sprite3;
        int fps;
        Event *evento1;

    private:
};

#endif // MENU_H
