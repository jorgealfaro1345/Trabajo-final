#include "Juego.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Juego::Juego(int _ancho, int _alto,std::string _nombre)
{
    fps=60;

    ventana1 = new RenderWindow(VideoMode(_ancho,_alto), _nombre);

    ventana1-> setFramerateLimit(fps);

//creacion de terturas

    textura1 = new Texture;

    textura2 = new Texture;

    textura3 = new Texture;

//creacion de sprites

    sprite1 = new Sprite;

    sprite2 = new Sprite;

    sprite3 = new Sprite;

//carga una imagen a la textura

    textura1->loadFromFile("1.png");

    textura2->loadFromFile("2.png");

    textura3->loadFromFile("3.png");

// almacena el sprite en la textura

    sprite1->setTexture(*textura1);

    sprite2->setTexture(*textura2);

    sprite3->setTexture(*textura3);

    point plat[20];

    for (int i=0;i<10;i++)
      {
       plat[i].x=rand()%400;
       plat[i].y=rand()%533;
      }

//posiciones de inicio de los sprite

    sprite1->setPosition(0,0);

    //sprite2->setPosition(280,615);

    sprite2->setPosition(x+dx,y+dy);

    for (int i=0;i<10;i++)
      {
        sprite3->setPosition(plat[i].x,plat[i].y);
      }

/*     sprite3->setPosition(200,350);*/

    evento1 = new Event;


//inicia el bucle del juego

    gameloop();//ctor
}

void Juego::gameloop()
{
    while(ventana1->isOpen())
    {
        //agregar_movimiento();
        iniciar_eventos();
        mostrar();
    }

}



void Juego::mostrar()
{
    ventana1->clear();

    ventana1->draw(*sprite1);

    ventana1->draw(*sprite2);

    ventana1->draw(*sprite3);

    ventana1->display();

}

void Juego::iniciar_eventos()
{
    dy+=0.2;
    y+=dy;
    dx+=0.2;
    if (y>500)  dy=-10;

	if (y<h)
    for (int i=0;i<10;i++)
    {
      y=h;
      plat[i].y=plat[i].y-dy;
      if (plat[i].y>533) {plat[i].y=0; plat[i].x=rand()%400;}
    }

	for (int i=0;i<10;i++)
    if ((x+50>plat[i].x) && (x+20<plat[i].x+68) && (y+70>plat[i].y) && (y+70<plat[i].y+14) && (dy>0))  dy=-10;


    while(ventana1->pollEvent(*evento1))
    {
        switch(evento1->type)
        {
        case Event::Closed:
            ventana1->close();
            exit(1);
            break;

        case Event::KeyPressed:
            if(Keyboard::isKeyPressed(Keyboard::Left))
            {
                sprite2->setPosition(sprite2->getPosition().x - dx  ,sprite2->getPosition().y);
            }
            else if(Keyboard::isKeyPressed(Keyboard::Right))
            {
                sprite2->setPosition(sprite2->getPosition().x + dx ,sprite2->getPosition().y);
            }

        }
        sprite2->setPosition(x,y);
    }

}


/*void Juego::agregar_movimiento()
{
    dy+=0.2;
    y+=dy;
    if (y>500)  dy=-10;

	if (y<h)
    for (int i=0;i<10;i++)
    {
      y=h;
      plat[i].y=plat[i].y-dy;
      if (plat[i].y>533) {plat[i].y=0; plat[i].x=rand()%400;}
    }

	for (int i=0;i<10;i++)
    if ((x+50>plat[i].x) && (x+20<plat[i].x+68) && (y+70>plat[i].y) && (y+70<plat[i].y+14) && (dy>0))  dy=-10;

	sprite2->setPosition(x,y);

}

*/
