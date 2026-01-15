//Programa que da una predicción al presionar un botón.

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QMainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::vector<std::string> predictions = {"Today is going to be a shitty day.",
"You make the same mistakes repeatedly because you’re stupid.",
"You have no influence on your friends and people resent you.",
"You are quick tempered, impatient and scornful of advice.",
"Most people think you are stubborn and bull-headed.",
"You are inclined to expect too much for too little. Bastard.",
"You are always putting things off. You will always be on welfare.",
"You're vain and can’t tolerate criticism. Your arrogance is disgusting.",
"You’re unemotional and people often fall asleep while talking to you.",
"If you are male, you are nil. Most libra women are lazy. You're a loser.",
"You will achieve the pinnacle of success because of your lack of ethics."                                        };


void MainWindow::on_pushButton_clicked()
{
    std::string todayPred = predictions[0];
    ui->predition->setText(QString::fromStdString(todayPred));
}


void MainWindow::on_boton_clicked()
{
    srand(time(NULL));
    std::string todayPred = predictions[rand() % predictions.size()];
    ui->predition->setText(QString::fromStdString(todayPred));
}

