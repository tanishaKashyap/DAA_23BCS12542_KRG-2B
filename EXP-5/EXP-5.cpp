#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;


int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


vector<int> generateRandomNumbers(int n, int range=10000) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % range;
    }
    return arr;
}


int main() {
    srand(time(0));

    vector<int> sizes = {1000, 5000, 10000, 50000, 100000}; 

    for (int n : sizes) {
        vector<int> arr = generateRandomNumbers(n);

        auto start = high_resolution_clock::now();
        quickSort(arr, 0, arr.size() - 1);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end - start);
        cout << "Time taken to sort " << n << " elements: "
             << duration.count() / 1000.0 << " milliseconds" << endl;
    }

    return 0;
}
