#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Juego
{
    public:
        Juego(int _ancho, int _alto,std::string _nombre);
        void gameloop();
        void mostrar();

    private:
        RenderWindow *ventana1;
        int fps;
};

#endif // JUEGO_H
