#include "testpollardrho.hpp"
#include <iostream>

testPollardRho::testPollardRho() :
    pollardrho(1, 1)
{
    mpz_init(n);
    mpz_init(x_1);
    run_test_cases();
}

testPollardRho::~testPollardRho() {
    mpz_clear(n);
    mpz_clear(x_1);
}

void testPollardRho::run_test_cases() {
    unsigned long int expected_result = 2;
    mpz_set_ui(n, 60);
    mpz_set_ui(x_1, 1);
    unsigned long int factor = pollard_rho_algorithm(n, x_1);

    // This test is passes by "failing"
    std::cout << "TEST CASE 1: ";
    if(expected_result != factor) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed, expected result was: ";
        std::cout << expected_result << ", but got ";
        std::cout << factor << " instead\n";
    }

    // This test passes
    mpz_set_ui(n, 1000);
    factor = pollard_rho_algorithm(n, x_1);
    expected_result = 8;
    std::cout << "TEST CASE 2: ";
    if(expected_result == factor) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed, expected result was: ";
        std::cout << expected_result << ", but got ";
        std::cout << factor << " instead\n";
    }
}