# Pollards-Rho-CPP
A C++ repository for an implementation of Pollard's Rho algorithm with GMP

## Development environment
The software used for making this repository is an Ubuntu terminal, and Visual Code. I installed GMP by running `sudo apt-get install libgmp3-dev` in the terminal. If you want to do something similar, or are looking to use GMP yourself, I highly recommend using a similar OS.

## Purpose of this repository
During my semester at uni, I had a project to implement Pollard's Rho algorithm in Python. That made me want to implement it in C++ as well, and to try new things by including a library I haven't used before. I also plan to make unit tests to learn something new.

## TODO:
- [ ] RAII-based initialization for `mpz_t` types.
- [ ] Random Number Generator to pass into the factorization class
- [ ] Test cases