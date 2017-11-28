#ifndef PUNTAJE_H
#define PUNTAJE_H

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

//CLASE CREADA
#include "Texto.h"
#include "Enemigos.h"
#include "Plataformas.h"

using namespace sf;

class Puntaje
{
    public:
        double punt_pant;
        std::string punt_pantext;
        Texto *punt_pantalla;
        int *max_score;
        int* score;

        Puntaje();
        void Puntos(std::vector<Enemigos *> enemigos,Plataformas* x);
        int Puntaje_alto();
        Text devo_punt();

        virtual ~Puntaje();

};

#endif // PUNTAJE_H

