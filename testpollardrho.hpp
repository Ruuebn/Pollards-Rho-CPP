#pragma once
#include "pollardrho.hpp"
#include <gmpxx.h>

class testPollardRho : protected pollardrho {
private:
    mpz_t n;
    mpz_t x_1;
    void run_test_cases();
public:
    testPollardRho();
    ~testPollardRho();
};