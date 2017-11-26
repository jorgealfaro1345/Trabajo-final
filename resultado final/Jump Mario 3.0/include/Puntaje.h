#ifndef PUNTAJE_H
#define PUNTAJE_H

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

//CLASE CREADA
#include "Texto.h"

using namespace sf;


class Puntaje
{
    public:
        long long puntaje_alt;
        std::string punt_pant;
        Texto *punt;
        Puntaje();
        void Puntos(int &plat,float &goom,float &koop);
        Text devo_punt();

        virtual ~Puntaje();
};

#endif // PUNTAJE_H
