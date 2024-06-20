#include "AuthenticationManager.h"

uint64_t AuthenticationManager::hashedPassword = 431473073579924274;

bool AuthenticationManager::verifyPassword(QString &password) {
    if(hashPassword(password) == hashedPassword) {
        return true;
    }
    return false;
}


void AuthenticationManager::setPassword(QString &password) {
    hashedPassword = hashPassword(password);
}

static inline uint64_t rotate64(uint64_t data, int k) {
    return ( data << k ) | (data >> (64 - k));
}

uint64_t AuthenticationManager::hashPassword(QString &password) {
    const uint64_t seed =  password.at(2).toLatin1();
    size_t length = password.size();

    const uint64_t prime1 = 0x16DB3A5B72CA447ull;
    const uint64_t prime2 = 0x6475E84C0578ABB9ull;
    const uint64_t prime3 = 0x79FB5F167AC593B1ull;
    const uint64_t prime4 = 0x744B6EDD2888E81ull;

    QByteArray passwordByteArray = password.toUtf8();
    const uint8_t *ptr = reinterpret_cast<const uint8_t *>(passwordByteArray.constData());

    uint64_t hash = seed ^ (length * prime1);

    while(length >= 8) {
        uint64_t k = *reinterpret_cast<const uint64_t *>(ptr);
        k*=prime2;
        k = rotate64(k, 31);
        k*=prime3;
        hash^=k;
        hash = rotate64(hash, 27) * prime1 + prime4;
        ptr+=8;
        length-=8;
    }

    if(length > 0) {
        uint64_t k = 0;
        for(size_t i = 0; i < length; ++i) {
            k<<=8;
            k |= ptr[i];
        }
        k*=prime2;
        k = rotate64(k, 31);
        k *= prime3;
        hash ^= k;
        hash = rotate64(hash, 27) * prime1 + prime4;
    }

    hash ^= hash >> 33;
    hash *= prime1;
    hash ^= hash >> 29;
    hash *= prime2;
    hash ^= hash >> 32;
    return hash;

}








