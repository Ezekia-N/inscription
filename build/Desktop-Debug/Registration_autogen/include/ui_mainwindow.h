/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newFile;
    QAction *openFile;
    QAction *saveFile;
    QAction *saveAsFile;
    QAction *undoAction;
    QAction *redoAction;
    QAction *modifyAction;
    QAction *removeAction;
    QAction *quit;
    QAction *addStudentView;
    QAction *studentListView;
    QAction *toolBarView;
    QAction *statutBarView;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QMdiArea *mdiArea;
    QWidget *addSub;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *fnameLineEdit;
    QLineEdit *ageLineEdit;
    QLabel *nameLabel;
    QLabel *ageLabel;
    QLabel *fnameLabel;
    QLineEdit *nameLineEdit;
    QPushButton *addButton;
    QWidget *listSub;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *searchEditLine;
    QTableWidget *liste;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *backButton;
    QPushButton *nextButton;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuAbout;
    QMenu *menuAffichage;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1080, 600);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        newFile = new QAction(MainWindow);
        newFile->setObjectName("newFile");
        openFile = new QAction(MainWindow);
        openFile->setObjectName("openFile");
        saveFile = new QAction(MainWindow);
        saveFile->setObjectName("saveFile");
        saveAsFile = new QAction(MainWindow);
        saveAsFile->setObjectName("saveAsFile");
        undoAction = new QAction(MainWindow);
        undoAction->setObjectName("undoAction");
        redoAction = new QAction(MainWindow);
        redoAction->setObjectName("redoAction");
        modifyAction = new QAction(MainWindow);
        modifyAction->setObjectName("modifyAction");
        removeAction = new QAction(MainWindow);
        removeAction->setObjectName("removeAction");
        quit = new QAction(MainWindow);
        quit->setObjectName("quit");
        addStudentView = new QAction(MainWindow);
        addStudentView->setObjectName("addStudentView");
        addStudentView->setCheckable(true);
        addStudentView->setChecked(true);
        studentListView = new QAction(MainWindow);
        studentListView->setObjectName("studentListView");
        studentListView->setCheckable(true);
        studentListView->setChecked(true);
        toolBarView = new QAction(MainWindow);
        toolBarView->setObjectName("toolBarView");
        toolBarView->setCheckable(true);
        toolBarView->setChecked(true);
        statutBarView = new QAction(MainWindow);
        statutBarView->setObjectName("statutBarView");
        statutBarView->setCheckable(true);
        statutBarView->setChecked(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName("mdiArea");
        mdiArea->setTabPosition(QTabWidget::North);
        addSub = new QWidget();
        addSub->setObjectName("addSub");
        layoutWidget = new QWidget(addSub);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 10, 310, 134));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        fnameLineEdit = new QLineEdit(layoutWidget);
        fnameLineEdit->setObjectName("fnameLineEdit");

        gridLayout->addWidget(fnameLineEdit, 1, 1, 1, 1);

        ageLineEdit = new QLineEdit(layoutWidget);
        ageLineEdit->setObjectName("ageLineEdit");

        gridLayout->addWidget(ageLineEdit, 2, 1, 1, 1);

        nameLabel = new QLabel(layoutWidget);
        nameLabel->setObjectName("nameLabel");
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        nameLabel->setFont(font);

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        ageLabel = new QLabel(layoutWidget);
        ageLabel->setObjectName("ageLabel");
        ageLabel->setFont(font);

        gridLayout->addWidget(ageLabel, 2, 0, 1, 1);

        fnameLabel = new QLabel(layoutWidget);
        fnameLabel->setObjectName("fnameLabel");
        fnameLabel->setFont(font);

        gridLayout->addWidget(fnameLabel, 1, 0, 1, 1);

        nameLineEdit = new QLineEdit(layoutWidget);
        nameLineEdit->setObjectName("nameLineEdit");

        gridLayout->addWidget(nameLineEdit, 0, 1, 1, 1);

        addButton = new QPushButton(addSub);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(20, 150, 111, 41));
        mdiArea->addSubWindow(addSub);
        listSub = new QWidget();
        listSub->setObjectName("listSub");
        verticalLayout_2 = new QVBoxLayout(listSub);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(listSub);
        groupBox->setObjectName("groupBox");
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 81, 21));
        searchEditLine = new QLineEdit(groupBox);
        searchEditLine->setObjectName("searchEditLine");
        searchEditLine->setGeometry(QRect(90, 5, 331, 31));

        verticalLayout_2->addWidget(groupBox);

        liste = new QTableWidget(listSub);
        if (liste->columnCount() < 3)
            liste->setColumnCount(3);
        QFont font1;
        font1.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        liste->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        liste->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        liste->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        liste->setObjectName("liste");
        liste->setEnabled(true);
        liste->setSelectionBehavior(QAbstractItemView::SelectItems);
        liste->setColumnCount(3);

        verticalLayout_2->addWidget(liste);

        groupBox_2 = new QGroupBox(listSub);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        backButton = new QPushButton(groupBox_2);
        backButton->setObjectName("backButton");

        gridLayout_2->addWidget(backButton, 0, 0, 1, 1);

        nextButton = new QPushButton(groupBox_2);
        nextButton->setObjectName("nextButton");

        gridLayout_2->addWidget(nextButton, 0, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);

        mdiArea->addSubWindow(listSub);

        verticalLayout->addWidget(mdiArea);

        MainWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        statusBar->setFont(font2);
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1080, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName("menuAbout");
        menuAffichage = new QMenu(menuBar);
        menuAffichage->setObjectName("menuAffichage");
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAffichage->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(openFile);
        menuFile->addAction(saveFile);
        menuFile->addAction(saveAsFile);
        menuAffichage->addAction(addStudentView);
        menuAffichage->addAction(studentListView);
        menuAffichage->addAction(toolBarView);
        menuAffichage->addAction(statutBarView);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        newFile->setText(QCoreApplication::translate("MainWindow", "Nouveau fichier", nullptr));
        openFile->setText(QCoreApplication::translate("MainWindow", "Ouvrir un fichier", nullptr));
        saveFile->setText(QCoreApplication::translate("MainWindow", "Enregistrer ", nullptr));
        saveAsFile->setText(QCoreApplication::translate("MainWindow", "Enregistrer sous", nullptr));
        undoAction->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        redoAction->setText(QCoreApplication::translate("MainWindow", "Refaire", nullptr));
        modifyAction->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        removeAction->setText(QCoreApplication::translate("MainWindow", "Retirer", nullptr));
        quit->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        addStudentView->setText(QCoreApplication::translate("MainWindow", "Ajout d'un \303\251tudiant", nullptr));
        studentListView->setText(QCoreApplication::translate("MainWindow", "Listes des \303\251tudiants", nullptr));
        toolBarView->setText(QCoreApplication::translate("MainWindow", "Barre d'toutils", nullptr));
        statutBarView->setText(QCoreApplication::translate("MainWindow", "Barre de statut", nullptr));
        addSub->setWindowTitle(QCoreApplication::translate("MainWindow", "Ajout d'un \303\251tudiant", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        ageLabel->setText(QCoreApplication::translate("MainWindow", "Age : ", nullptr));
        fnameLabel->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom : ", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        listSub->setWindowTitle(QCoreApplication::translate("MainWindow", "Listes des \303\251tudiants", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        QTableWidgetItem *___qtablewidgetitem = liste->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = liste->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = liste->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Age", nullptr));
        groupBox_2->setTitle(QString());
        backButton->setText(QCoreApplication::translate("MainWindow", "pr\303\251c\303\251dent", nullptr));
        nextButton->setText(QCoreApplication::translate("MainWindow", "suivant", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "Fichier", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Aide", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "\303\200 propos", nullptr));
        menuAffichage->setTitle(QCoreApplication::translate("MainWindow", "Affichage", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
