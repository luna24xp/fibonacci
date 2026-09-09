#include <iostream>
#include <limits> 
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

    while (true) {
        cout << "Ingresa un numero entero: ";
        cin >> numero;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Valor no valido. Debes ingresar un numero entero. Intentalo de nuevo." << endl << endl;
        } 
        else if (numero < 0) {
            cout << "Valor no valido. No se aceptan numeros negativos. Intentalo de nuevo." << endl << endl;
        } 
        else {
            cout << endl;
            break; 
        }
    }

    int resultado = factorial(numero);
    
    cout << "El resultado final de factorial(" << numero << ") es: " << resultado << endl;

    return 0;
}
