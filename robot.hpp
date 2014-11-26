#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
#include <list>
#include <vector>
#include <stdlib.h> 
#include <cmath>
using namespace std;
struct nodo{
    vector <int> camino;
    int costo_estimado;
  
};

class cuadrado_t{
    private:
      int estado_t;
      int posicion;
      //0 robot, 1 paso_natural, 2 Arboles 3 Empresa 5 RecorridoAutomata
    public:
    cuadrado_t(int);
    ~cuadrado_t();
    int get_estado();
    void set_estado(int);
};  

class robot_t{
    
    private:
      int C_inicial_x;
      int C_inicial_y;
      int *sensores;
    public:
      robot_t(int, int );
      robot_t();
      ~robot_t();
      int get_X();
      int get_Y();
      void ordenarlista(list<nodo> *v);
      void RecEuristico(/*cuadrado_t*** square, int*/);
      int manhattan(int inicio_x, int inicio_y,int fin_x ,int fin_y);
};

#endif // ROBOT_H