// LoginWidget.cpp

#include "LoginWidget.h"
#include "AuthenticationManager.h"
#include "MainWindow.h"

#include <QHBoxLayout>
#include <QMessageBox>

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent) {
    passwordLabel = new QLabel("Password:", this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Login", this);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QHBoxLayout *passwordLayout = new QHBoxLayout;
    passwordLayout->addWidget(passwordLabel);
    passwordLayout->addWidget(passwordEdit);

    layout->addLayout(passwordLayout);
    layout->addWidget(loginButton);

    connect(loginButton, &QPushButton::clicked, this, &LoginWidget::onLoginClicked);
}

void LoginWidget::onLoginClicked() {
    QString password = passwordEdit->text();

    if (AuthenticationManager::verifyPassword(password)) {
        QMessageBox::information(this, "Login Success", "Valid password");
        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid password");
    }
}
