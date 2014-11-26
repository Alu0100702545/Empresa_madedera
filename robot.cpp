

#include "robot.hpp"
//cuadrado_t
cuadrado_t::cuadrado_t(int estado):
 estado_t(estado){
    //CUADRADO
  //0 robot, 1 paso_natural, 2 Arboles 3 Empresa 4 RecorridoAutomata
   
}
 cuadrado_t::~cuadrado_t(){}
 int cuadrado_t::get_estado(){
   return estado_t;
}
 void cuadrado_t::set_estado(int N_estado){
   estado_t=N_estado;
   
}
//ROBOT




robot_t::robot_t(int x , int y):
  C_inicial_x(x),
  C_inicial_y(y),
  sensores(NULL){
    sensores= new int[4];    
    for(int i =0;i<4 ;i++){
      sensores[i]=0;
    }
    
  }
  
  
robot_t::robot_t():
  C_inicial_x(2),
  C_inicial_y(5),
  sensores(NULL){
    sensores= new int[4];    
    for(int i =0;i<4 ;i++){
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
bool compare_nodos (nodo n1, nodo n2)
{

  return ( n1.costo_estimado < n2.costo_estimado);
}



/*void robot_t::ordenarlista(list<nodo> *v){
  nodo aux;
  int ax,ax1
  //list<nodo>::iterator ax;
  //list<nodo>::iterator ax1;
  for(ax=1;ax<v->size(); ax++) {
    aux=v->at(i);
    ax1=i-1;
    while(ax1>=0 && aux <v->at(ax1)){
      v->at(ax1+1)=v->at(ax1);
      ax1--;
    }
   v->at(ax1+1)= aux
  }
  
  
  
}*/
void robot_t::RecEuristico(/*cuadrado_t*** square,int fin*/){
  list<nodo> abierta;
  list<nodo> cerrada;
  
  nodo aux;
  while (!abierta.empty() ||abierta.front().camino.at[0]==fin){
    aux=abierta.front();
    abierta.pop_front();
    cerrada.push_front(aux);
    //buscar y añadir las trayectorias
    if(){}
    elseif(){}
    elseif(){}
    elseif(){}
    else{}
    
    //ordenacion de la lista
    abierta.sort(compare_nodos);
    //eliminar duplicados de cerrada y abierta   
  }
  
 
  
}
int robot_t::manhattan(int inicio_x, int inicio_y,int fin_x ,int fin_y){
  return abs(inicio_x-fin_x)+abs(inicio_y-fin_y);
}




 /*  nodo n,n1;
  n.costo_estimado=6;
  abierta.push_front(n);
  n.costo_estimado=3;
  abierta.push_front(n);
  n.costo_estimado=5;
  abierta.push_front(n) ;
  n.costo_estimado=7;
  abierta.push_front(n) ;
  n.costo_estimado=4;
  abierta.push_front(n) ;
  
  n1=abierta.front();
  cout <<n1.costo_estimado;
  abierta.sort(compare_nodos);
   n1=abierta.front();
   cout <<n1.costo_estimado; 
  abierta.pop_front();
   n1=abierta.front();
   cout <<n1.costo_estimado; 
  abierta.pop_front();
   n1=abierta.front();
   cout <<n1.costo_estimado; 
  abierta.pop_front();
   n1=abierta.front();
   cout <<n1.costo_estimado; 
  abierta.pop_front();
  
    */

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