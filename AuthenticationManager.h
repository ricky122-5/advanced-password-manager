//
// Created by Rikki on 6/7/2024.
//

#ifndef AUTHENTICATIONMANAGER_H
#define AUTHENTICATIONMANAGER_H
#include <QString>


class AuthenticationManager {
    static uint64_t hashedPassword;
public:
    static bool verifyPassword(QString &password);

    static void setPassword(QString &password);

private:
    static uint64_t hashPassword(QString &password);


};

#endif //AUTHENTICATIONMANAGER_H
