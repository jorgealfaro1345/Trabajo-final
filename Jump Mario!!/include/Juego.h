#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Juego
{
    public:
        Juego(int _ancho, int _alto,std::string _nombre);
        void gameloop();
        void mostrar();
        void iniciar_eventos();
        void agregar_movimiento();

    private:
        struct point
        { int x,y;};
        RenderWindow *ventana1;
        int fps;
        Texture *textura1;
        Texture *textura2;
        Texture *textura3;
        Sprite *sprite1;
        Sprite *sprite2;
        Sprite *sprite3;
        Event *evento1;
        int x=280,y=615,h=200;
        float dx=0,dy=0;
        //Vector2f velocidad ;
        //Vector2f aceleracion ;
        float gravity ;
        point plat[20];

};

#endif // JUEGO_H
