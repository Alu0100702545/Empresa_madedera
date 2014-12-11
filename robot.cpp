#include "robot.h"
/*
Esta funcion realiza la creacion del robot otorgandole una posicion inicial
e inicializando los sensores a una array de 4(ya explicado) y poniendolos a 0
*/
Robot:: Robot(int x, int y,QLabel* informacion):
  C_inicial_x_(x),
  C_inicial_y_(y),
  actual_x_(x),
  actual_y_(y),
  informacion_(informacion),
  sensores_(NULL){
    sensores_ = new int[4];
    if(sensores_!=NULL)
    {
        for(int i =0;i<4 ;i++){
            sensores_[i]=0;
        }
    }
    else
    {
        if(informacion_ != NULL)
            informacion_->setText( "No se ha podido reservar la memoria para los sensores");
    }

  }

Robot::~Robot(){
  delete [] sensores_;
}

int Robot::get_X(){
    return  actual_x_;
}

int Robot::get_Y(){

    return actual_y_;

}
int Robot::get_X_ini()
{
    return C_inicial_x_;
}
int Robot::get_Y_ini()
{
    return C_inicial_y_;
}
void Robot::set_X(int x)
{
    this->actual_x_ = x;
}

void Robot::set_Y(int y)
{
    this->actual_y_ = y;
}
void Robot::set_X_ini(int x)
{
    this->C_inicial_x_ = x;
}
void Robot::set_Y_ini(int y)
{
    this->C_inicial_y_ = y;

}
/*
La funcion "inicializar_sensores" es clave para el desarrollo del algoritmo.
Se encarga de buscar las distintas trayectorias a partir de la ultima posicion
de nuestra estructura nodo. Para ello tiene 3 estados posibles:
    * 0 Posicion valida.
    * 1 Posicion invalida debido a que hay un obstaculo(arboles)
    * -1 Posicion invalidad debido a que esta fuera del rango del terreno establecido
Al final de esta funcion devolvera un booleano el cual mandara un true cuando la suma
del valor absoluto de los 4 sensores es menor que 4, esto indica que al menos uno de los
sensores es 0 por lo que a partir de esa trayectoria es posible que se pueda encontrar un
camino optimo.
*/
bool Robot::inicializar_sensores(Nodo n, int nfilas,int ncolumnas,Celda** square)
{
    int xx = n.camino.at(n.camino.size()-1).x;
    int yy = n.camino.at(n.camino.size()-1).y;
  if (!is_outrange(xx+1,yy,nfilas,ncolumnas))
  {
    if (square[xx+1][yy].get_estado()!=2)
      sensores_[1]=0;
    else
      sensores_[1]=1;
  }
  else
      sensores_[1]=-1;

  if (!is_outrange(xx-1,yy,nfilas,ncolumnas))
  {
      if (square[xx-1][yy].get_estado()!=2)
      sensores_[0]=0;
    else
      sensores_[0]=1;
  }
  else
      sensores_[0]=-1;

  if (!is_outrange(xx,yy-1,nfilas,ncolumnas))
  {
    if (square[xx][yy-1].get_estado()!=2)
      sensores_[3]=0;
    else
      sensores_[3]=1;
  }
  else
      sensores_[3]=-1;

  if (!is_outrange(xx,yy+1,nfilas,ncolumnas))
  {
    if (square[xx][yy+1].get_estado()!=2)
      sensores_[2]=0;
    else
      sensores_[2]=1;
  }
  else
      sensores_[2]=-1;

  int sum=abs(sensores_[0])+abs(sensores_[1])+abs(sensores_[2])+abs(sensores_[3]);

 return sum <4;
}

/*
Esta es una funcion que se le incorporata al metodo Qsort para que ordene la lista
segun su coste
*/
bool variantLessThan(const Nodo &n1, const Nodo &n2)
{
    return ( n1.costo_estimado < n2.costo_estimado);
}
/*
Esta es la funcion principal que desarrollara el algoritmo A*
El principio crea dos lista ( abierta(contendra las trayectorias posibles que no han sido
vistas) y cerrada(trayectorias ya visitadas).
Se inicializa la lista  abierta con el nodo inicial en el que esta el nodo añadiendo a su
vector la posicion inicial y el coste inicial
/sigue la explicacion dentro de la funcion/
*/

