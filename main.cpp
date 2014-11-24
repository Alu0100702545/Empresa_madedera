

#include "tabla.hpp"
#include <iostream> 
#include <stdlib.h>  
int main(){
  int n,m,x,y,opcion,ran;
  bool opt=false;
  tablero *mapa;
  srand(time(NULL));
  cout << "Bienvenido al programa del Automata maderero " <<endl;
  
  cout << "Introduzca las dimensiones del mapa por favor " <<endl;
  cin >> n >>m;
  
  mapa= new tablero(n,m);
  do{
  cout << "Introduzca posicion inicial del automata " <<endl;
  cin >>x>>y;
      opt=mapa->introducir_automata(x,y);
  }while (opt==false );
  mapa->mostrar_tablero();
  do{
  cout << "Introduzca posicion inicial de la empresa " <<endl;
  cin >>x>>y;
      opt=mapa->introducir_empresa(x,y);
  }while (opt==false );
  mapa->mostrar_tablero();
  do{
  cout << "¿Como desea que se generen los arboles? 1 random , 0  manual" <<endl;
  cin >>opcion;
  }while (opcion>1 || opcion<0);
  if (opcion ==1){
   ran=rand()%(n*m -2);
   while (ran >0){
      x=rand()%n;
      y=rand()%m;
      opt=mapa->introducir_arboles(x,y);
      if(opt==true){
	ran--;
      }
    }
    
  }else{
    do{
  cout << "Introduzca posicion arbol " <<endl;
  cin >>x>>y;
  cout << "Desea introducir mas arboles? si= cualquier numero; no = 1 " <<endl;
  cin >>opcion;
      opt=mapa->introducir_arboles(x,y);
  }while ( opt==false || opcion != 1);
    
    
  }
  mapa->rellenar_paso_natural();
  mapa->mostrar_tablero();
  
return 0; 
  
}
