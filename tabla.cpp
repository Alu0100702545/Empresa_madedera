 
 //CUADRADO
  //0 robot, 1 paso_natural, 2 Arboles 3 Empresa 4 RecorridoAutomata
#include "tabla.hpp"
 cuadrado_t::cuadrado_t(int estado):
 estado_t(estado){
   
   
}
 cuadrado_t::~cuadrado_t(){}
 int cuadrado_t::get_estado(){
   return estado_t;
}
 void cuadrado_t::set_estado(int N_estado){
   estado_t=N_estado;
   
}
//TABLERO    
tablero::tablero(int n, int m):
 tabla(NULL),
 automata(NULL),
 n_filas(n),
 n_columnas(m){
 
   tabla = new cuadrado_t**[n];
   for (int i=0;i<n;i++){
     tabla[i]=new cuadrado_t*[m];
  }
   
}
 tablero::~tablero(){
   // tabla = new tablero**[n];
   for (int i=0;i<n_filas;i++){
     //tabla[i]=new tablero*[m];
      delete tabla[i];
   }
  delete [] tabla; 
}
 bool  tablero::introducir_automata(int x,int y){
    if (x>=0 && x<n_filas && y>=0 && y<n_columnas && tabla[x][y]==NULL){
	tabla[x][y]=new cuadrado_t(0);
	automata=new robot_t(x,y);
	return true;
    }else{
      cout<< "busque otra posicion viable"<< endl;
    return false;
    }
}
 bool  tablero::introducir_arboles(int x, int y){
      if (x>=0 && x<n_filas && y>=0 && y<n_columnas && tabla[x][y]==NULL){
	tabla[x][y]=new cuadrado_t(2);
	//automata=new robot_t(x,y);
	return true;
    }else{
      //cout<< "busque otra posicion viable"<< endl;
    return false;
    }
   
   
}
 bool  tablero::introducir_empresa(int x,int y){
     if (x>=0 && x<n_filas && y>=0 && y<n_columnas && tabla[x][y]==NULL ){
	tabla[x][y]=new cuadrado_t(3);
	//automata=new robot_t(x,y);
	return true;
    }else{
      cout<< "busque otra posicion viable"<< endl;
    return false;
    }
}
 void  tablero::rellenar_paso_natural(){
      for(int i=0;i<n_filas;i++){
	for(int j=0;j<n_columnas;j++){
	  if(tabla[i][j]==NULL)
	   tabla[i][j]=new cuadrado_t(1); 
	}
      }
   
   
   
}
void tablero::mostrar_tablero(){
      
     for(int i=0;i<n_filas;i++){
	for(int j=0;j<n_columnas;j++){
	  
	  if(tabla[i][j]==NULL){
	    cout << "!|";
	  
	  }else if(tabla[i][j]->get_estado()==0){
	     cout << "X|";
	  }else if(tabla[i][j]->get_estado()==1){
	     cout << "_|";
	  }else if(tabla[i][j]->get_estado()==2){
	     cout << "A|";
	  }else if(tabla[i][j]->get_estado()==3){
	     cout << "O|";
	  }else if(tabla[i][j]->get_estado()==4){
	    cout << "M|";
	  }  
	}
      cout<< endl;
      for(int j=0;j<n_columnas;j++)
	  cout << "- ";
      cout<< endl; 
     }
    
}


 void  tablero::marcar_recorridoAutomata(){} 