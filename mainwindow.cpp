#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mdiArea->tileSubWindows();
    ui->saveFile->setEnabled(false);
    ui->liste->setRowCount(0);
    ui->liste->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->liste->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->liste, &QWidget::customContextMenuRequested, this, &MainWindow::showMenu);
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addSlot()));
    reg = Registration();
    listAction = new QAction(this);

    lister(reg.getListePerson());
    searchControl();
    showToolBar();
    saveShortcut();
    saveAsShortcut();
    undoShortcut();
    listShortcut();
    openFileShortcut();
    modifyShortcut();
    removeShortcut();
    reg.historique.push_back(reg.getListePerson());
    listView();
    addView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::listView()
{
    connect(ui->studentListView, &QAction::toggled, this, [this](bool checked){
        if (ui->listSub->parentWidget())
        {
            if (checked)
            {
                ui->listSub->parentWidget()->show();
                ui->listSub->parentWidget()->setFocus();
            }
            else
            {
                ui->listSub->parentWidget()->hide();
            }
        }
    });

    if (ui->listSub->parentWidget())
    {
        ui->listSub->parentWidget()->setAttribute(Qt::WA_DeleteOnClose, false);
        connect(ui->listSub, &QObject::destroyed, this, [this](){
            ui->studentListView->setChecked(false);
        });
    }
}
void MainWindow::addView()
{
    connect(ui->addStudentView, &QAction::toggled, this, [this](bool checked){
        if (ui->addSub->parentWidget())
        {
            if (checked)
            {
                ui->addSub->parentWidget()->show();
                ui->addSub->parentWidget()->setFocus();
            }
            else
            {
                ui->addSub->parentWidget()->hide();
            }
        }
    });

    if (ui->addSub->parentWidget())
    {
        ui->addSub->parentWidget()->setAttribute(Qt::WA_DeleteOnClose, false);
        connect(ui->addSub, &QObject::destroyed, this, [this](){
            ui->addStudentView->setChecked(false);
        });
    }
}

