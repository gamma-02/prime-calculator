#include <iostream>
#include <chrono>
#include <cmath>
#include <immintrin.h>

u_int64_t factorial(u_int64_t input){
    if(input == 0){
        return 1;
    }else{
        return factorial(input-1)*input;
    }
}

bool isPrime(int input){
    u_int64_t inputFac = factorial(input-1)+1;
    u_int64_t result = (inputFac%input);
    return result == 0;
}

int nthPrime(int n){
    int prime = 1;
    int primes = 0;
    while(true){
        int numToTest = prime;

        if(numToTest == 2){
            std::cout << prime << " is prime, continuing..." << std::endl;
            primes++;
            prime++;
            continue;
        }

        if(isPrime(prime)){
            primes++;
            std::cout << prime << " is prime, continuing..." << std::endl;
            if(n == primes){
                return numToTest;
            }
        }
        if((prime+1)%2==0 && prime != 1)
            prime++;
        prime++;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    while(true) {


        std::cout << "Please input a whole number to caclulate the nth prime: " << std::endl;
        int n = 0;
        std::string input;
        bool toBreak = false;
        while (true) {
            try {
                std::cin >> input;
                if (input.find("exit") != std::string::npos)
                    toBreak = true;
                else
                    n = std::stoi(input);


                break;
            } catch (std::exception &e) {
                std::cout << "NOT AN INT! TRY AGAIN: " << std::endl;
            }
        }
        if (toBreak)
            break;
        auto begin1 = std::chrono::high_resolution_clock::now();
        int prime = nthPrime(n);
        auto end1 = std::chrono::high_resolution_clock::now();


        std::cout << "The " << n << (n%10 <= 3 ? (n%10 <= 2  ? n%10 == 1 ? "st" : "nd" : "rd") : "th" ) << " prime is: " << prime << std::endl << "It took " << (end1 - begin1).count()
                  << " nanoseconds." << std::endl;
    }






    return 0;
}
