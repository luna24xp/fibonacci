#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <algorithm>

struct Metric {
    double tiempoMs = 0.0;
    long long comparaciones = 0;
    long long movimientos = 0;
};

Metric bubbleSort(std::vector<int> arr) {
    Metric m;
    auto start = std::chrono::high_resolution_clock::now();
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        bool huboIntercambio = false;
        for (int j = 0; j < n - i - 1; ++j) {
            m.comparaciones++;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                m.movimientos++;
                huboIntercambio = true;
            }
        }
        if (!huboIntercambio) break;
    }

    auto end = std::chrono::high_resolution_clock::now();
    m.tiempoMs = std::chrono::duration<double, std::milli>(end - start).count();
    return m;
}

Metric insertionSort(std::vector<int> arr) {
    Metric m;
    auto start = std::chrono::high_resolution_clock::now();
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int clave = arr[i];
        int j = i - 1;
        
        while (j >= 0) {
            m.comparaciones++;
            if (arr[j] > clave) {
                arr[j + 1] = arr[j];
                m.movimientos++; // Desplazamiento
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = clave;
        m.movimientos++; // Colocación de la clave en su lugar
    }

    auto end = std::chrono::high_resolution_clock::now();
    m.tiempoMs = std::chrono::duration<double, std::milli>(end - start).count();
    return m;
}

Metric selectionSort(std::vector<int> arr) {
    Metric m;
    auto start = std::chrono::high_resolution_clock::now();
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            m.comparaciones++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            std::swap(arr[i], arr[minIdx]);
            m.movimientos++;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    m.tiempoMs = std::chrono::duration<double, std::milli>(end - start).count();
    return m;
}

void merge(std::vector<int>& arr, int l, int m, int r, Metric& metric) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) {
        L[i] = arr[l + i];
        metric.movimientos++;
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[m + 1 + j];
        metric.movimientos++;
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        metric.comparaciones++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        metric.movimientos++;
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        metric.movimientos++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        metric.movimientos++;
    }
}

void mergeSortHelper(std::vector<int>& arr, int l, int r, Metric& metric) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortHelper(arr, l, m, metric);
        mergeSortHelper(arr, m + 1, r, metric);
        merge(arr, l, m, r, metric);
    }
}

Metric mergeSort(std::vector<int> arr) {
    Metric m;
    auto start = std::chrono::high_resolution_clock::now();
    
    mergeSortHelper(arr, 0, arr.size() - 1, m);

    auto end = std::chrono::high_resolution_clock::now();
    m.tiempoMs = std::chrono::duration<double, std::milli>(end - start).count();
    return m;
}

int partition(std::vector<int>& arr, int low, int high, Metric& metric) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; ++j) {
        metric.comparaciones++;
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
            metric.movimientos++;
        }
    }
    std::swap(arr[i + 1], arr[high]);
    metric.movimientos++;
    return (i + 1);
}

void quickSortHelper(std::vector<int>& arr, int low, int high, Metric& metric) {
    if (low < high) {
        int pi = partition(arr, low, high, metric);
        quickSortHelper(arr, low, pi - 1, metric);
        quickSortHelper(arr, pi + 1, high, metric);
    }
}

Metric quickSort(std::vector<int> arr) {
    Metric m;
    auto start = std::chrono::high_resolution_clock::now();
    
    if (!arr.empty()) {
        quickSortHelper(arr, 0, arr.size() - 1, m);
    }

    auto end = std::chrono::high_resolution_clock::now();
    m.tiempoMs = std::chrono::duration<double, std::milli>(end - start).count();
    return m;
}

std::vector<int> generarArregloAleatorio(int n) {
    std::vector<int> arr(n);
    std::mt19937 gen(42); // Semilla fija para comparar los mismos datos en cada algoritmo
    std::uniform_int_distribution<> dis(1, 100000);
    for (int i = 0; i < n; ++i) {
        arr[i] = dis(gen);
    }
    return arr;
}

void imprimirFila(const std::string& algoritmo, int n, const Metric& m) {
    std::cout << std::left << std::setw(15) << algoritmo
            << std::setw(10) << n
            << std::setw(15) << std::fixed << std::setprecision(4) << m.tiempoMs
            << std::setw(20) << m.comparaciones
            << std::setw(20) << m.movimientos << "\n";
}

int main() {
    std::vector<int> tamanos = {100, 500, 1000, 5000, 10000};

    std::cout << "========================================================================================\n";
    std::cout << "                        COMPARATIVA DE METODOS DE ORDENAMIENTO                         \n";
    std::cout << "========================================================================================\n";
    std::cout << std::left << std::setw(15) << "Algoritmo"
            << std::setw(10) << "N"
            << std::setw(15) << "Tiempo (ms)"
            << std::setw(20) << "Comparaciones"
            << std::setw(20) << "Movimientos" << "\n";
    std::cout << "----------------------------------------------------------------------------------------\n";

    for (int n : tamanos) {
        std::vector<int> datosBase = generarArregloAleatorio(n);

        imprimirFila("Burbuja", n, bubbleSort(datosBase));
        imprimirFila("Insercion", n, insertionSort(datosBase));
        imprimirFila("Seleccion", n, selectionSort(datosBase));
        imprimirFila("Mezcla", n, mergeSort(datosBase));
        imprimirFila("QuickSort", n, quickSort(datosBase));
        std::cout << "----------------------------------------------------------------------------------------\n";
    }

    return 0;
}