#include <QApplication>
#include <QPushButton>
#include "LoginWidget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    LoginWidget login_widget;
    login_widget.show();

    return a.exec();
}
