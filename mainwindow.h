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
#include <QPointer>
#include <QMdiSubWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QPointer<QMdiSubWindow> mdiChild;
    QString fileName, fileNameRead, fileNameWrite;
    MainWindow(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent* event);
    void saveShortcut();
    void undoShortcut();
    void openFileShortcut();
    void saveAsShortcut();
    void modifyShortcut();
    void removeShortcut();
    void manageShow();
    void showToolBar();
    void viewManagement();
    void listView();
    void addView();
    void searchControl();
    void listShortcut();

    ~MainWindow();

private slots:
    void addSlot();
    void editSlot();
    void removeSlot();
    void saveSlot();
    void showMenu(const QPoint &pos);
    void DataLoading();
    void save();
    void saveAs();
    void undo();
    void listSlot();

    // void on_nextButton_clicked();
    // void on_backButton_clicked();

private:
    Ui::MainWindow *ui;
    Registration reg;
    vector<Person> listPerson;
    QAction *undoAction, *removeAction, *modifyAction, *redoAction;
    void lister(vector<Person> listPerson);
    QAction* listAction;

    int currentRow, currentCol;
    int counter;
};
#endif // MAINWINDOW_H
