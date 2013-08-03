#include "gameui.h"
#include "ui_gameui.h"

GameUi::GameUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameUi)
{
    ui->setupUi(this);
}


GameUi::~GameUi()
{
    delete ui;
}
