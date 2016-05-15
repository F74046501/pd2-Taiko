#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include <QTime>
#include <QMainWindow>
#include <QMediaPlayer>

game_scene::game_scene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game_scene)
{
    ui->setupUi(this);

    //time_counter declare
    time = 30;
    ui->count->display(30);

    //show the score during the game
    score_LCD();
    score = 0;
    ui ->score -> display(0);

    //hide the frame
    frame_show();

    connect(timer, QTimer::timeout, this, game_scene::on_time_linkActivated);
    connect(timer, QTimer::timeout, this, game_scene::flying);
    connect(timer, QTimer::timeout, this, game_scene::flying_king);
    connect(timer, QTimer::timeout, this, game_scene::score_LCD);
    //connect(timer, QTimer::timeout, this, game_scene::keyPressEvent(QKeyEvent *event));
    timer->start(1000);



/* //put in the photo by codes

    BackGround_Path = ":/new/prefix1/game.jpg";
    BackGround = new QLabel;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(BackGround);

    BackGround->setParent(parent);
    BackGround->setGeometry(0,0,982,607);
    BackGround->setPixmap(QPixmap(BackGround_Path));
    BackGround->setScaledContents(true);
    BackGround->show();

*/

}

game_scene::~game_scene()
{
    delete ui;
}

void game_scene::on_time_linkActivated() //counter
{
    time--;

    //make the time may not be < 0
    if(time < 0){
        time = 0;
    }

    ui->count->display(time);

    //hide the ball in time < 0
    if(time <= 0){
        ui-> ball -> hide();
        ui-> king_ball -> hide();
    }

    //hide the ball in time > 0
    else if (time > 0){
        ui-> ball -> show();
        ui-> king_ball -> show();
    }

    //show the frame when the time = 0
    frame_show();
}

void game_scene::flying(){
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int rand = qrand() % 30;

    QPropertyAnimation *time;
    time = new QPropertyAnimation(ui-> ball, "geometry");
    time->setDuration(1000);
    time->setStartValue(QRect(150+rand*20,20,381,261));
    time->setEndValue(QRect(-400,20,381,261));
    time->start();
}

void game_scene::flying_king(){
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int rand = qrand() % 20;

    QPropertyAnimation *time;
    time = new QPropertyAnimation(ui-> king_ball, "geometry");
    time->setDuration(1700);
    time->setStartValue(QRect(400,80,291,101));
    time->setEndValue(QRect(-700-rand*30,80,291,101));
    time->start();
}

void game_scene::keyPressEvent(QKeyEvent *event) //hit the drum
{
    if(event->key() == Qt::Key_Right){
        ui-> ball -> hide();
    }

    if(event->key() == Qt::Key_Left){
        ui -> king_ball -> hide();
    }
}

void game_scene::on_fr_restart_clicked(){
    //this -> MainWindow::on_start_button_clicked()
    time = 30;
    score = 0;
}

void game_scene::on_fr_exit_clicked(){

    exit(1);
}

void game_scene::score_LCD()//show the score during the game
{
    ui-> score ->display(score);
}

void game_scene::frame_show(){
    if(time <= 0){
        ui -> frame -> show();
        ui-> fr_score ->display(final_score);
        ui-> test_ball_hit ->hide();
        ui-> test_king_ball_hit -> hide();
    }
    else if(time > 0){
        ui -> frame -> hide();
        ui-> test_ball_hit ->show();
        ui-> test_king_ball_hit -> show();
    }
}

void game_scene::on_test_ball_hit_clicked(){
    if(((ui->for_ball_left->x()-50)<(ui->ball->x()))&&((ui->for_ball_right->x()+50)>(ui->ball->x()))){
        ui -> ball -> hide();
        score++;
        final_score = score;
    }
}

void game_scene::on_test_king_ball_hit_clicked()
{
    if(((ui->for_king_left->x()-50)<(ui->king_ball->x()))&&((ui->for_king_right->x()+50)>(ui->king_ball->x()))){
    ui -> king_ball -> hide();
    score = score + 2;
    final_score = score;
    }
}
