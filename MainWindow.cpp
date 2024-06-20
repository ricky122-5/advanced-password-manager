#include "MainWindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QVBoxLayout>
#include "AuthenticationManager.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    accountsTree = new QTreeWidget(this);
    accountsTree->setColumnCount(1);
    accountsTree->setHeaderLabel("Accounts");
    connect(accountsTree, &QTreeWidget::itemClicked, this, &MainWindow::showAccountDetails);
    layout->addWidget(accountsTree);

    setMasterPasswordButton = new QPushButton("Set Master Password", this);
    connect(setMasterPasswordButton, &QPushButton::clicked, this, &MainWindow::onSetMasterPasswordClicked);
    layout->addWidget(setMasterPasswordButton);

    addNewAccountButton = new QPushButton("Add New Account", this);
    connect(addNewAccountButton, &QPushButton::clicked, this, &MainWindow::onAddNewAccountClicked);
    layout->addWidget(addNewAccountButton);

    setCentralWidget(centralWidget);
}

void MainWindow::onSetMasterPasswordClicked() {
    bool ok;
    QString newPassword = QInputDialog::getText(this, "Set Master Password", "New Password:", QLineEdit::Password, "", &ok);
    if (ok && !newPassword.isEmpty()) {
        AuthenticationManager::setPassword(newPassword);
        QMessageBox::information(this, "Success", "Master password updated.");
    }
}

void MainWindow::onAddNewAccountClicked() {
    bool ok;
    QString username = QInputDialog::getText(this, "New Account", "Username:", QLineEdit::Normal, "", &ok);
    if (!ok || username.isEmpty()) return;

    QString website = QInputDialog::getText(this, "New Account", "Website:", QLineEdit::Normal, "", &ok);
    if (!ok || website.isEmpty()) return;

    QString password = QInputDialog::getText(this, "New Account", "Password:", QLineEdit::Password, "", &ok);
    if (!ok || password.isEmpty()) return;

    Account newAccount(username.toStdString(), website.toStdString(), password);
    accounts.push_back(newAccount);
    addAccountToTree(newAccount);
}

void MainWindow::addAccountToTree(const Account &account) {
    QTreeWidgetItem *item = new QTreeWidgetItem(accountsTree);
    item->setText(0, QString::fromStdString(account.getWebsite()));
    item->setData(0, Qt::UserRole, QVariant::fromValue(accounts.size() - 1));
    accountsTree->addTopLevelItem(item);
}

void MainWindow::showAccountDetails(QTreeWidgetItem *item, int column) {
    int index = item->data(0, Qt::UserRole).toInt();
    const Account &account = accounts.at(index);

    if (item->childCount() == 0) {
        QTreeWidgetItem *usernameItem = new QTreeWidgetItem();
        usernameItem->setText(0, "Username: " + QString::fromStdString(account.getUsername()));
        item->addChild(usernameItem);

        QTreeWidgetItem *passwordItem = new QTreeWidgetItem();
        passwordItem->setText(0, "Password: " + passwordHidden(account.getPassword()));
        item->addChild(passwordItem);

        QPushButton *decryptButton = new QPushButton("Decrypt Password");
        accountsTree->setItemWidget(passwordItem, 0, decryptButton);
        connect(decryptButton, &QPushButton::clicked, this, [this, passwordItem, account, decryptButton] {
            EncryptionManager em;
            QString decryptedPassword = em.decrypt(account.getPassword());
            passwordItem->setText(0, "Password: " + decryptedPassword);
            accountsTree->setItemWidget(passwordItem, 0, nullptr); // Remove button widget
        });
    }
}

QString MainWindow::passwordHidden(const std::vector<uint64_t>& encryptedPassword) {
    return QString(encryptedPassword.size(), '*');
}
