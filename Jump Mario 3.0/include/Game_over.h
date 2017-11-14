#ifndef GAME_OVER_H
#define GAME_OVER_H

//LIBRERIAS DE SFML
#include<SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

//CLASES CREADAS
#include "Texto.h"
//#include "Juego.h".

using namespace sf;

class Game_over
{
    public:
        Game_over();
        Text devo_text();
        //void restart();
        virtual ~Game_over();

    private:
        Texto *game_over;
        std::string mensa_gover="GAME OVER";

};

#endif // GAME_OVER_H
