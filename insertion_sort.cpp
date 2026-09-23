#include <iostream>

void mostrarArreglo(const int numeros[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << numeros[i] << " ";
    }
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int numeros[] = {7, 3, 8, 2, 6, 4, 5};
    constexpr int n = 7;

    std::cout << "Arreglo original:\n";
    mostrarArreglo(numeros, n);

    int comparaciones = 0, desplazamientos = 0, inserciones = 0;

    for (int i = 1; i < n; ++i) {
        int key = numeros[i];
        int j = i - 1;

        std::cout << "\nInsertando: " << key << '\n';

        for (; j >= 0; --j) {
            ++comparaciones;
            if (numeros[j] <= key) break;
            numeros[j + 1] = numeros[j];
            ++desplazamientos;
        }

        numeros[j + 1] = key;
        ++inserciones;

        mostrarArreglo(numeros, n);
    }

    std::cout << "\n========================================\n"
            << "       ESTADISTICAS\n"
            << "========================================\n"
            << "Comparaciones: " << comparaciones << '\n'
            << "Desplazamientos: " << desplazamientos << '\n'
            << "Inserciones: " << inserciones << '\n';

    return 0;
}
