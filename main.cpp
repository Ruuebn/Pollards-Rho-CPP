#include <iostream>

#include "pollardrho.hpp"

int main(int argc, char** argv) {

    pollardrho pr(5, 10);
    mpz_t num, x_1;
    // mpz_inits is NULL-terminated
    mpz_inits(num, x_1, NULL);
    mpz_set_ui(num, 60);
    mpz_set_ui(x_1, 1);

    for(unsigned int i = 0; i < 100; ++i) {
        gmp_printf("Factor for num: %lu\n", pr.pollard_rho_algorithm(num, x_1));
    }

    
    // mpz_clears is NULL-terminated
    mpz_clears(num, x_1, NULL);

    return 0;
}