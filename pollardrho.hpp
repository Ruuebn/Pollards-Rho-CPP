#pragma once

#include <gmpxx.h>
#include <list>

class pollardrho {
private:
    // Amount of repetitions, scales complexity quadratically
    unsigned int m_reps;
    // Constant c to use within f
    unsigned int m_c;
    // External function f to use
    void f(mpz_t& x, mpz_t n);
    // The infamous algorithm
    
public:
    // Function to find factors for n given c and amount of reps
    //std::list<mpz_t> find_factors(mpz_t n);

    unsigned long int pollard_rho_algorithm(mpz_t n, mpz_t x_1);

    pollardrho(unsigned int c, unsigned int reps);
};