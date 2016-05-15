#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include "game_scene.h"
#include "ui_game_scene.h"
#include <QtCore>
#include <QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QApplication>
#include <QGraphicsTextItem>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QWidget>
#include <QBrush>
#include <string>
#include <stdlib.h>
#include <QpropertyAnimation.h>
#include <typeinfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exit_button_clicked()
{
    this->hide();
}

void MainWindow::on_start_button_clicked() //change window
{
    QWidget *temp = new QWidget;
    this->setCentralWidget(temp);
    second = new game_scene(temp);
    temp->show();
    music->setMedia(QUrl("qrc:/new/prefix1/pokemon_song.mp3"));
    music->play();
}

