#ifndef PERSONAJE_H
#define PERSONAJE_H

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

//CLASE CREADA
#include "Texto.h"

using namespace sf;

class Personaje
{
    public:
        struct point{int x,y;};
        int x=300,y=100,h=200;
        int *vidas;
        float dx=0,dy=0;
        Texture *txt_jugador;
        Sprite *spr_jugador;
        std::string carpeta,imagen,imagen2;
        std::string vidasstr;
        Texto *vidast;

        Personaje();
        void pers_imagen();
        void pers_imagen(int x);
        void pers_imagen(double x);
        void pers_imagen(std::string x);
        void agregar_movimiento();
        Sprite devol_spr();
        void posyvidas_iniciales();
        int return_vidas();
        Text devo_vidas();


        virtual ~Personaje();

};

#endif // PERSONAJE_H*/
