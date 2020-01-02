#ifndef NOTE_H
#define NOTE_H

#include <QMainWindow>
#include "Features.h"
#include <string>
#include <QFile>
#include "findbox.h"
namespace Ui {
class Note;
}

class Note : public QMainWindow
{
    Q_OBJECT

public:
    explicit Note(QWidget *parent = nullptr);
    ~Note();

public slots:
    void find();
    void select_word();
    void slot_open();
    void slot_new();
    void slot_save();
    void updateTitle();

private:
    bool ask_save_or_close();
private:
    FindBox* find_box;
    QString FileName;
    Ui::Note *ui;
};

#endif // NOTE_H
