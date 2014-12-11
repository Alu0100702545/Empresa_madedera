#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QString>
#include <QDebug>
#include <QPixmap>
#include <QGraphicsScene>
#include <stdlib.h>
#include <time.h>
#include "vistagrafica.h"
#include "celda.h"
#include "robot.h"
#include "terreno.h"

//Definir constante el tamaño de las casillas de cada bloque
#define TAMCASILLA 16
//Defino Constantes del tablero por defecto
#define ALTURA 10
#define ANCHURA 10
#define OBSTACULO 1
// Defino Constantes de los límites del tablero
#define MAXALTURA 100
#define MAXANCHURA 100
#define MAXOBSTACULOS 100

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_actionSalir_triggered();
    void on_checkBoxModificar_stateChanged(int arg1);
    void on_lineEditAltura_textChanged(const QString &arg1);
    void on_lineEditAnchura_textChanged(const QString &arg1);
    void on_lineEditNumero_textChanged(const QString &arg1);
    void on_checkBoxAleatorio_stateChanged(int arg1);
   // Se genera el mapa con las opciones escogidas en la ventana principal
    void on_BotonGenerarMapa_clicked();
    // Se cambia la celda según las coordenadas que se le pasen a la misma por el evento mousepressed de la celda
    void cambiarCelda(int x,int y);
    // Se dibuja el terreno donde se va a mover el robot
    void pintarTerreno(void);

    void on_radioInicio_clicked();
    void on_radioDestino_clicked();
    void on_radioEliminar_clicked();
    void on_radioObstaculo_clicked();
    // Se invoca al algoritmo que va a realizar el robot para calcular la taryectoria a seguir
    void on_BotonVerCamino_clicked();

private:
    Ui::MainWindow *ui;
    int altura_;
    int anchura_;
    int obstaculos_;
    int aleatorio_;
    // Coordenadas del inicio del robot dentro del tablero
    int Sx_;
    int Sy_;
    // Coordenadas del destino del robot dentro del tablero
    int Zx_;
    int Zy_;
    // Esta variable nos indica el estado de las opciones del menú principal para interactuar en el mapa
    // antes de calcular la trayectoria a seguir
    int estado_;
    // Indica si ya se ha realizado el cálculo de la trayectoria a seguir para evitar modificaciones en el mapa
    bool sucio_;


    Terreno *terreno_;
    // Vista sobracargada que se va a usar para representar el tablero
    VistaGrafica *vista_tablero_;

    // Escena que permitirá introducir elementos en la escena
    QGraphicsScene *escena_;

    // Validadores que impidenn valores inválidos en los textbox
    QIntValidator *validadorAltura;
    QIntValidator *validadorAnchura;
    QIntValidator *validadorObstaculo;

};

#endif // MAINWINDOW_H
