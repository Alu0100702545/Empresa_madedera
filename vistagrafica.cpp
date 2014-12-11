#include "vistagrafica.h"



VistaGrafica::VistaGrafica(QWidget *parent) : QGraphicsView(parent),tam_celda_(16) {

}

/* Se redefine el evento mouse press para obtener la posición i j dentro del tablero correcta del elemento gráfico */

void VistaGrafica::mousePressEvent(QMouseEvent *event)
{

    if (itemAt(event->pos())) {
        QPointF g = QGraphicsView::mapToScene(event->pos());

        qreal x = g.x();
        qreal y = g.y();

        int columna= x/tam_celda_;
        int fila= y/tam_celda_;
        emit mousePressed(fila, columna);
    }

}
void VistaGrafica::set_tam_celda(unsigned int tam)
{
        tam_celda_ = tam;

}
unsigned int VistaGrafica::get_tam_celda(void)const
{

    return tam_celda_;

}
