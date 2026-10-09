#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Estructura para registrar los resultados
struct ResultadoBusqueda {
    int posicion;
    int iteraciones;
    bool encontrado;
};


ResultadoBusqueda busquedaBinaria(const vector<int>& arr, int clave) {
    ResultadoBusqueda res = {-1, 0, false};
    int inicio = 0;
    int fin = static_cast<int>(arr.size()) - 1;

    while (inicio <= fin) {
        res.iteraciones++;
        int medio = inicio + (fin - inicio) / 2;

        if (arr[medio] == clave) {
            res.posicion = medio;
            res.encontrado = true;
            return res;
        }
        else if (clave < arr[medio]) {
            fin = medio - 1;
        }
        else {
            inicio = medio + 1;
        }
    }
    return res;
}

// 2. Implementación de Búsqueda Secuencial / Lineal
ResultadoBusqueda busquedaSecuencial(const vector<int>& arr, int clave) {
    ResultadoBusqueda res = {-1, 0, false};
    int n = static_cast<int>(arr.size());

    for (int i = 0; i < n; ++i) {
        res.iteraciones++;
        if (arr[i] == clave) {
            res.posicion = i;
            res.encontrado = true;
            return res;
        }
    }
    return res;
}

void mostrarResultado(int objetivo, const ResultadoBusqueda& res) {
    cout << "Numero buscado: " << objetivo << "\n";
    cout << "Resultado: " << (res.encontrado ? "Encontrado" : "No encontrado") << "\n";
    cout << "Posicion: " << res.posicion << "\n";
    cout << "Iteraciones: " << res.iteraciones << "\n";
    cout << "--------------------------------------\n";
}

int main() {
    cout << "======================================\n";
    cout << "  PRUEBA CON ARREGLO DE MUESTRA (8)   \n";
    cout << "======================================\n\n";

    // Misma lista para ambas comparaciones de muestra
    vector<int> listaMuestra = {38, 12, 57, 4, 91, 26, 73, 15};
    int objetivoMuestra = 73;

    cout << "--- Búsqueda Binaria en lista DESORDENADA ---\n";
    ResultadoBusqueda resBinDes = busquedaBinaria(listaMuestra, objetivoMuestra);
    mostrarResultado(objetivoMuestra, resBinDes);

    // Ordenamos LA MISMA lista en memoria
    sort(listaMuestra.begin(), listaMuestra.end());

    cout << "Lista ordenada: [ ";
    for (int num : listaMuestra) cout << num << " ";
    cout << "]\n\n";

    cout << "--- Búsqueda Binaria en la MISMA lista ORDENADA ---\n";
    ResultadoBusqueda resBinOrd = busquedaBinaria(listaMuestra, objetivoMuestra);
    mostrarResultado(objetivoMuestra, resBinOrd);

    cout << "\n======================================\n";
    cout << "  COMPARACION DE COMPLEJIDAD (N)     \n";
    cout << "  (Ambos métodos usan el mismo vector)\n";
    cout << "======================================\n\n";

    vector<int> tamanos = {100, 1000, 10000, 100000};

    for (int n : tamanos) {

        vector<int> listaBase(n);
        for (int i = 0; i < n; ++i) {
            listaBase[i] = i * 2; // [0, 2, 4, 6, ..., 2*(n-1)]
        }


        int claveExitosa = (n - 2) * 2;      // Penúltimo elemento (existe)
        int claveFallida = (n - 2) * 2 + 1;  // Número impar (no existe)

        ResultadoBusqueda seqExitosa = busquedaSecuencial(listaBase, claveExitosa);
        ResultadoBusqueda binExitosa = busquedaBinaria(listaBase, claveExitosa);

        ResultadoBusqueda seqFallida = busquedaSecuencial(listaBase, claveFallida);
        ResultadoBusqueda binFallida = busquedaBinaria(listaBase, claveFallida);

        cout << ">>> TAMAÑO DEL ARREGLO (N) = " << n << " <<<\n";
        cout << left << setw(24) << "Caso de Búsqueda"
            << setw(20) << "Secuencial (Iter)"
            << setw(20) << "Binaria (Iter)" << "\n";
        cout << string(64, '-') << "\n";
        cout << left << setw(24) << "Exitosa (Penúltimo)"
            << setw(20) << seqExitosa.iteraciones
            << setw(20) << binExitosa.iteraciones << "\n";
        cout << left << setw(24) << "Fallida (Inexistente)"
            << setw(20) << seqFallida.iteraciones
            << setw(20) << binFallida.iteraciones << "\n\n";
    }

    return 0;
}