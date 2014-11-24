#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
using namespace std;

class robot_t{
    
    private:
      int C_inicial_x;
      int C_inicial_y;
      int *sensores;
    public:
      robot_t(int, int );
      ~robot_t();
      int get_X();
      int get_Y();
      void RecEuristico(/*cuadrado_t** */);
};

#endif // ROBOT_H