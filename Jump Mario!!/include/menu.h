#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
using namespace sf;

class menu
{
    public:
         menu (int _ancho, int _alto,std::string _nombre);
         void gameloop();
         void iniciar_eventos();
         void dibujar();


    private:
        RenderWindow *menus;
        Texture *textura1;
        Texture *textura2;
        Texture *textura3;
        Sprite *sprite1;
        Sprite *sprite2;
        Sprite *sprite3;
        int fps;
        Event *evento1;
        struct point{ int x,y;};
};

#endif // MENU_H
