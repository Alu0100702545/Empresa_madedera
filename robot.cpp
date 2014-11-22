robot_t::robot_t(int x , int y):
  C_inicial_x(x),
  C_inicial_y(y),
  sensores(NULL){
    sensores= new int[4];    
    for(int i =0;i<4 i++){
      sensores[i]=0;
    }
    
  }
      
robot_t::~robot_t(){
  delete [] sensores;
}

int robot_t::get_X(){
    return  C_inicial_x;
}

int robot_t::get_Y(){
    return C_inicial_y;
}

void robot_t::RecEuristico(cuadrado_t** ){
  
}