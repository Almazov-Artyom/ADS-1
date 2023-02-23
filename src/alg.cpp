// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"


bool checkPrime(uint64_t value) {
    bool flag = true;
    for (int i = 2; i <= pow(value, 0.5); ++i) {
        if (!(value % i)) {
            flag = false;
            break;
        }
    }
    return flag;
}

uint64_t nPrime(uint64_t n) {
    int a = 1;
    int b = 2;
    while (a <= n) {
        if (checkPrime(b)) {
            a++;
        }
        if (a > n) {
            break;
        }
        b++;
    }
    return b;
}

uint64_t nextPrime(uint64_t value) {
    if (checkPrime(value + 1)) {
        return value + 1;
    } else {
        return nextPrime(value + 1);
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    uint64_t h = 2;
    while (h < hbound) {
        sum += h;
        h = nextPrime(h);
    }
    return sum;
}
