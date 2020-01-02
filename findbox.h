#ifndef FINDBOX_H
#define FINDBOX_H

#include <QWidget>
#include <QLineEdit>
namespace Ui {
class FindBox;
}

class FindBox : public QWidget
{
    Q_OBJECT

public:
    explicit FindBox(QWidget *parent = nullptr);
    ~FindBox();
    QLineEdit* get_line();

signals:

public slots:

private:
    Ui::FindBox *ui;

};

#endif // FINDBOX_H
