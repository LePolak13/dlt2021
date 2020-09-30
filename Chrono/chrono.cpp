#include "chrono.h"
#include "ui_chrono.h"

chrono::chrono(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chrono)
{
    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);             // Définition de la fenêtre
//---------------------------------------------------------------------//
    m_bout_start = new QPushButton("start");    // Liste des Widgets
    m_bout_reset = new QPushButton("reset");
    m_bout_stop  = new QPushButton("stop");
    m_lcd = new QLCDNumber();
//---------------------------------------------------------------------//
    m_layout = new QGridLayout();               // Création du calque
    m_layout->addWidget(m_bout_start,0,0);
    m_layout->addWidget(m_bout_stop,1,0);
    m_layout->addWidget(m_lcd,0,1);
    m_layout->addWidget(m_bout_reset,1,1);

    zoneCentrale->setLayout(m_layout);
//---------------------------------------------------------------------//
    timer_chrono = new QTimer();                // Création du Compteur
    resetCount();                               // MAZ variable de comptage
//---------------------------------------------------------------------//
    connect( m_bout_start, SIGNAL(clicked()), this, SLOT(onButton_Start()));
    connect( timer_chrono, SIGNAL(timeout()), this, SLOT(onTimer_Tick()));
    connect( m_bout_stop, SIGNAL(clicked()), timer_chrono, SLOT(stop()));
    connect( m_bout_reset, SIGNAL(clicked()), this, SLOT(onButton_Reset()));
//---------------------------------------------------------------------//
//              AFFICHAGE BARRE DE MENUS
//---------------------------------------------------------------------//
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QAction *actionQuitter = new QAction("&Quitter", this);
    menuFichier->addAction(actionQuitter);
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    // ui->setupUi(this);
}

//=========================================================================//
void chrono::resetCount()
    {
        countTimer=0;
    }
//=========================================================================//
void chrono::updateCount()
    {
        countTimer++;
    }
//=========================================================================//
void chrono::onButton_Start()
    {
        timer_chrono -> start(1000); // 1000 ms
    }
//=========================================================================//
void chrono::onButton_Reset()
    {
        resetCount();
        m_lcd -> display(countTimer);
    }
//=========================================================================//
void chrono::onTimer_Tick()
    {
        updateCount();
        m_lcd -> display(countTimer);
    }
//=========================================================================//

chrono::~chrono()
{
    delete ui;
}
