/********************************************************************************
** Form generated from reading UI file 'track.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TRACK_UI_H
#define TRACK_UI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_track
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *track)
    {
        if (track->objectName().isEmpty())
            track->setObjectName(QString::fromUtf8("track"));
        track->resize(640, 480);
        verticalLayoutWidget = new QWidget(track);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 631, 471));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("Background-color: #000;"));

        verticalLayout->addWidget(label);


        retranslateUi(track);

        QMetaObject::connectSlotsByName(track);
    } // setupUi

    void retranslateUi(QWidget *track)
    {
        track->setWindowTitle(QApplication::translate("track", "Track", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class track: public Ui_track {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TRACK_UI_H
