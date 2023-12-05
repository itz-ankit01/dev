#include <iostream>
#include <fstream> // For file handling
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[], int l, int h) {
    int pivot = a[l];
    int i = l, j = h;
    do {
        do { i++; } while (a[i] <= pivot);
        do { j--; } while (a[j] > pivot);
        if (i < j)
            swap(&a[i], &a[j]);
    } while (i < j);

    swap(&a[l], &a[j]);
    return j;
}

void quicksort(int a[], int l, int h) {
    int j;
    if (l < h) {
        j = partition(a, l, h);
        quicksort(a, l, j);
        quicksort(a, j + 1, h);
    }
}

int main() {
    ifstream inputFile("input.txt"); // Open input file
    if (!inputFile.is_open()) {
        cout << "Unable to open file";
        return 1;
    }

    int n;
    inputFile >> n; // Read the size of the array
    int a[n];

    // Read elements from the file into the array
    for (int i = 0; i < n; i++)
        inputFile >> a[i];

    inputFile.close(); // Close the file

    // Sorting the array
    quicksort(a, 0, n - 1);

    // Output the sorted array
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
