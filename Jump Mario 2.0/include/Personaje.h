#ifndef PERSONAJE_H
#define PERSONAJE_H

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

using namespace sf;

class Personaje
{
    public:
        struct point{int x,y;};
        int x=100,y=100,h=200;
        float dx=0,dy=0;
        Texture *txt_jugador;
        Sprite *spr_jugador;

        Personaje();
        virtual ~Personaje();
        void agregar_movimiento();
        Sprite devol_spr();
        void pos_iniciales();


    protected:

    private:
};

#endif // PERSONAJE_H*/
