#include "celda.h"
/*En este archivo no hay mucho mas que explicar es la declaracion de la clase
 Celda con los metodos set y get*/
Celda::Celda():
    estado_celda_(-1)
{}
Celda::~Celda()
{}

int Celda::get_estado()
{
    return estado_celda_;
}

void Celda::set_estado(int x)
{
    if (x >=-1 && x <= 4)
        estado_celda_ = x;

}
