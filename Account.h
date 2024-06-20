// Account.h

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include <QString>
#include "EncryptionManager.h"

class Account {
public:
    Account(const std::string &username, const std::string &website, const QString &password);

    std::string getUsername() const;
    std::string getWebsite() const;
    std::vector<uint64_t> getPassword() const;

    void setUsername(const std::string &username);
    void setWebsite(const std::string &website);
    void setPassword(const QString &password);

private:
    std::string username;
    std::string website;
    std::vector<uint64_t> password;
};

#endif // ACCOUNT_H
