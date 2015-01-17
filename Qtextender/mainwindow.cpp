#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "hardware_conf.h"
#include "../../Qtraspberrylib/mcp23017_isr.h"

#include <wiringPi.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setUpPins();
    setUpExtender();

    led_state = 0;
    portb_state = 0xff; //pull-ups will tke portb ints to Vdd
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setUpPins()
{
    //Configure the pins mode (GPIO numeration) and export them (BCM numeration)
    //GPIO.1 --> EXTENDER INTA
    //GPIO.4 --> EXTENDER INTB

    system("gpio mode 1 in");
    system("gpio mode 1 up");
    system("gpio mode 4 in");
    system("gpio mode 4 up");
    system("gpio export 18 in");
    system("gpio export 23 in");

    wiringPiSetupSys();
}

void MainWindow::setUpExtender()
{
    int ret;

    /*******************/
    /* Extender Config */
    /*******************/

    //General config: open descriptor, config I/O, pullups
    ret = ext.open(EXTENDER_ADDRESS); //Open MCP23017 at address 0x20
    ret = ext.setTris(PORTA,TRISA); // Set I/O
    ret = ext.setTris(PORTB,TRISB);
    ret = ext.setPullup(PORTA,A_PULLUP); // Set pullup resistors
    ret = ext.setPullup(PORTB,B_PULLUP);

    //Setup interruption on Port B
    setupMcp23017_isr_ext1(&ext);

    connect(&ext,SIGNAL(interrupt_B(quint8)),this,SLOT(ext1_intB(quint8)));

}

void MainWindow::on_pushButton_clicked()
{
    if (led_state) {
        led_state= 0;
        LED_A0_OFF;
    } else {
        led_state = 1;
        LED_A0_ON;
    }
}

void MainWindow::ext1_intB(quint8 value)
{
    quint8 aux;

    aux = portb_state ^ value; //Only pin that changed is sets a bit.
    portb_state = value;

    if(aux & BUT1) {
        if ((value & BUT1) >> 0 ) { //Active low
           ui->lineEdit->setText("Button at B0 Idle");
        } else {
           ui->lineEdit->setText("Button at B0 Pressed");
        }

    } else if (aux & BUT2) { //Active low
        if ((value & BUT2) >> 1 ) {
           ui->lineEdit->setText("Button at B1 Idle");
        } else {
           ui->lineEdit->setText("Button at B1 Pressed");
        }
    }

}
