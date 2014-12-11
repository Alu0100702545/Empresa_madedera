#include "terreno.h"
    //TABLERO
/*
Funcion para inicializar el terreno
*/

Terreno::Terreno(int n, int m,QLabel *informacion):
     tabla_(NULL),
     automata_(new Robot(-1,-1,informacion)),
     n_filas_(n),
     n_columnas_(m),
     fin_x_(-1),
     fin_y_(-1),
     informacion_(informacion)
    {
       tabla_ = new Celda*[n];
       for (int i=0;i<n;i++){
         tabla_[i]=new Celda[m];
      }
        this->rellenar_paso_natural();
    }
Terreno::~Terreno()
{
       for (int i=0;i<n_filas_;i++){
          delete tabla_[i];
       }
      delete [] tabla_;
}

/*Funcion que segun una coordenada x y coloca el automata en esa posicion y lo
 * construye
*/
bool  Terreno::introducir_automata(int x,int y)
{
        if (x>=0 && x<n_filas_ && y>=0 && y<n_columnas_ )
        {
            tabla_[x][y].set_estado(0);
            automata_=new Robot(x,y,informacion_);
            return true;
        }
        else{

            if(informacion_ != NULL)
                informacion_->setText("busque otra posicion viable");
            return false;
        }
}

/*Funcion que segun una coordenada x y coloca un arbol en esa posicion
*/
bool   Terreno::introducir_arboles(int x, int y)
{
          if (x>=0 && x<n_filas_ && y>=0 && y<n_columnas_ && tabla_[x][y].get_estado()==1)
          {
              tabla_[x][y].set_estado(2);
              return true;
          }
          else
          {
              if(informacion_ != NULL)
                  informacion_->setText("busque otra posicion viable");
            return false;
          }

}
/*Funcion que segun una coordenada x y coloca la empresa en esa posicion
*/
bool   Terreno::introducir_empresa(int x,int y){
         if (x>=0 && x<n_filas_ && y>=0 && y<n_columnas_)
         {
             tabla_[x][y].set_estado(3);
             fin_x_=x;
             fin_y_=y;
             return true;
        }
         else
         {
             if(informacion_ != NULL)
                 informacion_->setText("busque otra posicion viable");
            return false;
        }
}
/*Funcion que segun una coordenada x y coloca un terreno transitable en esa posicion
*/
bool Terreno::introducir_terreno(int x,int y)
{
    if (x>=0 && x<n_filas_ && y>=0 && y<n_columnas_)
    {
        tabla_[x][y].set_estado(1);
        return true;
    }
    else
    {
        if(informacion_ != NULL)
            informacion_->setText("busque otra posicion viable");
       return false;
   }
}
/*Funcion que rellena lo que falte de mapa con pasos naturales
*/

void  Terreno::rellenar_paso_natural()
{
         for(int i=0;i<n_filas_;i++){
             for(int j=0;j<n_columnas_;j++){
                 if(tabla_[i][j].get_estado()==-1)
                     tabla_[i][j].set_estado(1);
             }
          }

 }
/*Funcion que llama a la funcion euristica para consegui el camino optimo
y si lo hay lo marca en el mapa con la imagen que le corresponda*/
 void  Terreno::marcar_recorridoAutomata()
 {
       Nodo auxiliar;
       auxiliar=automata_->RecEuristico(tabla_,fin_x_,fin_y_,n_filas_,n_columnas_);

       if (!auxiliar.camino.empty())
       {
           for (int i=0;i <auxiliar.camino.size();i++)
           {
               if(tabla_[auxiliar.camino.at(i).x][auxiliar.camino.at(i).y].get_estado()!=0 && tabla_[auxiliar.camino.at(i).x][auxiliar.camino.at(i).y].get_estado()!=3)
                   tabla_[auxiliar.camino.at(i).x][auxiliar.camino.at(i).y].set_estado(4);
           }

           if(informacion_ != NULL)
               informacion_->setText(QString::number(auxiliar.costo_estimado));

        }
}
int Terreno::obtenerElementoTablero(int x,int y)const
{
    if( x < n_filas_ && y < n_columnas_)
        return (tabla_[x][y].get_estado());
    else
        return -1;

}
int Terreno::obtenerPosxrobot(void) const
{
    return automata_->get_X();
}
int Terreno::obtenerPosyrobot(void) const
{
    return automata_->get_Y();
}
int Terreno::obtenerPosyiniciorobot(void) const
{
    return automata_->get_Y_ini();
}
int Terreno::obtenerPosxiniciorobot(void) const
{
    return automata_->get_X_ini();
}
int Terreno::obtenerPosxFinalrobot(void)const
{
    return this->fin_x_;
}
int Terreno::obtenerPosyFinalrobot(void)const
{
    return this->fin_y_;
}
void Terreno::asignarPosFinal(int x,int y)
{
    this->fin_x_ = x;
    this->fin_y_ = y;
}
void Terreno::asignarPosInicio(int x,int y)
{
    this->automata_->set_X_ini(x);
    this->automata_->set_Y_ini(y);
    this->automata_->set_X(x);
    this->automata_->set_Y(y);
}
