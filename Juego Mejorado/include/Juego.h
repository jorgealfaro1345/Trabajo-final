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
        void pos_rand_plataformas();
        void rebote_plataformas(int &x, int &y, float &dy);
        void escenario(int &y, int &h, float &dy);
        void game_over(int &y);

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
        struct point{int x,y;};
        point plat[20];
        int x=100,y=100,h=200;
        float dx=0,dy=0,dp=0;



};

#endif // JUEGO_H
