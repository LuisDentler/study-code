#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[4] = {7,3,9,4};
    int n = 4;

    for (int i = 0; i < n - 1; i++) {
        // -i eingefügt
        for (int j = 0; j < n - 1-i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                //Wechsel 
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                std::cout <<"gewechselt: ";
            }
            printArray(arr, n);
        }
    }

    return 0;
}