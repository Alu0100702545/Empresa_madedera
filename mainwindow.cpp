#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    altura_(0),
    anchura_(0),
    obstaculos_(0),
    estado_(-1),
    aleatorio_(false),
    Sx_(-1),
    Sy_(-1),
    Zx_(-1),
    Zy_(-1),
    terreno_(NULL),
    vista_tablero_(NULL),
    sucio_(false),
    escena_(NULL),
    ui(new Ui::MainWindow)
{

    validadorAltura = NULL;
    validadorAnchura = NULL;
    validadorObstaculo = NULL;


    // Validar cadenas
    validadorAltura = new QIntValidator(ALTURA,MAXALTURA, this);
    validadorAnchura = new QIntValidator(ANCHURA,MAXANCHURA, this);
    validadorObstaculo = new QIntValidator(OBSTACULO,MAXOBSTACULOS, this);

    ui->setupUi(this);

    ui->checkBoxAleatorio->setCheckState(Qt::Unchecked);
    ui->checkBoxModificar->setCheckState(Qt::Unchecked);
    ui->lineEditAltura->setValidator(validadorAltura);
    ui->lineEditAnchura->setValidator(validadorAnchura);
    ui->lineEditNumero->setValidator(validadorObstaculo);
    ui->lineEditAltura->clear();
    ui->lineEditAnchura->clear();
    ui->lineEditAltura->setEnabled(false);
    ui->lineEditAnchura->setEnabled(false);
    ui->lineEditNumero->setEnabled(false);
    ui->lineEditAltura->setText(QString::number(ALTURA));
    ui->lineEditAnchura->setText(QString::number(ANCHURA));
    ui->lineEditNumero->setText(QString::number(OBSTACULO));

    this->vista_tablero_ = new VistaGrafica;
    vista_tablero_->setAlignment((Qt::AlignLeft | Qt::AlignTop));
    vista_tablero_->setVisible(false);

    ui->MatrizLayout->addWidget(vista_tablero_);
    connect(vista_tablero_, SIGNAL(mousePressed(int, int)), this, SLOT(cambiarCelda(int,int)));


    // Creación de la Escena para añadir los items , en este caso el terreno
        escena_ = new QGraphicsScene;
        if (escena_ == NULL)
              ui->Label_Informacion->setText("No se ha podido crear la escena\n");

}

MainWindow::~MainWindow()
{
    escena_->deleteLater();
    vista_tablero_->deleteLater();
    delete validadorAnchura;
    delete validadorAltura;
    delete validadorObstaculo;
    delete terreno_;
    delete vista_tablero_;
    delete escena_;
    delete ui;

}

void MainWindow::on_actionSalir_triggered()
{
    this->close();
}

void MainWindow::on_checkBoxModificar_stateChanged(int arg1)
{
    if(ui->lineEditAltura->isEnabled() && ui->lineEditAnchura->isEnabled())
    {
        ui->lineEditAltura->setEnabled(false);
        ui->lineEditAnchura->setEnabled(false);
    }
    else
    {
        ui->lineEditAltura->setEnabled(true);
        ui->lineEditAnchura->setEnabled(true);
    }
}

void MainWindow::on_lineEditAltura_textChanged(const QString &arg1)
{
    altura_ = arg1.toInt();

}

void MainWindow::on_lineEditAnchura_textChanged(const QString &arg1)
{
    anchura_ = arg1.toInt();
}

void MainWindow::on_lineEditNumero_textChanged(const QString &arg1)
{
    obstaculos_ = arg1.toInt();
}



void MainWindow::on_checkBoxAleatorio_stateChanged(int arg1)
{
  if(aleatorio_ == true)
  {
      aleatorio_ = false;
  }
  else
  {
      aleatorio_ = true;
  }
  if(ui->lineEditNumero->isEnabled())
  {
      ui->lineEditNumero->setEnabled(false);
  }
  else
  {
      ui->lineEditNumero->setEnabled(true);
  }
}

