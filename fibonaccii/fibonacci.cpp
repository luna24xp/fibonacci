#include <iostream>

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    std::cout << "Ingresa un numero n: "; 
    std::cin >> n;
    
    for (int i = 0; i <= n; i++) {
        if (i == n) {
            std::cout << "Fibonacci(" << i << ") = " << fibonacci(i) << "\n";
        } else {
            std::cout << "Fibonacci(" << i << ") = " << fibonacci(i) << "\n";
        }
    }
    
    return 0;
}

