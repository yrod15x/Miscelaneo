/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_4;
    QComboBox *comboBox_2;
    QPushButton *pushButton;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(310, 280);
        MainWindow->setMaximumSize(QSize(310, 280));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        MainWindow->setPalette(palette);
        QFont font;
        font.setUnderline(true);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("this->setStyleSheet(\"background-color: blue;\");"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 10, 311, 31));
        QFont font1;
        font1.setPointSize(17);
        font1.setBold(true);
        font1.setUnderline(false);
        label->setFont(font1);
        label->setAutoFillBackground(true);
        label->setStyleSheet(QString::fromUtf8("this->setStyleSheet(\"background-color: black;\");"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label->setWordWrap(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 63, 111, 31));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setUnderline(false);
        font2.setKerning(false);
        label_2->setFont(font2);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(140, 70, 141, 22));
        lineEdit->setMaxLength(5);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(15, 111, 101, 31));
        label_3->setFont(font2);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(140, 115, 141, 22));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setUnderline(false);
        comboBox->setFont(font3);
        comboBox->setLabelDrawingMode(QComboBox::LabelDrawingMode::UseStyle);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(13, 155, 101, 31));
        label_4->setFont(font2);
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(140, 160, 141, 22));
        comboBox_2->setFont(font3);
        comboBox_2->setLabelDrawingMode(QComboBox::LabelDrawingMode::UseStyle);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(25, 210, 107, 35));
        QPalette palette1;
        QBrush brush1(QColor(31, 155, 93, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Highlight, brush1);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Highlight, brush1);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Highlight, brush1);
        pushButton->setPalette(palette1);
        QFont font4;
        font4.setPointSize(12);
        font4.setUnderline(false);
        pushButton->setFont(font4);
        pushButton->setStyleSheet(QString::fromUtf8("this->setStyleSheet(\"background-color: white;\");"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(170, 210, 101, 31));
        QFont font5;
        font5.setPointSize(19);
        font5.setBold(true);
        font5.setUnderline(false);
        font5.setKerning(false);
        label_5->setFont(font5);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 310, 19));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#d9d9d9;\">Convertir Temperatura</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#d9d9d9;\">Temperatura</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#d9d9d9;\">De Grados</span></p></body></html>", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Celsius", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Farenheit", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#d9d9d9;\">A Grados</span></p></body></html>", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Celsius", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "Farenheit", nullptr));

        pushButton->setText(QCoreApplication::translate("MainWindow", "Convertir", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#d9d9d9;\">0 C</span><span style=\" color:#d9d9d9; vertical-align:super;\">o</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
