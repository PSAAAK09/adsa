/*EXPERMENT.NO:6

Implement Quick sort and Merge sort and observe the execution time for various input sizes (Average, Worst and Best cases).

AIM: - To perform  Implement Quick sort and Merge sort and observe the execution time for various input sizes (Average, Worst and Best cases).

THEORY:-
To measure the execution time for different input sizes and cases, you can use the clock() function from the <ctime> library. 

PROGRAM:-
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to perform Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
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

// Function to perform Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to generate random array
vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
    }
    return arr;
}

// Function to measure execution time
void measureExecutionTime(void (*sortFunc)(vector<int>&, int, int), vector<int> arr, const string& caseType) {
    auto start = high_resolution_clock::now();
    sortFunc(arr, 0, arr.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << caseType << " case execution time: " << duration.count() << " microseconds" << endl;
}

int main() {
    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};

    for (int size : sizes) {
        cout << "Array size: " << size << endl;

        // Average case
        vector<int> arr = generateRandomArray(size);
        measureExecutionTime(quickSort, arr, "Quick Sort Average");
        measureExecutionTime(mergeSort, arr, "Merge Sort Average");

        // Worst case for Quick Sort (sorted array)
        sort(arr.begin(), arr.end());
        measureExecutionTime(quickSort, arr, "Quick Sort Worst");

        // Best case for Quick Sort (sorted array)
        measureExecutionTime(quickSort, arr, "Quick Sort Best");

        // Worst case for Merge Sort (no specific worst case, same as average)
        measureExecutionTime(mergeSort, arr, "Merge Sort Worst");

        // Best case for Merge Sort (no specific best case, same as average)
        measureExecutionTime(mergeSort, arr, "Merge Sort Best");

        cout << endl;
    }

    return 0;
}