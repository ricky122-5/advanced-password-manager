//
// Created by Rikki on 6/8/2024.
//

#include "Account.h"

Account::Account(const std::string &username, const std::string &website, const QString &password)
    : username(username), website(website) {
    this->password = EncryptionManager::encrypt(password);
}

std::string Account::getUsername() const {
    return username;
}

std::string Account::getWebsite() const {
    return website;
}

std::vector<uint64_t> Account::getPassword() const {
    return password;
}

void Account::setUsername(const std::string &username) {
    this->username = username;
}

void Account::setWebsite(const std::string &website) {
    this->website = website;
}

void Account::setPassword(const QString &password) {
    this->password = EncryptionManager::encrypt(password);
}
