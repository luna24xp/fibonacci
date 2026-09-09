#include <iostream>

using namespace std;

int factorial(int n) {
    cout << "Calculando factorial(" << n << ")" << endl << endl;

    if (n == 0) {
        cout << "factorial(0) = 1" << endl << endl;
        return 1;
    }

    int prev = factorial(n - 1);
    
    int current = n * prev;

    cout << "factorial(" << n << ") = " << n << " x " << prev << " = " << current << endl << endl;

    return current;
}

int main() {
    int numero;

    cout << "Ingresa un numero entero: ";
    cin >> numero;
    cout << endl;

    if (numero < 0) {
        cout << "El factorial no está definido para números negativos." << endl;
    } else {
        int resultado = factorial(numero);
        
        cout << "El resultado final de factorial(" << numero << ") es: " << resultado << endl;
    }

    return 0;
}
