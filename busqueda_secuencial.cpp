#include <iostream>
using namespace std;

int busquedaSecuencial(int numeros[], int n, int buscado, int &comparaciones) {
    comparaciones = 0;

    for (int i = 0; i < n; i++) {
        comparaciones++;

        if (numeros[i] == buscado) {
            return i;
        }
    }

    return -1;
}

void busquedaMultiple(int numeros[], int n, int buscado) {
    bool encontrado = false;

    for (int i = 0; i < n; i++) {
        if (numeros[i] == buscado) {
            cout << "elemento encontrado en la posicion "
                << i << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "elemento no encontrado" << endl;
    }
}

int main() {
    int numeros[] = {12, 25, 41, 56, 68, 70, 73, 89, 95};
    int n = 9;
    int buscado = 73;
    int comparaciones;

    int posicion = busquedaSecuencial(numeros, n, buscado, comparaciones);

    cout << "elemento buscado: " << buscado << endl;

    if (posicion != -1) {
        cout << "resultado: Encontrado" << endl;
        cout << "posicion: " << posicion << endl;
    } else {
        cout << "resultado: No encontrado" << endl;
    }

    cout << "comparaciones: " << comparaciones << endl;

    cout << endl;

    int numeros2[] = {73, 25, 73, 41, 73, 68, 90, 73};
    int n2 = 8;

    busquedaMultiple(numeros2, n2, buscado);

    return 0;
}