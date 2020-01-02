#include "findbox.h"
#include "ui_findbox.h"

FindBox::FindBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FindBox)
{
    ui->setupUi(this);

}
FindBox::~FindBox()
{
    delete ui;
}

QLineEdit *FindBox::get_line()
{
    return ui->lineEdit;
}


