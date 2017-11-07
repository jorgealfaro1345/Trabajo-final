#ifndef MENUS_H
#define MENUS_H
#include <SFML/Graphics.hpp>
#include "Juego.h"
using namespace sf;


class Menus
{
    public:
        Menus(int _ancho, int _alto,std::string _nombre);
        virtual void GameLoop();
        virtual void Iniciar_Eventos();
        virtual void Mostrar();
        //virtual ~Menu Principal();

    protected:
        RenderWindow *menu1;
        Texture *textura1;
        Texture *textura2;
        //Texture *textura3;
        Sprite *sprite1;
        Sprite *sprite2;
        //Sprite *sprite3;
        int fps;
        Event *evento1;
        //struct point{int x,y};
    //protected:
};

#endif // MENUS_H
