#ifndef PLATAFORMAS_H
#define PLATAFORMAS_H
#include<SFML/System.hpp>
#include <SFML/Graphics.hpp>


class Plataformas
{
    public:
        Plataformas();

    private:
        Texture *textura3;
        Sprite *sprite3;
        struct point{ int x,y;};
        int x=280,y=615,h=0;
        float dx=0,dy=0,dp=0;
};

#endif // PLATAFORMAS_H
