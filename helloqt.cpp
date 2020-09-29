#include "helloqt.h"
#include "ui_helloqt.h"
#include <QPushButton>
#include <QApplication>

HelloQt::HelloQt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HelloQt)
{
    ui->setupUi(this);
    this->setFixedSize(400,250);
    this->setWindowTitle("Bienvenue Sir Kowalski !");
    //Déclaration du nouveau bouton
    pbQuitter = new QPushButton("Quitter", this);
    //Quand on clique sur le nouveau bouton, on change le texte de celui-ci
    QObject::connect(pbQuitter, SIGNAL(clicked()), this, SLOT(boutonclic1()));
    //--------------------------------------------------------//


    //-------------------------------------------------------//
    button1 = new QPushButton("Spam-moi à fond !!!!", this);
    button1->setGeometry(100,75,200,150);



}

void HelloQt::boutonclic1()
    {
        close();
    }

HelloQt::~HelloQt()
{
    delete ui;
}
