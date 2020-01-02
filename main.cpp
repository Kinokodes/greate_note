#include <QApplication>
#include "Note.h"
#include <QDebug>
int main(int argv,char* argc[]){
    QApplication app(argv,argc);
    Note w;
    w.show();

    return app.exec();
}
