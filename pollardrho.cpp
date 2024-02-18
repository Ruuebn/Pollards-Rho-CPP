#include "pollardrho.hpp"

pollardrho::pollardrho(unsigned int c, unsigned int reps) :
    m_c { c }, m_reps { reps } {

}

// Same as f(x) = (x^2 + c) % n
void pollardrho::f(mpz_t& x, mpz_t n) {
    mpz_mul(x, x, x);
    mpz_add_ui(x, x, m_c);
    mpz_mod(x, x, n);
}

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

        // diff := x - y
        mpz_sub(diff, x, y);
        mpz_gcd(p, diff, n);
    }

    unsigned long int res = mpz_get_ui(p);

    mpz_clears(x, y, diff, p, NULL);

    // Returns -1 if n == res. Rarely happens, but
    // just represents an invalid result.
    if(mpz_cmp_ui(n, res) == 0) return -1;
    return res;
}

// Will do the amount of reps to find factors (unique but might share common factors)
std::vector<unsigned long int> pollardrho::find_factors(mpz_t n, mpz_t x_1) {
    std::vector<unsigned long int> factors;

    for(size_t i = 0; i < m_reps; ++i) {
        for(size_t j = 0; j < m_reps; ++j) {
            unsigned long int res = pollard_rho_algorithm(n, x_1);

            // Finds out if the factor found already exists
            auto it = std::find(factors.begin(), factors.end(), res);
            if(it == factors.end()) factors.push_back(res);

            mpz_add_ui(x_1, x_1, 1);
        }
        m_c += 1;
    }

    return factors;
}