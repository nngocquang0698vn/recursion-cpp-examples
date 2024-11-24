#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to generate a random array of integers
void generateRandomArray(int arr[], int n, int minVal = 0, int maxVal = 1000000000) {
    std::srand(std::time(nullptr)); // Seed the random number generator
    for (int i = 0; i < n; ++i) {
        arr[i] = minVal + std::rand() % (maxVal - minVal + 1);
    }
}

// Partition function for QuickSort with random pivot selection
int partition(int arr[], int low, int high) {
    // Randomly select a pivot index and move it to the end
    int randomPivotIndex = low + std::rand() % (high - low + 1);
    std::swap(arr[randomPivotIndex], arr[high]);

    int pivot = arr[high]; // Pivot is now at the end
    int i = low - 1;       // Index of the smaller element

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition index

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    printArray(arr, n);

    delete[] arr; // Free the dynamically allocated memory
    return 0;
}
