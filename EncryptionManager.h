#ifndef ENCRYPTIONMANAGER_H
#define ENCRYPTIONMANAGER_H

#include <cstdint>
#include <QString>
#include <vector>

class EncryptionManager {
public:
    static std::vector<uint64_t> encrypt(const QString &password);
    static QString decrypt(const std::vector<uint64_t> &encryptedPasswordVector);

private:
    static uint64_t gcd(uint64_t a, uint64_t b);
    static uint64_t mod_exp(uint64_t base, uint64_t exp, uint64_t mod);
    static void generate_keys(uint64_t &n, uint64_t &e, uint64_t &d);

    static uint64_t p;
    static uint64_t q;
    static uint64_t n;
    static uint64_t e;
    static uint64_t d;
};

#endif // ENCRYPTIONMANAGER_H
