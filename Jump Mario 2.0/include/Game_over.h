#ifndef GAME_OVER_H
#define GAME_OVER_H

//LIBRERIAS DE SFML
#include<SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include <iostream>
using namespace sf;

class Game_over
{
    public:
        Game_over();
        virtual ~Game_over();
        Text devo_text();

    private:
        Font *fuente1;
        Text *Over;

    protected:
};

#endif // GAME_OVER_H
