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
        int x=100,y=100,h=200,vidas;
        float dx=0,dy=0;
        Texture *txt_jugador;
        Sprite *spr_jugador;
        /*string carpeta;
        string imagen;*/

        Personaje();
        /*Personaje(int x);
        Personaje(float x);
        Personaje(char x);*/
        void agregar_movimiento();
        Sprite devol_spr();
        void pos_iniciales();

        virtual ~Personaje();

};

#endif // PERSONAJE_H*/
