#include <stdio.h>

// Function to perform Selection Sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) 
        {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        printf("Sorted array after swapping : ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
    
    printf("\n");
    }
}

// Function to perform Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    (printf("\n"));
}

int main() {
    int size, choice;

    // Get array size from user
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[size];

    // Get array elements from user
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    //select insertion or selection
    printf("\nSelect Sorting Method:\n");
    printf("1. Selection Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Exit\n");
    printf("Enter your choice (1 or 2 or 3): ");
    scanf("%d", &choice);

    printf("\nOriginal array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Execute chosen sorting method
    switch (choice) {
        case 1:
            selectionSort(arr, size);
            printf("Sorted array (Selection Sort): ");
            for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
            break;
        
        case 2:
            insertionSort(arr, size);
            printf("Sorted array (Insertion Sort): ");
            for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
            break;
        case 3:
            printf("exiting");
            return 1;

    return 0;
}
}
