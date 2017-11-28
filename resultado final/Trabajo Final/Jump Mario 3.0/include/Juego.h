#ifndef JUEGO_H
#define JUEGO_H

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <vector>

//CLASE CREADA
#include "Plataformas.h"
#include "Personaje.h"
#include "Game_over.h"
#include "Enemigos.h"
#include "Fondo.h"
#include "Sonidos.h"
#include "Puntaje.h"


using namespace sf;

class Juego
{
    public:

        Juego(int _ancho, int _alto,std::string _nombre, int pers);
        void mostrar_and_setposicion();
        void iniciar_eventos();
        void gameloop();

        ~Juego();

    protected:

        RenderWindow *pantalla_de_juego;
        Event *evento1;
        Fondo *juego_fond;

        Plataformas *plat_ladrillos;
        int pers;
        int pers2;
        Personaje *personaje;
        Color *spr_color;

        Enemigos  *enem1;
        Enemigos  *enem2;
        Enemigos  *enem3;
        Enemigos  *enem4;
        Enemigos  *enem5;
        Enemigos  *enem6;
        Enemigos  *enem7;
        Enemigos  *enem8;
        std::vector<Enemigos *> enemigos;

        Game_over *G_over;
        Puntaje *puntos;

        Clock *reloj;
        float *tiempo;
        std::string tiempo1;
        Texto *reloj1;
};

#endif // JUEGO_H
