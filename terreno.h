#ifndef TERRENO_H
#define TERRENO_H
#include "celda.h"
#include "robot.h"
#include "stdio.h"
#include "qdebug.h"
#include <QString>
#include <QLabel>

/*La clase Terreno esta compuesta por:
    Variables:
        * Posicion final(X)(empresa madedera)
        * Posicion final(Y)
        * Numero de Columnas(dimension Y del terreno)
        * Numero de filas(Dimension X del terreno)
        * Un puntero doble de Celdas(La cual se iniciara como un vector de punteros Celda
           de dimension "Numero de filas" y en cada puntero Celda se creara un vector de
           dimensiones "Numero de Columnas)
        * Un puntero simple de la clase Robot( La cual se iniciara al colocar su posicion
          en el Terreno)
        * QLabel que se utilizará para mostrar la información del tablero
*/


/*Las funciones estan explicadas en el cpp que tiene el mismo nombre*/

using namespace std;
class Terreno
{
private:
    Celda   **tabla_;
    Robot   *automata_;
    int n_filas_;
    int n_columnas_;
    int fin_x_;
    int fin_y_;
    //
    QLabel *informacion_;

public:
    Terreno(int,int,QLabel* = NULL);
    ~Terreno();
    bool introducir_automata(int,int);
    bool introducir_arboles(int,int);
    bool introducir_empresa(int,int);
    bool introducir_terreno(int,int);
    void rellenar_paso_natural();
    void marcar_recorridoAutomata();
    void mostrar_tablero();
    int obtenerElementoTablero(int,int)const;
    int obtenerPosxrobot(void) const;
    int obtenerPosyrobot(void) const;
    int obtenerPosxiniciorobot(void)const;
    int obtenerPosyiniciorobot(void)const;
    int obtenerPosxFinalrobot(void)const;
    int obtenerPosyFinalrobot(void)const;
    void asignarPosFinal(int x,int y);
    void asignarPosInicio(int x,int y);
};

#endif // TERRENO_H
