/********************************************************************************
** Form generated from reading UI file 'object_params.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef OBJECT_PARAMS_UI_H
#define OBJECT_PARAMS_UI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_object_params
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFormLayout *formLayout;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSlider *hue_max;
    QSlider *hue_min;
    QFrame *line_2;
    QLabel *label_2;
    QFormLayout *formLayout_3;
    QSlider *saturation_min;
    QSlider *saturation_max;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QFrame *line;
    QLabel *label_3;
    QFormLayout *formLayout_4;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox_6;
    QSlider *value_min;
    QSlider *value_max;
    QFrame *line_3;
    QLabel *label_5;
    QFormLayout *formLayout_5;
    QSpinBox *spinBox_7;
    QSpinBox *spinBox_8;
    QSlider *obj_size_min;
    QSlider *obj_size_max;
    QLabel *label_4;

    void setupUi(QWidget *object_params)
    {
        if (object_params->objectName().isEmpty())
            object_params->setObjectName(QString::fromUtf8("object_params"));
        object_params->resize(508, 362);
        verticalLayoutWidget = new QWidget(object_params);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 501, 355));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        spinBox = new QSpinBox(verticalLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(255);

        formLayout->setWidget(1, QFormLayout::LabelRole, spinBox);

        spinBox_2 = new QSpinBox(verticalLayoutWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMaximum(255);
        spinBox_2->setValue(255);

        formLayout->setWidget(2, QFormLayout::LabelRole, spinBox_2);

        hue_max = new QSlider(verticalLayoutWidget);
        hue_max->setObjectName(QString::fromUtf8("hue_max"));
        hue_max->setMouseTracking(false);
        hue_max->setFocusPolicy(Qt::NoFocus);
        hue_max->setContextMenuPolicy(Qt::DefaultContextMenu);
        hue_max->setAcceptDrops(false);
        hue_max->setAutoFillBackground(false);
        hue_max->setInputMethodHints(Qt::ImhNone);
        hue_max->setMaximum(255);
        hue_max->setValue(255);
        hue_max->setOrientation(Qt::Horizontal);
        hue_max->setInvertedAppearance(false);
        hue_max->setInvertedControls(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, hue_max);

        hue_min = new QSlider(verticalLayoutWidget);
        hue_min->setObjectName(QString::fromUtf8("hue_min"));
        hue_min->setFocusPolicy(Qt::WheelFocus);
        hue_min->setMaximum(255);
        hue_min->setSliderPosition(0);
        hue_min->setTracking(true);
        hue_min->setOrientation(Qt::Horizontal);
        hue_min->setInvertedAppearance(false);
        hue_min->setInvertedControls(false);
        hue_min->setTickPosition(QSlider::NoTicks);
        hue_min->setTickInterval(15);

        formLayout->setWidget(1, QFormLayout::FieldRole, hue_min);


        verticalLayout->addLayout(formLayout);

        line_2 = new QFrame(verticalLayoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        saturation_min = new QSlider(verticalLayoutWidget);
        saturation_min->setObjectName(QString::fromUtf8("saturation_min"));
        saturation_min->setMaximum(255);
        saturation_min->setOrientation(Qt::Horizontal);
        saturation_min->setInvertedAppearance(false);
        saturation_min->setInvertedControls(false);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, saturation_min);

        saturation_max = new QSlider(verticalLayoutWidget);
        saturation_max->setObjectName(QString::fromUtf8("saturation_max"));
        saturation_max->setMaximum(255);
        saturation_max->setValue(255);
        saturation_max->setOrientation(Qt::Horizontal);
        saturation_max->setInvertedAppearance(false);
        saturation_max->setInvertedControls(false);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, saturation_max);

        spinBox_3 = new QSpinBox(verticalLayoutWidget);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setMaximum(255);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, spinBox_3);

        spinBox_4 = new QSpinBox(verticalLayoutWidget);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setMaximum(255);
        spinBox_4->setValue(255);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, spinBox_4);


        verticalLayout->addLayout(formLayout_3);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        spinBox_5 = new QSpinBox(verticalLayoutWidget);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setMaximum(255);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, spinBox_5);

        spinBox_6 = new QSpinBox(verticalLayoutWidget);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setMaximum(255);
        spinBox_6->setValue(255);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, spinBox_6);

        value_min = new QSlider(verticalLayoutWidget);
        value_min->setObjectName(QString::fromUtf8("value_min"));
        value_min->setMaximum(255);
        value_min->setOrientation(Qt::Horizontal);
        value_min->setInvertedAppearance(false);
        value_min->setInvertedControls(false);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, value_min);

        value_max = new QSlider(verticalLayoutWidget);
        value_max->setObjectName(QString::fromUtf8("value_max"));
        value_max->setMaximum(255);
        value_max->setValue(255);
        value_max->setOrientation(Qt::Horizontal);
        value_max->setInvertedAppearance(false);
        value_max->setInvertedControls(false);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, value_max);


        verticalLayout->addLayout(formLayout_4);

        line_3 = new QFrame(verticalLayoutWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        spinBox_7 = new QSpinBox(verticalLayoutWidget);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));
        spinBox_7->setMaximum(10000);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, spinBox_7);

        spinBox_8 = new QSpinBox(verticalLayoutWidget);
        spinBox_8->setObjectName(QString::fromUtf8("spinBox_8"));
        spinBox_8->setMaximum(10000);
        spinBox_8->setValue(10000);

        formLayout_5->setWidget(1, QFormLayout::LabelRole, spinBox_8);

        obj_size_min = new QSlider(verticalLayoutWidget);
        obj_size_min->setObjectName(QString::fromUtf8("obj_size_min"));
        obj_size_min->setMaximum(10000);
        obj_size_min->setOrientation(Qt::Horizontal);
        obj_size_min->setInvertedAppearance(false);
        obj_size_min->setInvertedControls(false);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, obj_size_min);

        obj_size_max = new QSlider(verticalLayoutWidget);
        obj_size_max->setObjectName(QString::fromUtf8("obj_size_max"));
        obj_size_max->setMaximum(10000);
        obj_size_max->setValue(10000);
        obj_size_max->setOrientation(Qt::Horizontal);
        obj_size_max->setInvertedAppearance(false);
        obj_size_max->setInvertedControls(false);

        formLayout_5->setWidget(1, QFormLayout::FieldRole, obj_size_max);


        verticalLayout->addLayout(formLayout_5);

        label_4 = new QLabel(object_params);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 510, 499, 14));

        retranslateUi(object_params);
        QObject::connect(hue_min, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(hue_max, SIGNAL(valueChanged(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(saturation_min, SIGNAL(valueChanged(int)), spinBox_3, SLOT(setValue(int)));
        QObject::connect(saturation_max, SIGNAL(valueChanged(int)), spinBox_4, SLOT(setValue(int)));
        QObject::connect(value_min, SIGNAL(valueChanged(int)), spinBox_5, SLOT(setValue(int)));
        QObject::connect(value_max, SIGNAL(valueChanged(int)), spinBox_6, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), hue_min, SLOT(setValue(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), hue_max, SLOT(setValue(int)));
        QObject::connect(spinBox_3, SIGNAL(valueChanged(int)), saturation_min, SLOT(setValue(int)));
        QObject::connect(spinBox_4, SIGNAL(valueChanged(int)), saturation_max, SLOT(setValue(int)));
        QObject::connect(spinBox_5, SIGNAL(valueChanged(int)), value_min, SLOT(setValue(int)));
        QObject::connect(spinBox_6, SIGNAL(valueChanged(int)), value_max, SLOT(setValue(int)));
        QObject::connect(spinBox_7, SIGNAL(valueChanged(int)), obj_size_min, SLOT(setValue(int)));
        QObject::connect(obj_size_min, SIGNAL(valueChanged(int)), spinBox_7, SLOT(setValue(int)));
        QObject::connect(spinBox_8, SIGNAL(valueChanged(int)), obj_size_max, SLOT(setValue(int)));
        QObject::connect(obj_size_max, SIGNAL(valueChanged(int)), spinBox_8, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(object_params);
    } // setupUi

    void retranslateUi(QWidget *object_params)
    {
        object_params->setWindowTitle(QApplication::translate("object_params", "Object Parameters", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("object_params", "Hue:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("object_params", "Saturation:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("object_params", "Value:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("object_params", "Object size:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("object_params", "Value:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class object_params: public Ui_object_params {};
} // namespace Ui

QT_END_NAMESPACE

#endif // OBJECT_PARAMS_UI_H
