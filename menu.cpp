#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    inter=NULL;
}

Menu::~Menu()
{
    delete inter;
    delete ventana;
    delete ui;
}

void Menu::on_Simular_clicked()
{
    ventana = new Widget();
    ventana->setVisible(true);
    inter=ventana->getInterseccion();
}

void Menu::on_Historial_clicked()
{
    Log *l = new Log();
    l->setInterseccion(inter);
    l->setVisible(true);

}

void Menu::on_Exit_clicked()
{
    exit(0);
}
