#ifndef VISTAGRAFICA_H
#define VISTAGRAFICA_H
#include <QGraphicsView>
#include <QMouseEvent>
#include <QObject>

// Esta clase nos permite la representación de vistas y la sobrecarga del mousepressed dentro de la misma para saber
// qué celda se ha presionado dentro de la vista
class VistaGrafica: public QGraphicsView
{
    Q_OBJECT
private:
    unsigned int tam_celda_;

public:
    VistaGrafica(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event);
    void set_tam_celda(unsigned int tam);
    unsigned int get_tam_celda(void)const;

signals:
    void mousePressed(int x, int y);

};

#endif // VISTAGRAFICA_H

