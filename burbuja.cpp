#include <iostream>

using namespace std;


void burbuja(int numeros[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool intercambio = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
                intercambio = true;
            }
        }
        if (!intercambio) {
            break;
        }
    }
}

// Punto de entrada requerido por el compilador
int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    burbuja(arr, n);

    cout << "Arreglo ordenado: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}

