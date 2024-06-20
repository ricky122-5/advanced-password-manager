// LoginWidget.h

#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class LoginWidget : public QWidget {
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);

    private slots:
        void onLoginClicked();

private:
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
};

#endif // LOGINWIDGET_H
