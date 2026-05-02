#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "contact1.h"
#include "contact2.h"
#include "solution.h"
#include "tablemodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }//автосг Класс Ui::MainWindow отвечает за дизайн
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~ MainWindow();

private slots:
//слоты-события.вызываются при нажатии соответствующих кнопок
    void load1(); void save1(); void loadBin1(); void saveBin1();
    void load2(); void save2(); void loadBin2(); void saveBin2();

private:
    Ui::MainWindow *ui; //укзаатель на все нарисованные виджеты(часть view)
    Solution<Contact1> sol1; //model
    Solution<Contact2> sol2; //model
    QAbstractTableModel* model = nullptr;//Объект класса TableModel, который берёт данные из sol1 ( sol2) и отдаёт их в QTableView
    //Адаптер (превращает Model в то, что понимает View)
};
#endif
