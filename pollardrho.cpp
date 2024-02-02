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