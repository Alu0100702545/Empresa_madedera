

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
      sensores[i]=-1;
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
bool compare_nodos (nodo_t n1, nodo_t n2)
{

  return ( n1.costo_estimado < n2.costo_estimado);
}




nodo_t robot_t::RecEuristico(cuadrado_t*** square,int fin_x,int fin_y,int nfilas,int ncolumnas ){
  
  
  cout<<"puta6";
  /*
   
  
  list<nodo_t> abierta;
  list<nodo_t> cerrada;
   cout<<"puta5";
  nodo_t aux,aux2,defaul,inicio;
  defaul.costo_estimado=-50;
  posicion p1;
  p1.x=C_inicial_x;
  p1.y=C_inicial_y;
  cout<<"puta4";
  inicio.camino.push_back(p1);
  inicio.costo_estimado=manhattan(p1.x,p1.y,fin_x,fin_y);
  
  abierta.push_front(inicio);
  cout<<"puta4";
  while (!abierta.empty() ||(abierta.front().camino.at(abierta.front().camino.size()-1).x==fin_x && abierta.front().camino.at(abierta.front().camino.size()-1).y==fin_y)){
    aux=abierta.front();
    abierta.pop_front();
    cerrada.push_front(aux);
    //buscar y añadir las trayectorias
    cout<<"puta1";
   if(inicializar_sensores(aux, nfilas,ncolumnas, square)) {
    if(sensores[1]==0 && (aux.camino.at(aux.camino.size()-1).y !=aux.camino.at(aux.camino.size()-2).y || aux.camino.at(aux.camino.size()-1).x+1 !=aux.camino.at(aux.camino.size()-2).x)){
      aux2=aux;
      p1.x=aux.camino.at(aux.camino.size()-1).y; 
      p1.y=aux.camino.at(aux.camino.size()-1).x +1;
      aux2.camino.push_back(p1);
      aux2.costo_estimado+=manhattan(p1.x,p1.y,fin_x,fin_y);
      
    }
    if(sensores[0]==0 &&(aux.camino.at(aux.camino.size()-1).y !=aux.camino.at(aux.camino.size()-2).y || aux.camino.at(aux.camino.size()-1).x-1 !=aux.camino.at(aux.camino.size()-2).x)){
      aux2=aux;
      p1.x=aux.camino.at(aux.camino.size()-1).y; 
      p1.y=aux.camino.at(aux.camino.size()-1).x -1;
      aux2.camino.push_back(p1);
      aux2.costo_estimado+=manhattan(p1.x,p1.y,fin_x,fin_y);
    }
    cout<<"puta2";
    if(sensores[3]==0&&(aux.camino.at(aux.camino.size()-1).y-1 !=aux.camino.at(aux.camino.size()-2).y || aux.camino.at(aux.camino.size()-1).x !=aux.camino.at(aux.camino.size()-2).x)){
      aux2=aux;
      p1.x=aux.camino.at(aux.camino.size()-1).y-1; 
      p1.y=aux.camino.at(aux.camino.size()-1).x;
      aux2.camino.push_back(p1);
      aux2.costo_estimado+=manhattan(p1.x,p1.y,fin_x,fin_y);
    }
    if(sensores[2]==0&&(aux.camino.at(aux.camino.size()-1).y+1 !=aux.camino.at(aux.camino.size()-2).y || aux.camino.at(aux.camino.size()-1).x !=aux.camino.at(aux.camino.size()-2).x)){
      aux2=aux;
      p1.x=aux.camino.at(aux.camino.size()-1).y+1; 
      p1.y=aux.camino.at(aux.camino.size()-1).x;
      aux2.camino.push_back(p1);
      aux2.costo_estimado+=manhattan(p1.x,p1.y,fin_x,fin_y);
    }
    cout<<"puta";
    //ordenacion de la lista
    abierta.sort(compare_nodos);
    //eliminar duplicados de cerrada y abierta   
    }else
      abierta.pop_front();
      
    
  }
  if(abierta.front().camino.at(abierta.front().camino.size()-1).x==fin_x && abierta.front().camino.at(abierta.front().camino.size()-1).y==fin_y){
    cout <<"camino optimo encontrado"<<endl;
    
    return abierta.front();
  }else 
    cout <<"no se ha encontrado ningun camino"<< endl;
    return defaul;
  */
}
bool robot_t::inicializar_sensores(nodo_t n, int nfilas,int ncolumnas,cuadrado_t*** square){
  //int aux=nodo.camino.at[0].x;
  /*
   Con esta funcion contemplo para que no se salga del tablado marcado con -1
   
   */
  if (n.camino.at(n.camino.size()-1).x+1 < nfilas &&n.camino.at(n.camino.size()-1).y < ncolumnas){
    if (square[n.camino.at(n.camino.size()-1).x+1][n.camino.at(n.camino.size()-1).y]->get_estado()==2)
      sensores[1]=1;
    else
      sensores[1]=0;
  }else
      sensores[1]=-1;
  if (n.camino.at(n.camino.size()-1).x-1 < nfilas &&n.camino.at(n.camino.size()-1).y < ncolumnas){
    if (square[n.camino.at(n.camino.size()-1).x-1][n.camino.at(n.camino.size()-1).y]->get_estado()==2)
      sensores[0]=1;
    else
      sensores[0]=0;
  }else
      sensores[0]=-1;
  if (n.camino.at(n.camino.size()-1).x < nfilas && n.camino.at(n.camino.size()-1).y-1 < ncolumnas){
    if (square[n.camino.at(n.camino.size()-1).x][n.camino.at(n.camino.size()-1).y-1]->get_estado()==2)
      sensores[3]=1;
    else
      sensores[3]=0;
  }else
      sensores[3]=-1;
  if (n.camino.at(n.camino.size()-1).x < nfilas &&n.camino.at(n.camino.size()-1).y+1 < ncolumnas){
    if (square[n.camino.at(n.camino.size()-1).x][n.camino.at(n.camino.size()-1).y+1]->get_estado()==2)
      sensores[2]=1;
    else
      sensores[2]=0;
  }else
      sensores[3]=-1;
  int sum=abs(sensores[0])+abs(sensores[1])+abs(sensores[2])+abs(sensores[3]);
 return sum < 3;
  
  
  
}
int robot_t::manhattan(int inicio_x, int inicio_y,int fin_x ,int fin_y){
  return abs(inicio_x-fin_x)+abs(inicio_y-fin_y);
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