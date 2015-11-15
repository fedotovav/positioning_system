/********************************************************************************
** Form generated from reading UI file 'color_range.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef COLOR_RANGE_H
#define COLOR_RANGE_H

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

class Ui_color_range
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

    void setupUi(QWidget *color_range)
    {
        if (color_range->objectName().isEmpty())
            color_range->setObjectName(QString::fromUtf8("color_range"));
        color_range->resize(505, 297);
        verticalLayoutWidget = new QWidget(color_range);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 501, 291));
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


        retranslateUi(color_range);
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

        QMetaObject::connectSlotsByName(color_range);
    } // setupUi

    void retranslateUi(QWidget *color_range)
    {
        color_range->setWindowTitle(QApplication::translate("color_range", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("color_range", "Hue:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("color_range", "Saturation:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("color_range", "Value:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class color_range: public Ui_color_range {};
} // namespace Ui

QT_END_NAMESPACE

#endif // COLOR_RANGE_H
