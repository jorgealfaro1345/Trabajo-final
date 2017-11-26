#include "Recursos.h"

#include <string>
#include <list>
#include <iostream>

using namespace std;

Recursos::Recursos()
{
    value = 0;
}

void Recursos::reset();
{
    value = 0;
}

int Recursos::getValue();
{
    return value;
}

void Recursos::setValue(int number);
{
    value = number;
}

Recursos::~Recursos()
{
    //dtor
}
