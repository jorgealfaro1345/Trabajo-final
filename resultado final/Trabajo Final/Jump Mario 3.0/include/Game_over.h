#ifndef GAME_OVER_H
#define GAME_OVER_H

//LIBRERIAS DE SFML
#include<SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

//CLASES CREADAS
#include "Texto.h"
#include "Personaje.h"
#include "Puntaje.h"

using namespace sf;

class Game_over
{
    public:
        Game_over(Puntaje* x);
        Text devo_text();
        Text devo_text(int x);
        Text devo_text(double x);

        virtual ~Game_over();

    private:
        Texto *game_over;
        std::string mensa_gover="GAME OVER";
        Texto *restart;
        std::string mensa_restart="Press TAB to restart";

        int *punt_max;
        Texto *punt_maxT;
        std::string mensa_punt_maxt="The highest score: ";

};

#endif // GAME_OVER_H