void MainWindow::pintarTerreno()
{


    escena_->deleteLater();
    escena_ = new QGraphicsScene(vista_tablero_);

   QGraphicsPixmapItem *item;

   // Imagenes que se van a usar en la escena
   QPixmap Arbol(":/Imagenes/Arbol.bmp");
   QPixmap Final(":/Imagenes/Final.bmp");
   QPixmap Inicio(":/Imagenes/Robot.bmp");
   QPixmap Libre(":/Imagenes/Libre.bmp");
   QPixmap Robot(":/Imagenes/Robot.bmp");


   for (int i=0; i < this->anchura_;i++){
       for (int j=0; j < this->altura_;j++)
       {

          int actual = terreno_->obtenerElementoTablero(j,i);

           switch (actual) {
           case 0:
               item = escena_->addPixmap(Inicio);
               item->setX(i*TAMCASILLA);
               item->setY(j*TAMCASILLA);
               break;
           case 1:
               item = escena_->addPixmap(Libre);
               item->setX(i*TAMCASILLA);
               item->setY(j*TAMCASILLA);
               break;
           case 2:
               item = escena_->addPixmap(Arbol);
               item->setX(i*TAMCASILLA);
               item->setY(j*TAMCASILLA);
               break;
           case 3:
               item = escena_->addPixmap(Final);
               item->setX(i*TAMCASILLA);
               item->setY(j*TAMCASILLA);
               break;
           case 4:
               item = escena_->addPixmap(Robot);
               item->setX(i*TAMCASILLA);
               item->setY(j*TAMCASILLA);
               break;
           default:
               break;
           }

        }
   }
   vista_tablero_->centerOn(terreno_->obtenerPosxrobot()*TAMCASILLA,terreno_->obtenerPosyrobot()*TAMCASILLA);
   vista_tablero_->setScene(escena_);
   vista_tablero_->setVisible(true);
   vista_tablero_->show();
}

void MainWindow::on_BotonGenerarMapa_clicked()
{
    srand(time(NULL));
    terreno_ = new Terreno(altura_,anchura_,ui->Label_Informacion);
    sucio_ = false;
    if(aleatorio_)
    {
        int rand_x = 0;
        int rand_y = 0;

        for (int i=1;i<=obstaculos_;i++)
        {
            bool introducido = false;
            do{
               rand_x = rand()%(this->altura_ - 1);
               rand_y = rand()%(this->anchura_ - 1);
               if(terreno_->obtenerElementoTablero(rand_x,rand_y) == 1)
               {
                   introducido = terreno_->introducir_arboles(rand_x,rand_y);
               }
            }while(!introducido);
        }
    }
     pintarTerreno();
}
void MainWindow::cambiarCelda(int x,int y)
{
    bool introducido =false;
    if(sucio_ == false)
    {
        switch(estado_){
         case 0:
                if(terreno_->obtenerElementoTablero(x,y)== 1)
                {
                    if(terreno_->obtenerPosxiniciorobot() == -1 && terreno_->obtenerPosyiniciorobot() == -1)
                    {
                        introducido= terreno_->introducir_automata(x,y);
                    }
                    else
                    {
                        int inicio_x = terreno_->obtenerPosxiniciorobot();
                        int inicio_y = terreno_->obtenerPosyiniciorobot();
                        terreno_->introducir_terreno(inicio_x,inicio_y);
                        introducido = terreno_->introducir_automata(x,y);
                    }
                }
                break;
           case 3:
                if(terreno_->obtenerElementoTablero(x,y)== 1)
                {
                    if(terreno_->obtenerPosxFinalrobot() == -1 && terreno_->obtenerPosxFinalrobot() == -1)
                    {
                        introducido= terreno_->introducir_empresa(x,y);
                    }
                    else
                    {
                        int final_x = terreno_->obtenerPosxFinalrobot();
                        int final_y = terreno_->obtenerPosyFinalrobot();
                        terreno_->introducir_terreno(final_x,final_y);
                        introducido = terreno_->introducir_empresa(x,y);
                    }
                }
                 break;
            case 2:
                if(terreno_->obtenerElementoTablero(x,y)== 1)
                {
                    introducido = terreno_->introducir_arboles(x,y);
                }
                break;
             case 5:
                int aux = terreno_->obtenerElementoTablero(x,y);
                if(aux == 0 || aux==3 || aux == 2)
                {
                            if (aux == 0)
                                terreno_->asignarPosInicio(-1,-1);

                            if(aux == 3)
                                terreno_->asignarPosFinal(-1,-1);
                           introducido = terreno_->introducir_terreno(x,y);
                }
                break;
          }
          if (introducido)
          {
                pintarTerreno();
           }
     }
    else
     {
            ui->Label_Informacion->setText("Debe limpiar la escena");
     }
}
void MainWindow::on_radioInicio_clicked()
{
    estado_ = 0;
}
void MainWindow::on_radioDestino_clicked()
{
    estado_ = 3;
}
void MainWindow::on_radioEliminar_clicked()
{
    estado_ = 5;
}
void MainWindow::on_radioObstaculo_clicked()
{
    estado_ = 2;
}

void MainWindow::on_BotonVerCamino_clicked()
{
     sucio_ = false;
        if (sucio_ == false)
        {
          if(terreno_->obtenerPosxiniciorobot() != -1 && terreno_->obtenerPosyiniciorobot() != -1 && terreno_->obtenerPosxFinalrobot() != -1 && terreno_->obtenerPosyFinalrobot() != -1)
           {
                terreno_->marcar_recorridoAutomata();
                pintarTerreno();
                sucio_ = true;

           }
         }

}
