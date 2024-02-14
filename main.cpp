#include <iostream>

#include "pollardrho.hpp"

#ifdef RUN_TESTS

#include "testpollardrho.hpp"

#endif

// Arguments: <number> <reps> where <number> is the number to be factored
// and <reps> is the amount of times to try and find factors
// if you want test cases to be run, simply add the -DRUN_TESTS
// flag when compiling

int main(int argc, char** argv) {

    if(argc < 3) {
        std::cerr << "Not enough arguments. Usage: " << argv[0] << " <number> <reps>\n";
        return 1;
    }

// Runs tests on initialization if compiler flag is set
#ifdef RUN_TESTS
    testPollardRho test = testPollardRho();
#endif
    
    unsigned int REPS = std::stoi(argv[2]);

    pollardrho pr(1, REPS);
    mpz_t num, x_1;
    // mpz_inits is NULL-terminated
    mpz_inits(num, x_1, NULL);
    mpz_set_str(num, argv[1], 10);
    mpz_set_ui(x_1, 1);

    gmp_printf("NUM to be factored: %Zd\n", num);
    gmp_printf("With amount of REPS: %lu\n", REPS);
    
    std::vector<unsigned long int> factors = pr.find_factors(num, x_1);

    std::cout << "Factors size: " << factors.size() << std::endl;

    std::cout << "Factors found: ";
    for(size_t i = 0; i < factors.size(); ++i) {
        if(i + 1 == factors.size()) {
            std::cout << factors[i] << std::endl;
            break;
        }
        std::cout << factors[i] << ", ";
    }
    
    // mpz_clears is NULL-terminated
    mpz_clears(num, x_1, NULL);


    return 0;
}