#ifndef JUEGO_H
#define JUEGO_H

//CLASE CREADA
#include "Enemigos.h"
#include "Goombas.h"

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

//CLASE CREADA
#include "Plataformas.h"
#include "Personaje.h"
#include "Game_over.h"
#include "Enemigos.h"
#include "Fondo.h"

using namespace sf;

class Juego
{
    public:

        Juego(int _ancho, int _alto,std::string _nombre);
        ~Juego();
        void mostrar_and_setposicion();
        void iniciar_eventos();
        void gameloop();
        void Game_Over();

    protected:

        RenderWindow *pantalla_de_juego;
        int fps;
        Event *evento1;

        Fondo *juego_fond;
        std::string nombre_carpeta="Fondo";
        std::string nombre_fondo="Fondo1";

        Plataformas *plat_ladrillos;

        Personaje *Mario;

        Enemigos  *enem1;
        int cant_enem;

        Game_over *G_over;

        /*SoundBuffer buffer_fondo;
        Sound sonido;
        Music fondo;*/

};

#endif // JUEGO_H
