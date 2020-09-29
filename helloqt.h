#ifndef HELLOQT_H
#define HELLOQT_H

#include <QtWidgets/QPushButton>

#include <QMainWindow>

namespace Ui {
class HelloQt;
}

class HelloQt : public QMainWindow
{
    Q_OBJECT

public:
    explicit HelloQt(QWidget *parent = 0);
    ~HelloQt();
    QPushButton *pbQuitter;
    QPushButton *button1;


private:
    Ui::HelloQt *ui;

public slots:
    void boutonclic1();

};

#endif // HELLOQT_H
