#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDataStream>


//1.создать базовое окно
//2 выделить память под ui
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this); //Берёт все кнопки, таблицы и другие элементы, которые были описаны в .ui файле, и размещает их внутри текущего окна (this)

    // Привязать кнопки к функциям
    connect(ui->btnLoadText1, &QPushButton::clicked, this, &MainWindow::load1);
    connect(ui->btnSaveText1, &QPushButton::clicked, this, &MainWindow::save1);
    connect(ui->btnLoadBin1,  &QPushButton::clicked, this, &MainWindow::loadBin1);
    connect(ui->btnSaveBin1,  &QPushButton::clicked, this, &MainWindow::saveBin1);

    connect(ui->btnLoadText2, &QPushButton::clicked, this, &MainWindow::load2);
    connect(ui->btnSaveText2, &QPushButton::clicked, this, &MainWindow::save2);
    connect(ui->btnLoadBin2,  &QPushButton::clicked, this, &MainWindow::loadBin2);
    connect(ui->btnSaveBin2,  &QPushButton::clicked, this, &MainWindow::saveBin2);
}

MainWindow::~MainWindow() {
    delete ui;
    delete model;
}

// ФУНКЦИИ CONTACT 1
void MainWindow::load1() {
    QString path = QFileDialog::getOpenFileName(this, "Load Text 1");
    if(path.isEmpty()) return;
    QFile f(path);
    if(f.open(QIODevice::ReadOnly | QIODevice::Text)) { QTextStream in(&f); in >> sol1; f.close(); }
    if(model) delete model;
    model = new TableModel<Contact1>(&sol1, {"Name", "Tel1", "Tel2"});
    ui->tableView->setModel(model);
}

void MainWindow::save1() {
    QString path = QFileDialog::getSaveFileName(this, "Save Text 1");
    if(path.isEmpty()) return;
    QFile f(path);
    if(f.open(QIODevice::WriteOnly | QIODevice::Text)) { QTextStream out(&f); out << sol1; f.close(); }
}

void MainWindow::loadBin1() {
    QString path = QFileDialog::getOpenFileName(this, "Load Binary 1");
    if(path.isEmpty()) return;
    QFile f(path);
    if(f.open(QIODevice::ReadOnly)) { QDataStream in(&f); in >> sol1; f.close(); }
    if(model) delete model;
    model = new TableModel<Contact1>(&sol1, {"Name", "Tel1", "Tel2"});
    ui->tableView->setModel(model);
}

void MainWindow::saveBin1() {
    QString path = QFileDialog::getSaveFileName(this, "Save Binary 1");
    if(path.isEmpty()) return;
    QFile f(path);
    if(f.open(QIODevice::WriteOnly)) { QDataStream out(&f); out << sol1; f.close(); }
}

// ФУНКЦИИ CONTACT 2
void MainWindow::load2() {
    QString path = QFileDialog::getOpenFileName(this, "Load Text 2");
    if(path.isEmpty()) return;
    QFile f(path);
    if(f.open(QIODevice::ReadOnly | QIODevice::Text)) { QTextStream in(&f); in >> sol2; f.close(); }
    if(model) delete model;
    model = new TableModel<Contact2>(&sol2, {"Name", "Address", "Tel1"});
    ui->tableView->setModel(model);
}

void MainWindow::save2() {
    QString path = QFileDialog::getSaveFileName(this, "Save Text 2");
    if(path.isEmpty()) return;
    QFile f(path);
    if(f.open(QIODevice::WriteOnly | QIODevice::Text)) { QTextStream out(&f); out << sol2; f.close(); }
}

void MainWindow::loadBin2() {
    QString path = QFileDialog::getOpenFileName(this, "Load Binary 2");
    if(path.isEmpty()) return;
    QFile f(path);
    if(f.open(QIODevice::ReadOnly)) { QDataStream in(&f); in >> sol2; f.close(); }
    if(model) delete model;
    model = new TableModel<Contact2>(&sol2, {"Name", "Address", "Tel1"});
    ui->tableView->setModel(model);
}

void MainWindow::saveBin2() {
    QString path = QFileDialog::getSaveFileName(this, "Save Binary 2");
    if(path.isEmpty()) return;
    QFile f(path);
    if(f.open(QIODevice::WriteOnly)) { QDataStream out(&f); out << sol2; f.close(); }
}
