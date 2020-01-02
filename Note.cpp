#include "Note.h"
#include "ui_Note.h"

#include <QFileDialog>
#include <QMessageBox>

Note::Note(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Note)
{
    ui->setupUi(this);

    connect(ui->action_Open,SIGNAL(triggered()),this,SLOT(slot_open()));
    connect(ui->action_New,SIGNAL(triggered()),this,SLOT(slot_new()));
    connect(ui->action_Save,SIGNAL(triggered()),this,SLOT(slot_save()));

    connect(ui->plainTextEdit,SIGNAL(modificationChanged(bool)),this,SLOT(setWindowModified(bool)));

    slot_new();
}

Note::~Note()
{
    delete ui;
}

void Note::find()
{
    //
}

void Note::slot_open()
{
    QString IFileName = QFileDialog::getOpenFileName(this,"Open file..",QDir::homePath(),"Text files (*.txt);;All files (*.*)");//
    if(IFileName.isEmpty()){
        return;
    }
    QFile file(IFileName);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){

        ui->plainTextEdit->setPlainText(file.readAll());
        file.close();
        setWindowModified(false);
        FileName = IFileName;
        updateTitle();
    }else{
        QMessageBox::warning(this,"Error!",QString("File %1 is not open!").arg(IFileName),QMessageBox::Ok);
    }
}

void Note::slot_new()
{
    if(isWindowModified()){
        if(!ask_save_or_close()){
            return;
        }
    }
    FileName = "untitled";
    setWindowModified(true);
    ui->plainTextEdit->clear();
    updateTitle();
}

void Note::slot_save()
{
    if(!isWindowModified()){
        return;
    }
    QString IFileName = QFileDialog::getSaveFileName(this,"Save file..",QDir::homePath()+QString("/%1").arg(FileName), "Text files (*.txt);;C++ files (*.cpp)");

    QFile file(IFileName);


    if(file.open(QIODevice::WriteOnly)){
        QByteArray IData;
        IData.append(ui->plainTextEdit->toPlainText());
        file.write(IData);
        file.close();

        FileName=IFileName;
        setWindowModified(false);
        updateTitle();
    }else{
        QMessageBox::warning(this,"Error!",QString("Could not open file %1 for writing").arg(FileName),QMessageBox::Ok);
    }

}

void Note::updateTitle()
{
    QString title = QString("GreateNote - %1[*]").arg(FileName);
    this->setWindowTitle(title);
}

bool Note::ask_save_or_close()
{
    int Result = QMessageBox::question(this,"Warning!","Do you want to save file?",QMessageBox::Yes | QMessageBox::Cancel);
    if(QMessageBox::Cancel == Result){
        return false;
    }else{
        slot_save();
        return true;
    }
}


