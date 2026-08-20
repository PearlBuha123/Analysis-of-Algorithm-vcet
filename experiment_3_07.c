#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high, int size) {
    int pivot = arr[high];
    printf("  -> Choose pivot: %d at index %d\n", pivot, high);
    
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            printf("  -> Swap %d and %d: ", arr[i], arr[j]);
            printArray(arr, size);
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    printf("  -> Place pivot in correct spot by swapping %d and %d: ", arr[i + 1], arr[high]);
    printArray(arr, size);
    
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int size) {
    if (low < high) {
        printf("-> Sub-array from index %d to %d: ", low, high);
        printArray(arr, size);
        
        int pi = partition(arr, low, high, size);
        
        printf("-> Pivot placed at index %d\n", pi);
        quickSort(arr, low, pi - 1, size);
        quickSort(arr, pi + 1, high, size);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nInitial array: ");
    printArray(arr, n);
    printf("\n--- Execution Steps ---\n");
    
    quickSort(arr, 0, n - 1, n);
    
    printf("\nSorted array: ");
    printArray(arr, n);
    return 0;
}
