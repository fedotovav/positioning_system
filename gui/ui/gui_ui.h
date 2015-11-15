/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef GUI_UI_H
#define GUI_UI_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gui
{
public:
    QAction *actionParameters;
    QAction *ot_color_range;
    QAction *camera_settings;
    QAction *store_settings;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_pic;
    QMenuBar *menu;
    QMenu *object_track_settings;
    QMenu *camera_menu;

    void setupUi(QMainWindow *gui)
    {
        if (gui->objectName().isEmpty())
            gui->setObjectName(QString::fromUtf8("gui"));
        gui->resize(900, 500);
        gui->setMouseTracking(false);
        gui->setDocumentMode(false);
        gui->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        actionParameters = new QAction(gui);
        actionParameters->setObjectName(QString::fromUtf8("actionParameters"));
        ot_color_range = new QAction(gui);
        ot_color_range->setObjectName(QString::fromUtf8("ot_color_range"));
        camera_settings = new QAction(gui);
        camera_settings->setObjectName(QString::fromUtf8("camera_settings"));
        store_settings = new QAction(gui);
        store_settings->setObjectName(QString::fromUtf8("store_settings"));
        centralWidget = new QWidget(gui);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 891, 471));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_pic = new QLabel(gridLayoutWidget);
        label_pic->setObjectName(QString::fromUtf8("label_pic"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_pic->sizePolicy().hasHeightForWidth());
        label_pic->setSizePolicy(sizePolicy);
        label_pic->setSizeIncrement(QSize(1, 1));
        label_pic->setStyleSheet(QString::fromUtf8("Background-color: #000;"));
        label_pic->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        label_pic->setFrameShape(QFrame::StyledPanel);
        label_pic->setScaledContents(true);
        label_pic->setWordWrap(false);

        gridLayout->addWidget(label_pic, 0, 0, 1, 1);

        gui->setCentralWidget(centralWidget);
        menu = new QMenuBar(gui);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setGeometry(QRect(0, 0, 900, 19));
        object_track_settings = new QMenu(menu);
        object_track_settings->setObjectName(QString::fromUtf8("object_track_settings"));
        camera_menu = new QMenu(menu);
        camera_menu->setObjectName(QString::fromUtf8("camera_menu"));
        gui->setMenuBar(menu);

        menu->addAction(object_track_settings->menuAction());
        menu->addAction(camera_menu->menuAction());
        object_track_settings->addAction(ot_color_range);
        camera_menu->addAction(camera_settings);
        camera_menu->addAction(store_settings);

        retranslateUi(gui);

        QMetaObject::connectSlotsByName(gui);
    } // setupUi

    void retranslateUi(QMainWindow *gui)
    {
        gui->setWindowTitle(QApplication::translate("gui", "Position system", 0, QApplication::UnicodeUTF8));
        actionParameters->setText(QApplication::translate("gui", "Parameters", 0, QApplication::UnicodeUTF8));
        ot_color_range->setText(QApplication::translate("gui", "Color range", 0, QApplication::UnicodeUTF8));
        camera_settings->setText(QApplication::translate("gui", "Settings", 0, QApplication::UnicodeUTF8));
        store_settings->setText(QApplication::translate("gui", "Store settings", 0, QApplication::UnicodeUTF8));
        label_pic->setText(QString());
        object_track_settings->setTitle(QApplication::translate("gui", "Object track", 0, QApplication::UnicodeUTF8));
        camera_menu->setTitle(QApplication::translate("gui", "Camera", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class gui: public Ui_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // GUI_UI_H
