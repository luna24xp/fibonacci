#include <iostream>

using namespace std;

void torresDeHanoi(int n, char origen, char auxiliar, char destino) {
    if (n == 1) {
        cout << "Mover disco 1 de la torre " << origen << " a la torre " << destino << endl;
        return;
    }
    torresDeHanoi(n - 1, origen, destino, auxiliar);
    cout << "Mover disco " << n << " de la torre " << origen << " a la torre " << destino << endl;
    torresDeHanoi(n - 1, auxiliar, origen, destino);
}

int main() {
    int numDiscos;
    
    cout << "Ingrese el numero de discos: ";
    cin >> numDiscos;
    
    if (numDiscos > 0) {
        torresDeHanoi(numDiscos, 'A', 'B', 'C');
    } else {
        cout << "El numero de discos debe ser mayor a 0." << endl;
    }
    
    return 0;
}
