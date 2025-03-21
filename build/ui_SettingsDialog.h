/********************************************************************************
** Form generated from reading UI file 'SettingsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_6;
    QSpinBox *linesPerPageSpinBox;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *novelPathLineEdit;
    QPushButton *selectPathButton;
    QLabel *label_8;
    QSpinBox *fontSizeSpinBox;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_4;
    QComboBox *encodingLineEdit;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QSpinBox *textSpacingSpinBox;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_7;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_4;
    QSpinBox *lineSpacingSpinBox;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_5;
    QDoubleSpinBox *opacitySpinBox;
    QSpacerItem *verticalSpacer_7;
    QComboBox *menuEncodingLineEdit;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *applyButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QString::fromUtf8("SettingsDialog"));
        SettingsDialog->resize(455, 400);
        verticalLayout = new QVBoxLayout(SettingsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(SettingsDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 435, 349));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 4, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 15, 1, 1, 1);

        linesPerPageSpinBox = new QSpinBox(scrollAreaWidgetContents);
        linesPerPageSpinBox->setObjectName(QString::fromUtf8("linesPerPageSpinBox"));
        linesPerPageSpinBox->setMaximum(1000);

        gridLayout->addWidget(linesPerPageSpinBox, 15, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 9, 1, 1, 1);

        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 15, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 13, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        novelPathLineEdit = new QLineEdit(scrollAreaWidgetContents);
        novelPathLineEdit->setObjectName(QString::fromUtf8("novelPathLineEdit"));

        horizontalLayout->addWidget(novelPathLineEdit);

        selectPathButton = new QPushButton(scrollAreaWidgetContents);
        selectPathButton->setObjectName(QString::fromUtf8("selectPathButton"));

        horizontalLayout->addWidget(selectPathButton);


        gridLayout->addLayout(horizontalLayout, 13, 2, 1, 1);

        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 11, 0, 1, 1);

        fontSizeSpinBox = new QSpinBox(scrollAreaWidgetContents);
        fontSizeSpinBox->setObjectName(QString::fromUtf8("fontSizeSpinBox"));
        fontSizeSpinBox->setMaximum(30);

        gridLayout->addWidget(fontSizeSpinBox, 0, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 7, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 5, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 17, 1, 1, 1);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 13, 0, 1, 1);

        encodingLineEdit = new QComboBox(scrollAreaWidgetContents);
        encodingLineEdit->addItem(QString());
        encodingLineEdit->addItem(QString());
        encodingLineEdit->addItem(QString());
        encodingLineEdit->setObjectName(QString::fromUtf8("encodingLineEdit"));

        gridLayout->addWidget(encodingLineEdit, 9, 2, 1, 1);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFrameShadow(QFrame::Plain);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 6, 1, 1, 1);

        textSpacingSpinBox = new QSpinBox(scrollAreaWidgetContents);
        textSpacingSpinBox->setObjectName(QString::fromUtf8("textSpacingSpinBox"));
        textSpacingSpinBox->setMaximum(10);

        gridLayout->addWidget(textSpacingSpinBox, 4, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 17, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 16, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 12, 0, 1, 1);

        lineSpacingSpinBox = new QSpinBox(scrollAreaWidgetContents);
        lineSpacingSpinBox->setObjectName(QString::fromUtf8("lineSpacingSpinBox"));
        lineSpacingSpinBox->setMaximum(10);

        gridLayout->addWidget(lineSpacingSpinBox, 6, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 14, 0, 1, 1);

        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 9, 0, 1, 1);

        opacitySpinBox = new QDoubleSpinBox(scrollAreaWidgetContents);
        opacitySpinBox->setObjectName(QString::fromUtf8("opacitySpinBox"));
        opacitySpinBox->setMaximum(1.000000000000000);
        opacitySpinBox->setSingleStep(0.010000000000000);
        opacitySpinBox->setValue(0.850000000000000);

        gridLayout->addWidget(opacitySpinBox, 17, 2, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_7, 10, 0, 1, 1);

        menuEncodingLineEdit = new QComboBox(scrollAreaWidgetContents);
        menuEncodingLineEdit->addItem(QString());
        menuEncodingLineEdit->addItem(QString());
        menuEncodingLineEdit->setObjectName(QString::fromUtf8("menuEncodingLineEdit"));

        gridLayout->addWidget(menuEncodingLineEdit, 11, 2, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 11, 1, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        applyButton = new QPushButton(SettingsDialog);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));

        horizontalLayout_2->addWidget(applyButton);

        cancelButton = new QPushButton(SettingsDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_2->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(SettingsDialog);

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QWidget *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QCoreApplication::translate("SettingsDialog", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("SettingsDialog", "\346\226\207\346\234\254\351\227\264\350\267\235", nullptr));
        label->setText(QCoreApplication::translate("SettingsDialog", "\345\255\227\344\275\223\345\244\247\345\260\217", nullptr));
        label_6->setText(QCoreApplication::translate("SettingsDialog", "\346\257\217\351\241\265\345\255\227\346\225\260", nullptr));
        selectPathButton->setText(QCoreApplication::translate("SettingsDialog", "select", nullptr));
        label_8->setText(QCoreApplication::translate("SettingsDialog", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("SettingsDialog", "\350\267\257\345\276\204", nullptr));
        encodingLineEdit->setItemText(0, QCoreApplication::translate("SettingsDialog", "utf-8", nullptr));
        encodingLineEdit->setItemText(1, QCoreApplication::translate("SettingsDialog", "GBK", nullptr));
        encodingLineEdit->setItemText(2, QCoreApplication::translate("SettingsDialog", "GB2312", nullptr));

        label_3->setText(QCoreApplication::translate("SettingsDialog", "\350\241\214\351\227\264\350\267\235", nullptr));
        label_7->setText(QCoreApplication::translate("SettingsDialog", "\351\200\217\346\230\216\345\272\246", nullptr));
        label_5->setText(QCoreApplication::translate("SettingsDialog", "TextLabel", nullptr));
        menuEncodingLineEdit->setItemText(0, QCoreApplication::translate("SettingsDialog", "utf-8", nullptr));
        menuEncodingLineEdit->setItemText(1, QCoreApplication::translate("SettingsDialog", "GB2312", nullptr));

        applyButton->setText(QCoreApplication::translate("SettingsDialog", "apply", nullptr));
        cancelButton->setText(QCoreApplication::translate("SettingsDialog", "cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
