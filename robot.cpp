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
 /*
  En principio cualquier algoritmos que cojamos su solucion
  sera de tipo recursica, es decir que para saber que camino tenemos
  que cojer iremos llamando a la funcion segun en numero de posibles
  caminos que haya(hasta un maximo de 4 caminos(norte,sur, este, oeste)
  si existiera el caso) para maximizar el rendimiento usaremos una segunda( aun no
  implementada) que sera para saber que casillas han sido visitadas para no volver a
  recorrer caminos que ya hemos recorridos. Aun no he pensado como veremos cual
  es el caminos mas optimo ni como haremos para guardar las posiciones(posiblemente
  lo haremos con colas (queue) o listas.   
  */ 
}