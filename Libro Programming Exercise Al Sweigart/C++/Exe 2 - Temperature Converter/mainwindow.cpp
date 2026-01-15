/* Aplicación gráfica con la biblioteca Qt que permite convertir
temperaturas de grados Celcius a Farenheit y viceversa.*/

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <cmath>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

float truncateToDecimal(float value, int decimals)
{
    float factor = pow(10, decimals);
    return std::trunc(value * factor) / factor;
}

float temperatura;

void MainWindow::on_pushButton_clicked()
{
    float resultado = 0;

    temperatura = ui->lineEdit->text().toFloat();
    if(ui->comboBox->currentText() == "Celsius" and
      ui->comboBox_2->currentText() == "Farenheit")
    {
        resultado = (temperatura * 9.0) / 5.0  + 32;
        resultado = truncateToDecimal(resultado, 2);
        ui->label_5->setText(QString::number(resultado) + " ⁰F");
    }
    else if(ui->comboBox->currentText() == "Farenheit" and
            ui->comboBox_2->currentText() == "Celsius")
    {
        resultado = (temperatura - 32) * (5.0  / 9.0);
        resultado = truncateToDecimal(resultado, 2);
        ui->label_5->setText(QString::number(resultado) + " ⁰C");
    }
}

//Lo uso para solo aceptar digitos en la caja de texto
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QRegularExpression rx("-[0-9]+");

    ui->lineEdit->setValidator(new QRegularExpressionValidator(rx, this));
}

