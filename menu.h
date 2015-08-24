#ifndef MENU_H
#define MENU_H
#include "widget.h"
#include "interseccion.h"
#include "log.h"
#include <QWidget>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private slots:
    void on_Simular_clicked();

    void on_Historial_clicked();

    void on_Exit_clicked();

private:
    Ui::Menu *ui;
    Widget *ventana;
    Interseccion *inter;
};

#endif // MENU_H
