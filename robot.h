#ifndef ROBOT_H
#define ROBOT_H
#include <QDebug>
#include <QList>
#include <QVector>
#include <QLabel>
#include <stdlib.h>
#include <cmath>
#include "celda.h"

/* Creamos dos estructuras:
    La estructura posicion es la que se encargara de guardar una posicion concreta de
    nuestro mapa
    La segundo estructura se encarga de ir guardando uno de los muchos caminos que puede haber
    en una lista. Esta compuesta por un vector de struct posicion y el coste estimado de dicho
    camino
*/

struct Posicion{
    int x;
    int y;

};

struct Nodo{
    QVector <Posicion> camino;
    int costo_estimado;

};
/*La clase Robot esta compuesta por:
    Variables:
        * Posicion inicial(X)
        * Posicion inicial(Y)
        * Posicion Actual(X)
        * Posicion Actual(Y)
        * Un puntero de sensores(se iniciara como una array de 4 elementos la
            cual indicara el norte, el sur ,el este y el oeste respectivamente)
*/
/*Las funciones estan explicadas en el cpp que tiene el mismo nombre*/

class Robot
{
   private:

     int C_inicial_x_;
     int C_inicial_y_;
     int actual_x_;
     int actual_y_;
     int *sensores_;
// Label que se mostrará en el menu principal con la información del robot
     QLabel *informacion_;

   public:

     Robot(int, int,QLabel* =NULL);
     ~Robot();
     int get_X_ini();
     int get_Y_ini();
     int get_X();
     int get_Y();
     void set_X_ini(int );
     void set_Y_ini(int );
     void set_X(int);
     void set_Y(int);
     bool inicializar_sensores(Nodo n, int nfilas,int ncolumnas,Celda** square);
     Nodo RecEuristico(Celda** square,int fin_x,int fin_y,int nfilas,int ncolumnas);
     int manhattan(int inicio_x, int inicio_y,int fin_x ,int fin_y);
     bool is_outrange(int x, int y,int nfilas,int ncolumnas);
     bool del_duplicate(Nodo n,QList<Nodo> &abierta);
     bool del_duplicate_dual(Nodo n,QList<Nodo> &cerrada);
     bool is_invector(Nodo n, int x, int y);
};

#endif // ROBOT_H
