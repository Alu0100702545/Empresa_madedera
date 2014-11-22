#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
using namespace std;

class robot_t{
    
    private:
      int C_inicial_x;
      int C_inicial_y;
    public:
      robot_t();
      ~robot_t();
      int get_X();
      int get_Y();
      void RecEuristico();
}

#endif // ROBOT_H