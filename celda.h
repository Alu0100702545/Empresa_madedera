#ifndef CELDA_H
#define CELDA_H
#include <QGraphicsPixmapItem>
#include <QPixmap>

// Se hereda de la clase QGraphicsPixmapItem para que una celda se puede representar en una escena en QT

class Celda:public QGraphicsPixmapItem
{
private:
    // La variable estado de celda nos indica el objeto que contiene dicha celda
    int estado_celda_;
    unsigned int tam_celda_;
public:
    Celda();
    virtual ~Celda();
    void set_estado(int x);
    int get_estado();


};

#endif // CELDA_H
