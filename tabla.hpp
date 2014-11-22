#ifndef TABLA_H
#define TABLA_H

#include "robot.h"
class cuadrado_t{
    private:
      int estado_t;//0 robot, 1 paso_natural, 2 Arboles 3 Empresa 5 RecorridoAutomata
    public:
    cuadrado_t(int);
    ~cuadrado_t();
    int get_estado();
    void set_estado(int);
};  
class tablero{
    private:
      cuadrado_t ***tabla;
      robot_t *automata:
      int n_filas;
      int n_columnas;
   public:
      tablero();
      ~tablero();
      bool introducir_automata(int,int);
      bool introducir_arboles(int,int);
      bool introducir_empresa(int,int);
      void rellenar_paso_natural();
      void marcar_recorridoAutomata();    
     
} ;






#endif // TABLA_H