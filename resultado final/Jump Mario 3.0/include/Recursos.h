#ifndef RECURSOS_H
#define RECURSOS_H

#include <string>
#include <list>
#include <iostream>

using namespace std;

class Recursos
{
    int value;

    public:
        Recursos();
        void reset();
        int getValue();
        void setValue(int number);
};

#endif // RECURSOS_H
