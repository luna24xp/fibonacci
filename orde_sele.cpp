#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }

        cout << "Pasada " << i + 1 << ":" << endl << endl;
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl << endl;
    }
}

int main() {
    int arr[] = {32, 12, 3, 8, 45, 20, 64};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    return 0;
}
