#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Registration.h"
#include <QWidget>
#include <QUndoStack>
#include <QShortcut>
#include <QAction>
#include <QKeySequence>
#include <QtCore>
#include <QFile>
#include <QTextStream>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent* event);
    void save();
    void saveShortcut();
    void closeShortcut();
    void undoShortcut();
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_removeButton_clicked();
    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;
    Registration reg;
    QUndoStack* undoStack;
    QShortcut* undoShortcut;
    void DataLoading();

    void lister();
    void undo();
    int currentRow, currentCol;
};
#endif // MAINWINDOW_H
