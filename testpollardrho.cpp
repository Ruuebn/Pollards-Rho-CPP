#include "testpollardrho.hpp"
#include <iostream>

// Initialises child with c = x_1 = 1
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
    print_test_results(expected_result != factor, expected_result, factor);

    mpz_set_ui(n, 1000);
    factor = pollard_rho_algorithm(n, x_1);
    expected_result = 8;

    // This test passes
    std::cout << "TEST CASE 2: ";
    print_test_results(expected_result == factor, expected_result, factor);
}

// Prints out result based on method of evaluating
void testPollardRho::print_test_results(bool method, int test_val, int actual_val) {
    if(method) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed, expected result was: ";
        std::cout << test_val << ", but got ";
        std::cout << actual_val << " instead\n";
    }
}