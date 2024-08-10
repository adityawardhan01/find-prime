
#include <iostream>
#include <vector>

void findPrimes(int n) {
    if (n < 2) {
        std::cout << "No primes less than 2." << std::endl;
        return;
    }

    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    std::cout << "Prime numbers up to " << n << " are:" << std::endl;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int number;
    std::cout << "Enter an integer: ";
    std::cin >> number;

    findPrimes(number);

    return 0;
}
