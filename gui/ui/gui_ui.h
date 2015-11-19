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
    QAction *ot_object_params;
    QAction *camera_settings;
    QAction *store_settings;
    QAction *ot_start_recording;
    QAction *v_show_track;
    QAction *ot_stop_recording;
    QAction *v_show_mesh;
    QAction *f_import_settings;
    QAction *f_export_settings;
    QAction *actionCamera_2;
    QAction *actionSettings;
    QAction *view_camera;
    QAction *actionCamera_5;
    QAction *object_params;
    QAction *camera_settings_2;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_pic;
    QMenuBar *menu;
    QMenu *object_track_settings;
    QMenu *file_menu;
    QMenu *view_menu;

    void setupUi(QMainWindow *gui)
    {
        if (gui->objectName().isEmpty())
            gui->setObjectName(QString::fromUtf8("gui"));
        gui->resize(640, 480);
        gui->setMouseTracking(false);
        gui->setDocumentMode(false);
        gui->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        actionParameters = new QAction(gui);
        actionParameters->setObjectName(QString::fromUtf8("actionParameters"));
        ot_object_params = new QAction(gui);
        ot_object_params->setObjectName(QString::fromUtf8("ot_object_params"));
        camera_settings = new QAction(gui);
        camera_settings->setObjectName(QString::fromUtf8("camera_settings"));
        store_settings = new QAction(gui);
        store_settings->setObjectName(QString::fromUtf8("store_settings"));
        ot_start_recording = new QAction(gui);
        ot_start_recording->setObjectName(QString::fromUtf8("ot_start_recording"));
        v_show_track = new QAction(gui);
        v_show_track->setObjectName(QString::fromUtf8("v_show_track"));
        v_show_track->setCheckable(true);
        v_show_track->setEnabled(true);
        ot_stop_recording = new QAction(gui);
        ot_stop_recording->setObjectName(QString::fromUtf8("ot_stop_recording"));
        v_show_mesh = new QAction(gui);
        v_show_mesh->setObjectName(QString::fromUtf8("v_show_mesh"));
        v_show_mesh->setCheckable(true);
        f_import_settings = new QAction(gui);
        f_import_settings->setObjectName(QString::fromUtf8("f_import_settings"));
        f_export_settings = new QAction(gui);
        f_export_settings->setObjectName(QString::fromUtf8("f_export_settings"));
        actionCamera_2 = new QAction(gui);
        actionCamera_2->setObjectName(QString::fromUtf8("actionCamera_2"));
        actionCamera_2->setCheckable(true);
        actionSettings = new QAction(gui);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        view_camera = new QAction(gui);
        view_camera->setObjectName(QString::fromUtf8("view_camera"));
        view_camera->setCheckable(true);
        actionCamera_5 = new QAction(gui);
        actionCamera_5->setObjectName(QString::fromUtf8("actionCamera_5"));
        object_params = new QAction(gui);
        object_params->setObjectName(QString::fromUtf8("object_params"));
        camera_settings_2 = new QAction(gui);
        camera_settings_2->setObjectName(QString::fromUtf8("camera_settings_2"));
        centralWidget = new QWidget(gui);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 631, 451));
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
        menu->setGeometry(QRect(0, 0, 640, 19));
        object_track_settings = new QMenu(menu);
        object_track_settings->setObjectName(QString::fromUtf8("object_track_settings"));
        file_menu = new QMenu(menu);
        file_menu->setObjectName(QString::fromUtf8("file_menu"));
        view_menu = new QMenu(menu);
        view_menu->setObjectName(QString::fromUtf8("view_menu"));
        gui->setMenuBar(menu);

        menu->addAction(file_menu->menuAction());
        menu->addAction(object_track_settings->menuAction());
        menu->addAction(view_menu->menuAction());
        object_track_settings->addAction(ot_start_recording);
        object_track_settings->addAction(ot_stop_recording);
        file_menu->addAction(f_import_settings);
        file_menu->addAction(f_export_settings);
        view_menu->addAction(v_show_track);
        view_menu->addAction(v_show_mesh);

        retranslateUi(gui);

        QMetaObject::connectSlotsByName(gui);
    } // setupUi

    void retranslateUi(QMainWindow *gui)
    {
        gui->setWindowTitle(QApplication::translate("gui", "Position system", 0, QApplication::UnicodeUTF8));
        actionParameters->setText(QApplication::translate("gui", "Parameters", 0, QApplication::UnicodeUTF8));
        ot_object_params->setText(QApplication::translate("gui", "Object parameters", 0, QApplication::UnicodeUTF8));
        camera_settings->setText(QApplication::translate("gui", "Settings", 0, QApplication::UnicodeUTF8));
        store_settings->setText(QApplication::translate("gui", "Store settings", 0, QApplication::UnicodeUTF8));
        ot_start_recording->setText(QApplication::translate("gui", "Start recording", 0, QApplication::UnicodeUTF8));
        v_show_track->setText(QApplication::translate("gui", "Show track", 0, QApplication::UnicodeUTF8));
        ot_stop_recording->setText(QApplication::translate("gui", "Stop recording", 0, QApplication::UnicodeUTF8));
        v_show_mesh->setText(QApplication::translate("gui", "Show mesh", 0, QApplication::UnicodeUTF8));
        f_import_settings->setText(QApplication::translate("gui", "Import settings", 0, QApplication::UnicodeUTF8));
        f_export_settings->setText(QApplication::translate("gui", "Export settings", 0, QApplication::UnicodeUTF8));
        actionCamera_2->setText(QApplication::translate("gui", "Camera 2", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("gui", "Settings", 0, QApplication::UnicodeUTF8));
        view_camera->setText(QApplication::translate("gui", "Camera 1", 0, QApplication::UnicodeUTF8));
        actionCamera_5->setText(QApplication::translate("gui", "Camera 2", 0, QApplication::UnicodeUTF8));
        object_params->setText(QApplication::translate("gui", "Object parameters", 0, QApplication::UnicodeUTF8));
        camera_settings_2->setText(QApplication::translate("gui", "Camera settings", 0, QApplication::UnicodeUTF8));
        label_pic->setText(QString());
        object_track_settings->setTitle(QApplication::translate("gui", "Object track", 0, QApplication::UnicodeUTF8));
        file_menu->setTitle(QApplication::translate("gui", "File", 0, QApplication::UnicodeUTF8));
        view_menu->setTitle(QApplication::translate("gui", "View", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class gui: public Ui_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // GUI_UI_H
