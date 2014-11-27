 

#include "tabla.hpp"
//TABLERO    
tablero::tablero(int n, int m):
 tabla_(NULL),
 automata(NULL),
 n_filas(n),
 n_columnas(m),
 fin_x(-1),
 fin_y(-1){
 
   tabla_ = new cuadrado_t*[n];
   for (int i=0;i<n;i++){
     tabla_[i]=new cuadrado_t[m];
  }
   
}
 tablero::~tablero(){
   // tabla = new tablero**[n];
   for (int i=0;i<n_filas;i++){
     //tabla[i]=new tablero*[m];
      delete tabla_[i];
   }
  delete [] tabla_; 
}
 bool  tablero::introducir_automata(int x,int y){
    if (x>=0 && x<n_filas && y>=0 && y<n_columnas ){
	tabla_[x][y].set_estado(0);
	automata=new robot_t(x,y);
	return true;
    }else{
      cout<< "busque otra posicion viable"<< endl;
    return false;
    }
}
 bool  tablero::introducir_arboles(int x, int y){
      if (x>=0 && x<n_filas && y>=0 && y<n_columnas && tabla_[x][y].get_estado()==-1){
	tabla_[x][y].set_estado(2);
	//automata=new robot_t(x,y);
	return true;
    }else{
      //cout<< "busque otra posicion viable"<< endl;
    return false;
    }
   
   
}
 bool  tablero::introducir_empresa(int x,int y){
     if (x>=0 && x<n_filas && y>=0 && y<n_columnas /*&& tabla_[x][y]==NULL */){
	tabla_[x][y].set_estado(3);
	//automata=new robot_t(x,y);
	fin_x=x;
        fin_y=y;
	return true;
    }else{
      cout<< "busque otra posicion viable"<< endl;
    return false;
    }
}
 void  tablero::rellenar_paso_natural(){
      for(int i=0;i<n_filas;i++){
	for(int j=0;j<n_columnas;j++){
	  if(tabla_[i][j].get_estado()==-1)
	   tabla_[i][j].set_estado(1); 
	}
      }
   
   
   
}
void tablero::mostrar_tablero(){
      cout<< "80"<< endl;
     /*for(int i=0;i<n_filas;i++){
	for(int j=0;j<n_columnas;j++){
	  
	  if(tabla_[i][j].get_estado()==-1)
	    cout << "!|";
	 
	  if(tabla_[i][j].get_estado()==0)
	     cout << "X|";
	     
	   if(tabla_[i][j].get_estado()==1)
	     cout << "_|";
	    
	  if(tabla_[i][j].get_estado()==2)
	     cout << "A|";
	     
	  if(tabla_[i][j].get_estado()==3)
	     cout << "O|";
	    
	  if(tabla_[i][j].get_estado()==4)
	    cout << "M|";
	    
	}
      cout<< endl;
      for(int p=0;p<n_columnas;p++)
	  cout << "- ";
      cout<< endl; 
     }*/
     
     cout << tabla_[2][2].get_estado();
    
}


 void  tablero::marcar_recorridoAutomata(){
   nodo_t auxiliar;
  automata->RecEuristico(tabla_,fin_x,fin_y,n_filas,n_columnas); 
   //cout << "gay"<< endl;
   //for (int i=0;i <auxiliar.camino.size();i++)
     //tabla[auxiliar.camino.at(i).x][auxiliar.camino.at(i).y]->set_estado(4);
     
     
   //cout << "el coste acumulado es " << auxiliar.costo_estimado<< endl;  
     
  
   
   
   
} 