void MainWindow::showToolBar()
{
    ui->toolBar->addAction(ui->modifyAction);
    ui->toolBar->addAction(ui->removeAction);
    ui->toolBar->addAction(ui->undoAction);
    ui->toolBar->addAction(ui->redoAction);
    ui->toolBar->addAction(listAction);
}
void MainWindow::showMenu(const QPoint &pos)
{
    QMenu menu(tr("Menu"), this);
    menu.addAction(ui->undoAction);
    menu.addAction(ui->modifyAction);
    menu.addAction(ui->removeAction);
    menu.addAction(listAction);
    menu.exec(ui->liste->mapToGlobal(pos));
}
void MainWindow::closeEvent(QCloseEvent* event)
{
    if (ui->saveFile->isEnabled() == false) return;
    auto reply = QMessageBox::question(this, "Quitter", "Voulez-vous enregistrer avant de quitter ?",
                                       QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

    if(reply == QMessageBox::Yes)
    {
        save();
        event->accept();
    }
    else if (reply == QMessageBox::No)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}
void MainWindow::saveShortcut()
{
    ui->saveFile->setShortcut(QKeySequence::Save);
    connect(ui->saveFile, &QAction::triggered, this, &MainWindow::save);
}
void MainWindow::listShortcut()
{
    listAction->setText("Lister");
    listAction->setShortcut(QKeySequence(Qt::Key_L));
    connect(listAction, &QAction::triggered, this, &MainWindow::listSlot);
}
void MainWindow::listSlot()
{
    lister(reg.getListePerson());
}
void MainWindow::undoShortcut()
{
    ui->undoAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_C));
    connect(ui->undoAction, &QAction::triggered, this, &MainWindow::undo);
}
void MainWindow::openFileShortcut()
{
    ui->openFile->setShortcut(QKeySequence::Open);
    connect(ui->openFile, &QAction::triggered, this, &MainWindow::DataLoading);
}
void MainWindow::undo()
{
    int sizeOfhistorique;
    sizeOfhistorique = reg.historique.size();
    if (sizeOfhistorique > 1)
    {
        reg.setListePerson(reg.historique[sizeOfhistorique-2]);
        lister(reg.getListePerson());
        reg.historique.pop_back();
        ui->statusBar->showMessage("Action annulée", 2000);
        ui->saveFile->setEnabled(true);
    }
}
void MainWindow::modifyShortcut()
{
    ui->modifyAction->setShortcut(QKeySequence(Qt::Key_M));
    connect(ui->modifyAction, &QAction::triggered, this, &MainWindow::editSlot);
}
void MainWindow::removeShortcut()
{
    ui->removeAction->setShortcut(QKeySequence(Qt::Key_Delete));
    connect(ui->removeAction, &QAction::triggered, this, &MainWindow::removeSlot);
}
void MainWindow::save()
{
    listPerson = reg.getListePerson();
    if (fileName.isEmpty())
    {
        fileName = QFileDialog::getSaveFileName(this, "Enregistrer un fichier .csv", "", "Fichiers CSV (*.csv);;Textes (*.txt)");
    }

    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QMessageBox::warning(this, "File Error", "Error File Opening");
        return;
    }

    QTextStream stream(&file);
    for(const Person &p : listPerson)
    {
        stream << p.getName() + "," + p.getFirstName() + "," + QString::number(p.getAge())+"\n";
    }
    file.close();
    ui->saveFile->setEnabled(false);
    ui->statusBar->showMessage("Action enregistrée", 2000);
}
void MainWindow::saveAs()
{
    listPerson = reg.getListePerson();
    fileName = QFileDialog::getSaveFileName(this, "Enregistrer un fichier .csv", "", "Fichiers CSV (*.csv);;Textes (*.txt)");
    QFile file(fileName);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QMessageBox::warning(this, "File Error", "Error File Opening");
        return;
    }

    QTextStream stream(&file);
    for(const Person &p : listPerson)
    {
        stream << p.getName() + "," + p.getFirstName() + "," + QString::number(p.getAge())+"\n";
    }
    file.close();
    ui->saveFile->setEnabled(false);
    ui->statusBar->showMessage("Action enregistrée", 2000);
}
void MainWindow::DataLoading()
{
    QString line;
    QStringList lString;
    fileName = QFileDialog::getOpenFileName(this,
    "Ouvrir un fichier .csv", "", "CSV (*.csv);;Textes (*.txt)");
    if (fileName.isEmpty()) return;
    reg.setListePerson(vector<Person>{});
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "File Error", "Error File Opening");
        return;
    }

    QTextStream stream(&file);

    while(!stream.atEnd())
    {
        line = stream.readLine();
        lString = line.split(",");
        reg.ajouter(Person(lString[0], lString[1], lString[2].toInt()));
    }

    file.close();
    lister(reg.getListePerson());
}
void MainWindow::saveAsShortcut()
{
    ui->saveAsFile->setShortcut(QKeySequence::SaveAs);
    connect(ui->saveAsFile, &QAction::triggered, this, &MainWindow::saveAs);
}
void MainWindow::addSlot()
{
    QString name, firstname;
    int age;
    bool ok;

    name = ui->nameLineEdit->text();
    firstname = ui->fnameLineEdit->text();
    age = (ui->ageLineEdit->text()).toInt(&ok);
    ui->nameLineEdit->setText("");
    ui->fnameLineEdit->setText("");
    ui->ageLineEdit->setText("");
    reg.ajouter(Person(name, firstname, age));
    reg.historique.push_back(reg.getListePerson());
    lister(reg.getListePerson());
    ui->saveFile->setEnabled(true);
}
void MainWindow::lister(vector<Person> listPerson)
{
    ui->liste->setRowCount(listPerson.size());
    for(int i = 0; i < listPerson.size(); i++)
    {
        ui->liste->setItem(i, 0, new QTableWidgetItem(listPerson[i].getName()));
        ui->liste->setItem(i, 1, new QTableWidgetItem(listPerson[i].getFirstName()));
        ui->liste->setItem(i, 2, new QTableWidgetItem(QString::number(listPerson[i].getAge())));
    }
    ui->liste->resizeColumnsToContents();
}
void MainWindow::editSlot()
{
    currentRow = ui->liste->currentRow();
    currentCol = ui->liste->currentColumn();

    if (currentRow != -1 && currentCol != -1)
    {
        QTableWidgetItem* item = ui->liste->item(currentRow, currentCol);
        if (item)
        {
            item->setFlags(item->flags() | Qt::ItemIsEditable);
            ui->liste->editItem(ui->liste->item(currentRow, currentCol));
            ui->liste->resizeColumnsToContents();
            connect(ui->liste, &QTableWidget::itemChanged, this, [this](QTableWidgetItem* changedItem) {
                QString itemEdited = changedItem->text();
                reg.modifier(itemEdited, changedItem->row(), changedItem->column());
                ui->saveFile->setEnabled(true);
            });
            reg.historique.push_back(reg.getListePerson());
        }
    }
}
void MainWindow::removeSlot()
{
    currentRow = ui->liste->currentRow();
    currentCol = ui->liste->currentColumn();

    if (currentRow != -1 && currentCol != -1)
    {
        ui->liste->removeRow(currentRow);
        reg.supprimer(reg.getListePerson()[currentRow]);
        ui->saveFile->setEnabled(true);
        reg.historique.push_back(reg.getListePerson());
    }
}
void MainWindow::saveSlot()
{
    save();
}
void MainWindow::searchControl()
{
    QAction* searchAction = new QAction(this);
    ui->searchEditLine->addAction(searchAction);
    connect(ui->searchEditLine, &QLineEdit::returnPressed, this, [this](){
        vector<Person> listeFound = reg.rechercher(ui->searchEditLine->text());
        if(listeFound.size() != 0)
        {
            // reg.lister(listeFound);
            lister(listeFound);
        }
        else
        {
            QMessageBox::information(this, "Recherche", ui->searchEditLine->text() + " non trouvé");
        }
    });
    connect(ui->searchEditLine, &QLineEdit::textEdited, this, [this](){
        vector<Person> listeFound = reg.rechercher(ui->searchEditLine->text());
        if(listeFound.size() != 0)
        {
            // reg.lister(listeFound);
            lister(listeFound);
        }
    });
}

