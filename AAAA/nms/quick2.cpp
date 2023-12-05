#include <iostream>
#include <cstdlib> // Include for rand() function
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
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[n];

    // Generating random elements for the array
    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000; // Generating random numbers between 0 to 999

    cout << "Input Array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    quicksort(a, 0, n - 1);

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
