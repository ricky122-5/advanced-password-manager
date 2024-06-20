#include "EncryptionManager.h"
#include <stdexcept>
#include <cmath>
#include <vector>
#include <iostream>
#include <cstring>

uint64_t EncryptionManager::p = 20;  // Example large prime
uint64_t EncryptionManager::q = 107;  // Example large prime
uint64_t EncryptionManager::n = 0;
uint64_t EncryptionManager::e = 0;
uint64_t EncryptionManager::d = 0;

uint64_t EncryptionManager::gcd(uint64_t a, uint64_t b) {
    while (b != 0) {
        uint64_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

uint64_t EncryptionManager::mod_exp(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp >> 1;
    }
    return result;
}

void EncryptionManager::generate_keys(uint64_t &n, uint64_t &e, uint64_t &d) {
    n = p * q;
    uint64_t phi = (p - 1) * (q - 1);

    // Choose e
    e = 3;
    while (gcd(e, phi) != 1) {
        e += 2;
    }

    // Compute d
    uint64_t k = 1;
    while ((1 + k * phi) % e != 0) {
        ++k;
    }
    d = (1 + k * phi) / e;
}

std::vector<uint64_t> EncryptionManager::encrypt(const QString &password) {
    if (n == 0 || e == 0 || d == 0) {
        generate_keys(n, e, d);
    }
    std::vector<uint64_t> encryptedPasswordVector;
    std::string strPassword = password.toStdString();
    for (char c : strPassword) {
        encryptedPasswordVector.push_back(mod_exp(static_cast<uint64_t>(static_cast<uint8_t>(c)), e, n));
    }
    return encryptedPasswordVector;
}

QString EncryptionManager::decrypt(const std::vector<uint64_t> &encryptedPasswordVector) {
    if (n == 0 || e == 0 || d == 0) {
        generate_keys(n, e, d);
    }
    std::string decryptedPassword;
    for (uint64_t c : encryptedPasswordVector) {
        decryptedPassword.push_back(static_cast<char>(mod_exp(c, d, n)));
    }
    return QString::fromStdString(decryptedPassword);
}
