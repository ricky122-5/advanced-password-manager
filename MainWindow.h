#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include "Account.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    private slots:
        void onSetMasterPasswordClicked();
    void onAddNewAccountClicked();
    void showAccountDetails(QTreeWidgetItem *item, int column);

private:
    QPushButton *setMasterPasswordButton;
    QPushButton *addNewAccountButton;
    QTreeWidget *accountsTree;

    std::vector<Account> accounts;

    void addAccountToTree(const Account &account);
    QString passwordHidden(const std::vector<uint64_t>& encryptedPassword);
};

#endif // MAINWINDOW_H
