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
    QPushButton *pbQuitter = new QPushButton("Quitter", this);
    pbQuitter->setGeometry(1,170,60,30);
    MyButton *myb = new MyButton("Docteur Jeckyl",this);
    myb->setGeometry(125, 70, 120, 30);
    QObject::connect(pbQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(myb,SIGNAL(clicked()),myb,SLOT(slotChangeText()));
    //--------------------------------------------------------//



    // Quand on clique sur le nouveau bouton , on change le texte de celui-ci

    //-------------------------------------------------------//
    //button1 = new QPushButton("Spam-moi à fond !!!!", this);
    //button1->setGeometry(100,75,200,150);
}

void HelloQt::boutonclic1()
    {
        close();
    }

HelloQt::~HelloQt()
{
    delete ui;
}

MyButton::MyButton(const QString & texte, QWidget *parent):
    QPushButton(texte,parent)
{}

MyButton::~MyButton()
{

}

void MyButton::slotChangeText()
{
    if(text()==QString("Docteur Jeckyl"))
        setText(QString("Mister Hide"));
    else
        setText(QString("Docteur Jeckyl"));
}
