#include <iostream>
using namespace std;

int main() {
    const int MAX = 20;   // capacidad maxima del arreglo
    int arr[MAX];
    int n;

    // Tamaño del arreglo
    cout << "Cuantos elementos tendra el arreglo (1 a " << MAX << ")? ";
    cin >> n;

    // Captura de los elementos
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Mostrar los elementos
    cout << "\nElementos del arreglo: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Suma, promedio, mayor y menor
    int suma = 0;
    int mayor = arr[0];
    int menor = arr[0];

    for (int i = 0; i < n; i++) {
        suma = suma + arr[i];
        if (arr[i] > mayor) mayor = arr[i];
        if (arr[i] < menor) menor = arr[i];
    }

    double promedio = (double)suma / n;

    cout << "\nSuma     : " << suma << endl;
    cout << "Promedio : " << promedio << endl;
    cout << "Mayor    : " << mayor << endl;
    cout << "Menor    : " << menor << endl;

    // Buscar un numero
    int buscado;
    int posicion = -1;

    cout << "\nQue numero desea buscar? ";
    cin >> buscado;

    for (int i = 0; i < n; i++) {
        if (arr[i] == buscado) {
            posicion = i;
            break;
        }
    }

    if (posicion != -1)
        cout << "El numero " << buscado << " SI fue encontrado en la posicion "
            << posicion + 1 << endl;
    else
        cout << "El numero " << buscado << " NO fue encontrado" << endl;

    // Mostrar el arreglo en orden inverso
    cout << "\nArreglo en orden inverso: ";
    for (int i = n - 1; i >= 0; i--)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}