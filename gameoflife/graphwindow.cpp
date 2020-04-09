#include "graphwindow.h"
#include "ui_graphwindow.h"

GraphWindow::GraphWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GraphWindow)
{
    ui->setupUi(this);
}

GraphWindow::~GraphWindow()
{
    delete ui;
}


void GraphWindow::on_stepButton_clicked(){

}

void GraphWindow::on_playButton_clicked()
{

}

void GraphWindow::on_pauseButton_clicked()
{

}
