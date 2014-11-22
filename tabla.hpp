#ifndef TABLA_H
#define TABLA_H

#include "robot.h"
class cuadrado_t{
    private:
      int estado_t;//0 robot, 1 paso_natural, 2 Arboles 3 Empresa 5 RecorridoAutomata
    public:
    cuadrado_t();
    ~cuadrado_t();
    int get_estado();
    void set_estado(int);
}  
class tablero{
    private:
      cuadrado_t **tabla;
      robot_t automata:
   public:
      tablero();
      ~tablero();
      void introducir_automata();
      void introducir_arboles();
      void introducir_empresa();
      void rellenar_paso_natural();
      void marcar_recorridoAutomata();    
     
} 






#endif // TABLA_H