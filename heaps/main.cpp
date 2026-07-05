#include <iostream>
#include <vector>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;            // Initialize largest as root
    int left = 2 * i + 1;       // Left child index
    int right = 2 * i + 2;      // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to build a max-heap from an unordered array
void buildHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to insert a new element into the heap
void insert(vector<int>& arr, int value) {
    arr.push_back(value); // Insert the new element at the end
    int i = arr.size() - 1;

    // Fix the max heap property if it is violated
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to delete the root (maximum element) from the heap
void deleteRoot(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return;

    // Move the last element to root and remove the last element
    arr[0] = arr[n - 1];
    arr.pop_back();

    // Heapify the root element to maintain the max-heap property
    heapify(arr, arr.size(), 0);
}

// Function to perform heap sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build a max-heap
    buildHeap(arr);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move the current root to the end
        swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Utility function to print the array
void printArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};

    cout << "Original array: ";
    printArray(arr);

    buildHeap(arr);
    cout << "Array after building heap: ";
    printArray(arr);

    insert(arr, 15);
    cout << "Array after inserting 15: ";
    printArray(arr);

    deleteRoot(arr);
    cout << "Array after deleting root: ";
    printArray(arr);

    heapSort(arr);
    cout << "Array after heap sort: ";
    printArray(arr);

    return 0;
}
