#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->saveButton->hide();
    ui->liste->setRowCount(0);
    ui->liste->setEditTriggers(QAbstractItemView::NoEditTriggers);
    reg = Registration();
    DataLoading();
    lister();
    saveShortcut();
}

void MainWindow::saveShortcut()
{
    QShortcut* saveSc = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_S), this);
    connect(saveSc, &QShortcut::activated, this, &MainWindow::save);
}

void MainWindow::undoShorcut()
{
    QShortcut* undoSc = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_C), this);
    connect(undoSc, &QShortcut::activated, this, &MainWindow::undo);
}

void MainWindow::undo()
{
    if (reg.historique.size() > 0)
    {
        reg.setListePerson(reg.historique[reg.historique.size()-1]);
        reg.historique.pop_back();
        lister();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DataLoading()
{
    QFile file("database.csv");
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QMessageBox::warning(this, "File Error", "Error File Opening");
    }

    QTextStream stream(&file);

    while(!stream.atEnd())
    {
        QString line = stream.readLine();
        QStringList lString = line.split(",");
        reg.ajouter(Person(lString[0], lString[1], lString[2].toInt()));
    }

    file.close();
}

void MainWindow::save()
{
    vector<Person> listPerson;
    listPerson = reg.getListePerson();

    QFile file("database.csv");
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this, "File Error", "Error File Opening");
        return;
    }

    QTextStream stream(&file);
    for(Person p : listPerson)
    {
        stream << p.getName() + "," + p.getFirstName() + "," + QString::number(p.getAge())+"\n";
    }
    file.close();
    ui->saveButton->hide();
    ui->statusBar->showMessage("Action enregistrée", 2000);
}

void MainWindow::on_addButton_clicked()
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
    lister();
    ui->saveButton->show();
}

void MainWindow::lister()
{
    vector<Person> listPerson;
    listPerson = reg.getListePerson();
    ui->liste->setRowCount(listPerson.size());
    for(int i = 0; i < listPerson.size(); i++)
    {
        ui->liste->setItem(i, 0, new QTableWidgetItem(listPerson[i].getName()));
        ui->liste->setItem(i, 1, new QTableWidgetItem(listPerson[i].getFirstName()));
        ui->liste->setItem(i, 2, new QTableWidgetItem(QString::number(listPerson[i].getAge())));
    }
    ui->liste->resizeColumnsToContents();
}

void MainWindow::on_editButton_clicked()
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
                ui->saveButton->show();
                reg.historique.push_back(reg.getListePerson());
            });
        }
    }
}

void MainWindow::on_removeButton_clicked()
{
    currentRow = ui->liste->currentRow();
    currentCol = ui->liste->currentColumn();

    if (currentRow != -1 && currentCol != -1)
    {
        ui->liste->removeRow(currentRow);
        reg.supprimer(reg.getListePerson()[currentRow]);
        ui->saveButton->show();
        reg.historique.push_back(reg.getListePerson());
    }
}

void MainWindow::on_saveButton_clicked()
{
    save();
}

void MainWindow::closeShortcut()
{
    return;
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    if (ui->saveButton->isHidden()) return;
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
