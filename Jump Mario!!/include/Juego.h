#ifndef JUEGO_H
#define JUEGO_H
#include<SFML/System.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

class Juego
{
    public:

        Juego(int _ancho, int _alto,std::string _nombre);
        /*~Juego();*/
        void gameloop();
        void mostrar_and_setposicion();
        void iniciar_eventos();
        void agregar_movimiento();
        void agregar_plataformas();


    private:

        RenderWindow *pantalla_de_juego;
        int fps;
        Texture *textura1;
        Texture *textura2;
        Texture *textura3;
        Sprite *sprite1;
        Sprite *sprite2;
        Sprite *sprite3;
        Event *evento1;
        struct point{ int x,y;};
        int x=280,y=615,h=0,pos_x,pos_y;
        float dx=0,dy=0,dp=0;
        int rand_x=rand()%600;
        int rand_y=rand()%697;


};

#endif // JUEGO_H
