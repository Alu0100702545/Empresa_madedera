

#include "robot.hpp"
//cuadrado_t
cuadrado_t::cuadrado_t():
 estado_t(-1){
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
bool delet_nodos(nodo_t n1, nodo_t n2){
	int x1=n1.camino.at(n1.camino.size() - 1).x;
	int y1=n1.camino.at(n1.camino.size() - 1).y;
	int x2=n2.camino.at(n2.camino.size() - 1).x;
	int y2=n2.camino.at(n2.camino.size() - 1).y;
	int costo1=n1.costo_estimado;
	int costo2=n2.costo_estimado;
	return(x1==x2&& y1==y2 && costo1 >costo2);
}




nodo_t robot_t::RecEuristico(cuadrado_t** square,int fin_x,int fin_y,int nfilas,int ncolumnas ){
  list<nodo_t> abierta;
  list<nodo_t> cerrada;
  //int sz = abierta.size();
  bool algo,algo2;
  nodo_t aux,aux2,defaul,inicio;
  defaul.costo_estimado=-50;
  posicion p1;
  p1.x=C_inicial_x;
  p1.y=C_inicial_y;
  inicio.camino.push_back(p1);
  inicio.costo_estimado=manhattan(p1.x,p1.y,fin_x,fin_y);
  //int xini=abierta.front().camino.at(abierta.front().camino.size()-1).x;
  //int yini=abierta.front().camino.at(abierta.front().camino.size()-1).y;
  abierta.push_front(inicio);
do{
    aux=abierta.front();
    abierta.pop_front();
    //sz = abierta.size();
    cerrada.push_front(aux);

    int yy = aux.camino.at(aux.camino.size() - 1).y;
    int xx= aux.camino.at(aux.camino.size()-1).x;
    //buscar y añadir las trayectorias
   if(inicializar_sensores(aux, nfilas,ncolumnas, square)) {
	   //int yy2= aux.camino.at(aux.camino.size()-2).y;
  	   //int xx2= aux.camino.at(aux.camino.size()-2).x;
	   //int yy2= aux.camino.at(aux.camino.size()-2).y;
	   //int xx2= aux.camino.at(aux.camino.size()-2).x;

	   if(sensores[1]==0){

			   if(is_invector(aux, xx+1, yy)==false){
				   aux2=aux;
			   	   p1.x=xx+1;
			   	   p1.y=yy;
			   	   aux2.camino.push_back(p1);
			   	   aux2.costo_estimado+=manhattan(p1.x,p1.y,fin_x,fin_y);
			   	   abierta.push_front(aux2);
			   }
	   }
	   if(sensores[0]==0){

			   if(is_invector(aux, xx-1, yy)==false){
				   aux2=aux;
			   	   p1.x=xx-1;
			   	   p1.y=yy;
			   	   aux2.camino.push_back(p1);
			   	   aux2.costo_estimado+=manhattan(p1.x,p1.y,fin_x,fin_y);
			   	   abierta.push_front(aux2);
			   }
	   }

	   if(sensores[3]==0){
		    if(is_invector(aux, xx, yy-1)==false){
				   aux2=aux;
			   	   p1.x=xx;
			   	   p1.y=yy-1;
			   	   aux2.camino.push_back(p1);
			   	   aux2.costo_estimado+=manhattan(p1.x,p1.y,fin_x,fin_y);
			   	   abierta.push_front(aux2);
			}
	   }
	   if(sensores[2]==0){
		     if(is_invector(aux, xx, yy+1)==false){
				   aux2=aux;
			   	   p1.x=xx;
			   	   p1.y=yy+1;
			   	   aux2.camino.push_back(p1);
			   	   aux2.costo_estimado+=manhattan(p1.x,p1.y,fin_x,fin_y);
			   	   abierta.push_front(aux2);
		     }
	   }


		   abierta.sort(compare_nodos);
		  // if(abierta.size()>4)
		      //peores_espectativas(abierta);

		   do{
			if (!abierta.empty()){
			 aux=abierta.front();
			 abierta.pop_front();
			 algo=del_duplicate(aux, abierta);
			 abierta.push_front(aux);
			}
		  }while(algo==true);
		   do{
		   	if (!abierta.empty()){
		   		aux=abierta.front();
		   		abierta.pop_front();
		   		algo2=del_duplicate_dual(aux, cerrada);
		   		if (algo2 ==false)
		   			abierta.push_front(aux);
		   	}
		   }while(algo2==true);



    }else{
    	//mirar la lista por si esta vacio
    	//algo= abierta.empty();
    	if (!abierta.empty())
    		abierta.pop_front();

    }

  } while (!abierta.empty() &&(abierta.front().camino.at(abierta.front().camino.size()-1).x !=fin_x || abierta.front().camino.at(abierta.front().camino.size()-1).y!=fin_y));

  if(!abierta.empty() && abierta.front().camino.at(abierta.front().camino.size()-1).x==fin_x && abierta.front().camino.at(abierta.front().camino.size()-1).y==fin_y){
    cout <<"camino optimo encontrado"<<endl;
    
    return abierta.front();
  }else{
    cout <<"no se ha encontrado ningun camino"<< endl;
    return defaul;
  }
}
bool robot_t::inicializar_sensores(nodo_t n, int nfilas,int ncolumnas,cuadrado_t** square){
  //int aux=nodo.camino.at[0].x;
  /*
   Con esta funcion contemplo para que no se salga del tablado marcado con -1
   
   */

	bool algo;
	int xx = n.camino.at(n.camino.size()-1).x;
    int yy = n.camino.at(n.camino.size()-1).y;
  if (!is_outrange(xx+1,yy,nfilas,ncolumnas)){
    if (square[xx+1][yy].get_estado()!=2)
      sensores[1]=0;
    else
      sensores[1]=1;
  }else
      sensores[1]=-1;

  if (!is_outrange(xx-1,yy,nfilas,ncolumnas)){
	  if (square[xx-1][yy].get_estado()!=2)
      sensores[0]=0;
    else
      sensores[0]=1;
  }else
      sensores[0]=-1;
  if (!is_outrange(xx,yy-1,nfilas,ncolumnas)){
    if (square[xx][yy-1].get_estado()!=2)
      sensores[3]=0;
    else
      sensores[3]=1;
  }else
      sensores[3]=-1;
  if (!is_outrange(xx,yy+1,nfilas,ncolumnas)){
    if (square[xx][yy+1].get_estado()!=2)
      sensores[2]=0;
    else
      sensores[2]=1;
  }else
      sensores[2]=-1;
  int sum=abs(sensores[0])+abs(sensores[1])+abs(sensores[2])+abs(sensores[3]);
 return sum <4;
  
  
  
}


void robot_t::peores_espectativas(list<nodo_t> &abierta){
	//int count=1;
	nodo_t aux,aux2;
	aux=abierta.back();
	aux2=abierta.back();
	while(aux2.costo_estimado==aux.costo_estimado && abierta.size()>4){
		abierta.pop_back();
		aux2=abierta.back();
	}

}

int robot_t::manhattan(int inicio_x, int inicio_y,int fin_x ,int fin_y){
  return abs(inicio_x-fin_x)+abs(inicio_y-fin_y);
}

bool robot_t::is_outrange(int x,int y,int nfilas,int ncolumnas){
	return x<0 || y<0 || x >= nfilas || y >= ncolumnas;
}
bool robot_t::is_invector(nodo_t n, int x, int y){
if(!n.camino.empty()){
	for (unsigned int i=0;i < n.camino.size();i++){
		if(n.camino.at(i).x ==x && n.camino.at(i).y==y){
			return true;
		}
	}
	return false;
}
return false;


}

bool robot_t::del_duplicate(nodo_t n ,list<nodo_t> &abierta){
list<nodo_t> ::iterator open;
int x,xx, y,yy;
x=n.camino.at(n.camino.size()-1).x;
y=n.camino.at(n.camino.size()-1).y;
//.camino.at(abierta.front().camino.size()-1).x=
nodo_t aux;
	for (open=abierta.begin();open !=abierta.end();open++){
			aux=*open;
			xx=aux.camino.at(aux.camino.size()-1).x;
			yy=aux.camino.at(aux.camino.size()-1).y;
		if (x==xx && y==yy){
			abierta.erase(open);
			return true;
		}
	}
	return false;
}
void robot_t::busqueda_duplicate(nodo_t n ,list<nodo_t> &abierta){
	list<nodo_t> ::iterator open;
	int x,xx, y,yy;
	nodo_t aux;
	x=n.camino.at(n.camino.size()-1).x;
	y=n.camino.at(n.camino.size()-1).y;
	int count=0;
	for (open=abierta.begin();open !=abierta.end();open++){
				aux=*open;
				xx=aux.camino.at(aux.camino.size()-1).x;
				yy=aux.camino.at(aux.camino.size()-1).y;
			if (x==xx && y==yy){
				count++;
			}
	}
	for (int i=0;i<count;i++)
		del_duplicate(n,abierta);




}
bool robot_t::del_duplicate_dual(nodo_t n,list<nodo_t> &cerrada){
	list<nodo_t> ::iterator close;
	int x,xx, y,yy, coste,coste1;
	//.camino.at(abierta.front().camino.size()-1).x=
	x=n.camino.at(n.camino.size()-1).x;
	y=n.camino.at(n.camino.size()-1).y;
	coste1=n.costo_estimado;
	nodo_t aux;
		for (close=cerrada.begin();close !=cerrada.end();close++){
				aux=*close;
				xx=aux.camino.at(aux.camino.size()-1).x;
				yy=aux.camino.at(aux.camino.size()-1).y;
				coste=aux.costo_estimado;
				if (x==xx && y==yy && coste <coste1){
					return true;
				}

		}
		return false;
}



