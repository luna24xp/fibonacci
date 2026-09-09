#include <iostream>
using namespace std;

int main() {
    int m[50][50], filas, columnas;

    cout << "Numero de filas: ";
    cin >> filas;
    cout << "Numero de columnas: ";
    cin >> columnas;

    // Captura
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> m[i][j];
        }

    // Mostrar la matriz
    cout << "\nMatriz:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++)
            cout << m[i][j] << "\t";
        cout << "\n";
    }

    // Suma total, mayor y menor
    int suma = 0, mayor = m[0][0], menor = m[0][0];
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++) {
            suma += m[i][j];
            if (m[i][j] > mayor) mayor = m[i][j];
            if (m[i][j] < menor) menor = m[i][j];
        }

    cout << "\nSuma total: " << suma;
    cout << "\nPromedio: " << (float)suma / (filas * columnas);
    cout << "\nMayor: " << mayor;
    cout << "\nMenor: " << menor << "\n";

    // Suma de cada fila
    cout << "\nSuma de cada fila:\n";
    for (int i = 0; i < filas; i++) {
        int s = 0;
        for (int j = 0; j < columnas; j++)
            s += m[i][j];
        cout << "Fila " << i << ": " << s << "\n";
    }

    // Suma de cada columna
    cout << "\nSuma de cada columna:\n";
    for (int j = 0; j < columnas; j++) {
        int s = 0;
        for (int i = 0; i < filas; i++)
            s += m[i][j];
        cout << "Columna " << j << ": " << s << "\n";
    }

    return 0;
}