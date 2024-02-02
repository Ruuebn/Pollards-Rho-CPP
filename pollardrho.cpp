#include "pollardrho.hpp"

pollardrho::pollardrho(unsigned int c, unsigned int reps) :
    m_c { c }, m_reps { reps } {

}

// Same as f(x) = (x^2 + c) % n
void pollardrho::f(mpz_t& x, mpz_t n) {
    mpz_mul(x, x, x);
    mpz_add_ui(x, x, m_c);
    mpz_mod(x, x, n);
    m_c += 1;
}

// mpz init, push back, mpz clear
/*
std::list<mpz_t> pollardrho::find_factors(mpz_t n) {
    std::list<mpz_t> factors;
    mpz_t p, x_1;
    mpz_inits(p, x_1);

    for(unsigned int i = 0; i < m_reps; ++i) {
        m_c += 1;

        for(unsigned int j = 0; j < m_reps; ++j) {
            mpz_set_ui(x_1, j);
            mpz_set_ui(p, pollard_rho_algorithm(n, x_1));

            auto it = std::find(factors.begin(), factors.end(), p);
            //factors.push_back(p);
        }
        
    }

    mpz_clears(p, x_1);
    // Reset constant in case other numbers are to be factored
    m_c = 0;

    return factors;
}*/

unsigned long int pollardrho::pollard_rho_algorithm(mpz_t n, mpz_t x_1) {
    mpz_t x, y, diff, p;
    mpz_inits(x, y, diff, p, NULL);
    mpz_set(x, x_1);
    mpz_set(y, x);

    mpz_set_ui(p, 1);

    // mpz_cmp_ui(op1, op2) returns 0 if op1 == op2
    while(mpz_cmp_ui(p, 1) == 0) {
        f(x, n);
        f(y, n); f(y, n);
        mpz_sub(diff, x, y);
        mpz_gcd(p, diff, n);
    }

    unsigned long int res = mpz_get_ui(p);

    mpz_clears(x, y, diff, p, NULL);

    if(mpz_cmp(p, n) == 0) return res;
    return res;
}