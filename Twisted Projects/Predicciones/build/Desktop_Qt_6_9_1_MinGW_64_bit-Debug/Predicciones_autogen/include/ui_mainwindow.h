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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QMainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *boton;
    QLabel *predition;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QMainWindow)
    {
        if (QMainWindow->objectName().isEmpty())
            QMainWindow->setObjectName("QMainWindow");
        QMainWindow->resize(500, 200);
        QMainWindow->setMaximumSize(QSize(500, 200));
        centralwidget = new QWidget(QMainWindow);
        centralwidget->setObjectName("centralwidget");
        boton = new QPushButton(centralwidget);
        boton->setObjectName("boton");
        boton->setGeometry(QRect(190, 20, 131, 41));
        predition = new QLabel(centralwidget);
        predition->setObjectName("predition");
        predition->setGeometry(QRect(10, 80, 481, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        font.setPointSize(10);
        font.setWeight(QFont::Medium);
        predition->setFont(font);
        predition->setAlignment(Qt::AlignmentFlag::AlignCenter);
        QMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 19));
        QMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(QMainWindow);
        statusbar->setObjectName("statusbar");
        QMainWindow->setStatusBar(statusbar);

        retranslateUi(QMainWindow);

        QMetaObject::connectSlotsByName(QMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QMainWindow)
    {
        QMainWindow->setWindowTitle(QCoreApplication::translate("QMainWindow", "MainWindow", nullptr));
        boton->setText(QCoreApplication::translate("QMainWindow", "Give My Prediction", nullptr));
        predition->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QMainWindow: public Ui_QMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
