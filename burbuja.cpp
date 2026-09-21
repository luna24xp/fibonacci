#include <iostream>

using namespace std;

void burbuja(int numeros[], int n, int &comparaciones, int &intercambios) {
    for (int i = 0; i < n - 1; i++) {
        bool intercambio = false;
        
        for (int j = 0; j < n - i - 1; j++) {
            comparaciones++;
            if (numeros[j] > numeros[j + 1]) {
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
                intercambios++;
                intercambio = true;
            }
        }
        
        cout << "Pasada " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << numeros[k] << (k == n - 1 ? "" : " ");
        }
        cout << "\n";
        
        if (!intercambio) {
            break;
        }
    }
}

int main() {
    int arr[] = {7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparaciones = 0;
    int intercambios = 0;

    cout << "Arreglo original: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n\n";

    burbuja(arr, n, comparaciones, intercambios);

    cout << "\nArreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n\n";

    cout << "Elementos: " << n << "\n\n";
    cout << "Comparaciones: " << comparaciones << "\n";
    cout << "Intercambios: " << intercambios << "\n";

    return 0;
}
