#pragma once

#include <gmpxx.h>
#include <vector>

class pollardrho {
protected:
    unsigned long int pollard_rho_algorithm(mpz_t n, mpz_t x_1);
private:
    // Amount of repetitions, scales complexity quadratically
    // because both c and x_1 is incremented by themselves
    unsigned int m_reps;
    // Constant c to use within f
    unsigned int m_c;
    // External function f to use
    void f(mpz_t& x, mpz_t n);
    // The infamous algorithm
public:
    std::vector<unsigned long int> find_factors(mpz_t n, mpz_t x_1);
    pollardrho(unsigned int c, unsigned int reps);
};