#include "menu.h"
#include "ui_menu.h"
#include <QMessageBox>

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    inter=NULL;
    ui->Logo->setPixmap(QPixmap(":Logo.png"));
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
    if(inter){
        Log *l = new Log();
        l->setInterseccion(inter);
        l->setVisible(true);
    }else{
        QMessageBox::warning(this, "Error", "No ha habido simulacion");
    }
}

void Menu::on_Exit_clicked()
{
    exit(0);
}
