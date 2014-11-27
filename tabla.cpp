 

#include "tabla.hpp"
//TABLERO    
tablero::tablero(int n, int m):
 tabla(NULL),
 automata(NULL),
 n_filas(n),
 n_columnas(m),
 fin_x(-1),
 fin_y(-1){
 
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
	  if(tabla[i][j]==NULL)
	   tabla[i][j]=new cuadrado_t(1); 
	}
      }
   
   
   
}
void tablero::mostrar_tablero(){
      cout<< "80"<< endl;
     for(int i=0;i<n_filas;i++){
	for(int j=0;j<n_columnas;j++){
	  cout<< "81"<< endl;
	  if(tabla[i][j]==NULL){
	    cout << "!|";
	  cout<< "82"<< endl;
	  }else if(tabla[i][j]->get_estado()==0){
	     cout << "X|";
	     cout<< "83"<< endl;
	  }else if(tabla[i][j]->get_estado()==1){
	     cout << "_|";
	     cout<< "84"<< endl;
	  }else if(tabla[i][j]->get_estado()==2){
	     cout << "A|";
	     cout<< "85"<< endl;
	  }else if(tabla[i][j]->get_estado()==3){
	     cout << "O|";
	     cout<< "86"<< endl;
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


 void  tablero::marcar_recorridoAutomata(){
   nodo_t auxiliar;
   
   cout << "gay1"<< endl;
   //auxiliar=
   cout <<automata;
   automata->RecEuristico( tabla,fin_x,fin_y,n_filas,n_columnas); 
   cout << "gay"<< endl;
   //for (int i=0;i <auxiliar.camino.size();i++)
     //tabla[auxiliar.camino.at(i).x][auxiliar.camino.at(i).y]->set_estado(4);
     
     
   //cout << "el coste acumulado es " << auxiliar.costo_estimado<< endl;  
     
   mostrar_tablero();
   
   
   
} 