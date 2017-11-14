#include "Game_over.h"

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

//CLASES CREADAS
#include "Juego.h".

Game_over::Game_over()
{
    fuente1=new Font;
    fuente1->loadFromFile("Fuentes/smb.ttf");
    Over=new Text();
    Over->setFont(*fuente1);
    Over->setString("GAME OVER");
    Over->setCharacterSize(189);
    Over->setPosition(35,200);

    /*if(Mario.y>697)
    {
        fps=0;
        spr_fondo->setColor(Color::Red);

    }*///ctor
}

Text Game_over::devo_text()
{
    return *Over;
}
Game_over::~Game_over()
{
    //dtor
}
