#include "Game_over.h"

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

//CLASES CREADAS
#include "Texto.h"
#include "Juego.h".

using namespace sf;

Game_over::Game_over()
{
    game_over=new Texto;
    game_over->mens_tam_pos(mensa_gover,189,35,200);
}

Text Game_over::devo_text()
{
    return game_over->dev_text();
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

/*void Game_over::restart()
{
    if(Mario->y>697)
    {
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            Juego->Mario->pos_iniciales();
            Juego->juego_fond->spr_fond->setColor(Juego->juego_fond->color1);
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            pantalla_de_juego->close();
            exit(1);
        }
    }
}*/

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

Game_over::~Game_over()
{
    //dtor
}
