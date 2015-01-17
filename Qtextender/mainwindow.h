#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../../Qtraspberrylib/mcp23017.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setUpPins();
    void setUpExtender();
    
private slots:
    void on_pushButton_clicked();

    void ext1_intB(quint8 value);

private:
    Ui::MainWindow *ui;

    Mcp23017 ext;

    int led_state;

    qint8 portb_state;
};

#endif // MAINWINDOW_H
