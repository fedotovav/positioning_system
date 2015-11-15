/********************************************************************************
** Form generated from reading UI file 'camera_settings.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CAMERA_SETTINGS_UI_H
#define CAMERA_SETTINGS_UI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_camera_settings
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_4;
    QDoubleSpinBox *brightness_hardware;
    QDoubleSpinBox *contrast_hardware;
    QDoubleSpinBox *exposure_hardware;
    QDoubleSpinBox *gain_hardware;
    QDoubleSpinBox *hue_hardware;
    QDoubleSpinBox *saturation_hardware;
    QWidget *tab;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_7;
    QDoubleSpinBox *brightness_software;
    QLabel *label_8;
    QDoubleSpinBox *contrast_software;

    void setupUi(QWidget *camera_settings)
    {
        if (camera_settings->objectName().isEmpty())
            camera_settings->setObjectName(QString::fromUtf8("camera_settings"));
        camera_settings->resize(159, 189);
        tabWidget = new QTabWidget(camera_settings);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 161, 191));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        formLayoutWidget = new QWidget(tab_2);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 151, 161));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);
        formLayout->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        brightness_hardware = new QDoubleSpinBox(formLayoutWidget);
        brightness_hardware->setObjectName(QString::fromUtf8("brightness_hardware"));
        brightness_hardware->setMinimum(-100);
        brightness_hardware->setMaximum(100);
        brightness_hardware->setSingleStep(0.1);

        formLayout->setWidget(0, QFormLayout::FieldRole, brightness_hardware);

        contrast_hardware = new QDoubleSpinBox(formLayoutWidget);
        contrast_hardware->setObjectName(QString::fromUtf8("contrast_hardware"));
        contrast_hardware->setMinimum(-100);
        contrast_hardware->setMaximum(100);
        contrast_hardware->setSingleStep(0.1);

        formLayout->setWidget(1, QFormLayout::FieldRole, contrast_hardware);

        exposure_hardware = new QDoubleSpinBox(formLayoutWidget);
        exposure_hardware->setObjectName(QString::fromUtf8("exposure_hardware"));
        exposure_hardware->setMinimum(-100);
        exposure_hardware->setMaximum(100);
        exposure_hardware->setSingleStep(0.1);

        formLayout->setWidget(5, QFormLayout::FieldRole, exposure_hardware);

        gain_hardware = new QDoubleSpinBox(formLayoutWidget);
        gain_hardware->setObjectName(QString::fromUtf8("gain_hardware"));
        gain_hardware->setMinimum(-100);
        gain_hardware->setMaximum(100);
        gain_hardware->setSingleStep(0.1);

        formLayout->setWidget(4, QFormLayout::FieldRole, gain_hardware);

        hue_hardware = new QDoubleSpinBox(formLayoutWidget);
        hue_hardware->setObjectName(QString::fromUtf8("hue_hardware"));
        hue_hardware->setMinimum(-100);
        hue_hardware->setMaximum(100);
        hue_hardware->setSingleStep(0.1);

        formLayout->setWidget(3, QFormLayout::FieldRole, hue_hardware);

        saturation_hardware = new QDoubleSpinBox(formLayoutWidget);
        saturation_hardware->setObjectName(QString::fromUtf8("saturation_hardware"));
        saturation_hardware->setMinimum(-100);
        saturation_hardware->setMaximum(100);
        saturation_hardware->setSingleStep(0.1);

        formLayout->setWidget(2, QFormLayout::FieldRole, saturation_hardware);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        formLayoutWidget_2 = new QWidget(tab);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(0, 0, 151, 161));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setRowWrapPolicy(QFormLayout::WrapLongRows);
        formLayout_2->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_2->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(formLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_7);

        brightness_software = new QDoubleSpinBox(formLayoutWidget_2);
        brightness_software->setObjectName(QString::fromUtf8("brightness_software"));
        brightness_software->setMinimum(-100);
        brightness_software->setMaximum(100);
        brightness_software->setSingleStep(0.1);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, brightness_software);

        label_8 = new QLabel(formLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_8);

        contrast_software = new QDoubleSpinBox(formLayoutWidget_2);
        contrast_software->setObjectName(QString::fromUtf8("contrast_software"));
        contrast_software->setMinimum(-100);
        contrast_software->setMaximum(100);
        contrast_software->setSingleStep(0.1);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, contrast_software);

        tabWidget->addTab(tab, QString());

        retranslateUi(camera_settings);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(camera_settings);
    } // setupUi

    void retranslateUi(QWidget *camera_settings)
    {
        camera_settings->setWindowTitle(QApplication::translate("camera_settings", "Camera settings", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("camera_settings", "Brightness:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("camera_settings", "Contrast:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("camera_settings", "Saturation:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("camera_settings", "Exposure", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("camera_settings", "Gain", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("camera_settings", "Hue", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("camera_settings", "Hardware", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("camera_settings", "Brightness:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("camera_settings", "Contrast:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("camera_settings", "Software", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class camera_settings: public Ui_camera_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CAMERA_SETTINGS_UI_H