Nodo Robot::RecEuristico(Celda** square,int fin_x,int fin_y,int nfilas,int ncolumnas)
{

    QList<Nodo> abierta;
    QList<Nodo> cerrada;
    bool algo,algo2;
    Nodo aux,aux2,defaul,inicio;
    defaul.costo_estimado=-50;
    Posicion p1;
    p1.x=C_inicial_x_;
    p1.y=C_inicial_y_;
    inicio.camino.push_back(p1);
    inicio.costo_estimado=manhattan(p1.x,p1.y,fin_x,fin_y);
    abierta.push_front(inicio);
    do{
        /*Sacamos el primer nodo de la lista , lo guardamos en una variable auxiliar
           y en la lista cerrada */
        aux=abierta.front();
        abierta.pop_front();
        cerrada.push_front(aux);
        int yy = aux.camino.at(aux.camino.size() - 1).y;
        int xx= aux.camino.at(aux.camino.size()-1).x;

       /*Funcion explicada arriba*/
       if(inicializar_sensores(aux, nfilas,ncolumnas, square))
       {
        /*En esta parte del codigo examinamos cada una de las posibles trayectorias
         (sensores) y si es viable(sensor[i]=0 y no esta en el vector de lo nodo(funcion is_invector
         explicada mas adelante)) lo metemos dentro de la lista abierta
         y esto lo hacemos para cada sensor(0,1,2,3)
        */
           if(sensores_[1]==0){

                   if(is_invector(aux, xx+1, yy)==false){
                       aux2=aux;
                       p1.x=xx+1;
                       p1.y=yy;
                       aux2.camino.push_back(p1);
                       aux2.costo_estimado+=manhattan(p1.x,p1.y,fin_x,fin_y);
                       abierta.push_front(aux2);
                   }
           }
           if(sensores_[0]==0){

                   if(is_invector(aux, xx-1, yy)==false){
                       aux2=aux;
                       p1.x=xx-1;
                       p1.y=yy;
                       aux2.camino.push_back(p1);
                       aux2.costo_estimado+=manhattan(p1.x,p1.y,fin_x,fin_y);
                       abierta.push_front(aux2);
                   }
           }
           if(sensores_[3]==0){
                if(is_invector(aux, xx, yy-1)==false){
                       aux2=aux;
                       p1.x=xx;
                       p1.y=yy-1;
                       aux2.camino.push_back(p1);
                       aux2.costo_estimado+=manhattan(p1.x,p1.y,fin_x,fin_y);
                       abierta.push_front(aux2);
                }
           }
           if(sensores_[2]==0){
                 if(is_invector(aux, xx, yy+1)==false){
                       aux2=aux;
                       p1.x=xx;
                       p1.y=yy+1;
                       aux2.camino.push_back(p1);
                       aux2.costo_estimado+=manhattan(p1.x,p1.y,fin_x,fin_y);
                       abierta.push_front(aux2);
                 }
           }
         /*
          Despues de haber metido las posibles direcciones en la lista desde un determinado
          punto ordenamos la lista con la sentencia qsort pasandole la lista y la funcion
          que indica como debe ordenar la lista
         */


           qSort(abierta.begin(),abierta.end(),variantLessThan);
            /*
            La funcion siguiente como veis tiene dos do-while. El do-while de dentro lo que
            busca es eliminar los duplicados del primer nodo.Se realiza de esta forma y
            llamando a la funcion del_duplicate() porque usando solo el for y eliminando
            todos los elementos da una violacion de codigo debido a que no se actualiza el
            size en cada iteraccion de un for.Lo que realiza es que cada vez que se elimine un
            nodo la funcion envia un booleando true para que vuelva a examinar la lista po si
            quedan mas elementos repetidos

            La segunda parte lo que hace es buscar si hay un repetido en la lista cerrada.Para
            ello hay dos formas de proceder:
            1) Si el nodo de abierta tiene menor coste estimado no se realiza nada
            2) Si el nodo de abierta tiene un mayor coste estimado se elimina de lista abierta
                por lo que es necesario volver al primer do while para eliminar los duplicados
                de ese nodo que quedo en cabeza de la lista.

            Este proceso se repite hasta o hasta que se cumpla el punto numero 1 o abierta
            se quede vacia
            */
              do{
               do{
                if (!abierta.empty())
                {
                     aux=abierta.front();
                     abierta.pop_front();
                     algo=del_duplicate(aux, abierta);
                     abierta.push_front(aux);
                }
               }while(algo==true);

                if (!abierta.empty()){
                    aux=abierta.front();
                    abierta.pop_front();
                    algo2=del_duplicate_dual(aux, cerrada);
                    if (algo2 ==false)
                        abierta.push_front(aux);
                }else
                    algo2=false;
               }while(algo2==true);



        }else{
        /*Este else procede de la funcion del if que contiene la funcion inicializar_sensore()
        y lo que hace es que si no encuentra ninguna trayectoria posible(sum=4) lo expulsa
        de abierta si abierta esta vacia.
        */
            if (!abierta.empty())
                abierta.pop_front();

        }
        /*Este while va enlazado con el do que hay casi al principio de la funcion y lo que
         expone es que repita mientra abierta no este vacia && la coordenada final (camino)
         del primer nodo de abierta no sea la coordenada de la empresa madedera
        */
      } while (!abierta.empty() &&(abierta.front().camino.at(abierta.front().camino.size()-1).x !=fin_x || abierta.front().camino.at(abierta.front().camino.size()-1).y!=fin_y));
    /*
    Estas ultimas sentencias es que si la coordenada del primer nodo de la lista es
    la coordenada final se ha encontrado un camino optimo y devuelve el nodo que contiene
    cada una de las posiciones para llegar a la posicion final de una manera optima.
    Si por otro lado eso no se cumple(normalmente porque la lista estara vacia)
    devolvera un valor default con coste -50 y el mensaje de que no se encontro ningun
    camino
    */
      if(!abierta.empty() && abierta.front().camino.at(abierta.front().camino.size()-1).x==fin_x && abierta.front().camino.at(abierta.front().camino.size()-1).y==fin_y){
          if(informacion_ != NULL)
              informacion_->setText( "Camino optimo encontrado \n");
        return abierta.front();
      }
      else
      {
          if(informacion_ != NULL)
              informacion_->setText( "No se encontro ningún camino \n");
         return defaul;
      }

}
/*
Funcion que te calcula la distancia manhattan de unas coordenas iniciales a unas
coordenadas finales
*/
int Robot::manhattan(int inicio_x, int inicio_y,int fin_x ,int fin_y)
{
    return abs(inicio_x-fin_x)+abs(inicio_y-fin_y);

}
/*
Funcion que examina si una trayectoria se va fuera de rango
utilizada en la funcion inicializar_sensores()
*/
bool Robot::is_outrange(int x, int y,int nfilas,int ncolumnas)
{
    return (x<0 || y<0 || x >= nfilas || y >= ncolumnas);
}
/*
Funcion que elimina los duplicados de la lista abierta
*/
bool Robot::del_duplicate(Nodo n,QList<Nodo> &abierta)
{
    QList<Nodo> ::iterator open;
    int x,xx, y,yy;
    x=n.camino.at(n.camino.size()-1).x;
    y=n.camino.at(n.camino.size()-1).y;
    Nodo aux;
        for (open=abierta.begin();open !=abierta.end();open++)
        {
                aux=*open;
                xx=aux.camino.at(aux.camino.size()-1).x;
                yy=aux.camino.at(aux.camino.size()-1).y;
            if (x==xx && y==yy)
            {
                abierta.erase(open);
                return true;
            }
        }
        return false;
}
/*Funcion que examina si hay que eliminar el nodo actual por que ya existe un nodo
en cerrada con un coste menor o igual al coste del nodo actual*/
bool Robot::del_duplicate_dual(Nodo n,QList<Nodo> &cerrada)
{
    QList<Nodo> ::iterator close;
        int x,xx, y,yy, coste,coste1;
        x=n.camino.at(n.camino.size()-1).x;
        y=n.camino.at(n.camino.size()-1).y;
        coste1=n.costo_estimado;
        Nodo aux;
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

/*
Funcion que examina que dado un nodo n, este no tenga una coordenada guardada que sea
exactamente igual(devuelve true si existe esa coordenada en el vector o false cuando
no exista esa coordenada en el vector
*/
bool Robot::is_invector(Nodo n, int x, int y)
{
    if(!n.camino.empty())
    {
        for (int i=0;i < n.camino.size();i++)
        {
            if(n.camino.at(i).x ==x && n.camino.at(i).y==y)
            {
                return true;
            }
        }
        return false;
    }
    return false;
}




