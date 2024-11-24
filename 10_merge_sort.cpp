#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

// Function to generate a random array of integers
void generateRandomArray(int arr[], int n, int minVal = 0, int maxVal = 1000000000) {
    std::srand(std::time(nullptr)); // Seed the random number generator
    for (int i = 0; i < n; ++i) {
        arr[i] = minVal + std::rand() % (maxVal - minVal + 1);
    }
}

// Merge function to merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    // Create temporary arrays
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    // Copy any remaining elements of leftArr[]
    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    // Copy any remaining elements of rightArr[]
    while (j < n2) {
        arr[k++] = rightArr[j++];
    }

    // Free dynamically allocated memory
    delete[] leftArr;
    delete[] rightArr;
}

// MergeSort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print the array
void printArray(const int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Main function
int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    int* arr = new int[n]; // Dynamically allocate the array
    generateRandomArray(arr, n);

    std::cout << "Unsorted array: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    printArray(arr, n);

    delete[] arr; // Free the dynamically allocated memory
    return 0;
}
