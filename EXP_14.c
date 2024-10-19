#include <stdio.h>

// Function prototypes
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void display(int arr[], int n);
void swap(int* a, int* b);

int main() {
    int n, choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n1. Merge Sort\n2. Quick Sort\n3. Display Array\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                mergeSort(arr, 0, n - 1); 
                printf("Sorted using Merge Sort.\n");
                display(arr, n);  // Display sorted array
                break;
            case 2: 
                quickSort(arr, 0, n - 1); 
                printf("Sorted using Quick Sort.\n");
                display(arr, n);  // Display sorted array
                break;
            case 3: 
                display(arr, n); 
                break;
            case 4: 
                return 0;
            default: 
                printf("Invalid choice. Select 1-4.\n");
        }
    }
}

void merge(int arr[], int left, int mid, int right) {
    int sizeFirst = mid - left + 1, sizeSecond = right - mid;
    int firstArr[sizeFirst], secondArr[sizeSecond];

    for (int i = 0; i < sizeFirst; i++) firstArr[i] = arr[left + i];
    for (int j = 0; j < sizeSecond; j++) secondArr[j] = arr[mid + 1 + j];

    for (int i = 0, j = 0, k = left; k <= right; k++) {
        if (i < sizeFirst && (j >= sizeSecond || firstArr[i] <= secondArr[j])) {
            arr[k] = firstArr[i++];
        } else {
            arr[k] = secondArr[j++];
        }
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[++i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void display(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void swap(int* a, int* b) {
    int temp = *a; *a = *b; *b = temp;
}

