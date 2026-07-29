#include <stdio.h>

// Structure to pair an element with its original index
struct Element {
    int value;
    int originalIndex;
};

// Insertion Sort adapted to handle the Element structure
void insertionSort(struct Element arr[], int size) {
    for (int i = 1; i < size; i++) {
        struct Element key = arr[i];
        int j = i - 1;

        // Sort based on the integer 'value'
        while (j >= 0 && arr[j].value > key.value) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Binary Search adapted for the Element structure
int binarySearch(struct Element arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid].value == target) {
            return mid; // Returns the index in the SORTED array
        }
        else if (arr[mid].value < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, target, resultIndex, choice;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    struct Element arr[n];

    // 1. Input elements and auto-assign their original index
    printf("Enter %d integers (in ANY order):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].originalIndex = i; 
    }

    // 2. Sort the structures
    insertionSort(arr, n);

    printf("\nEnter the value to find: ");
    scanf("%d", &target);

    // 3. Search using Binary Search
    resultIndex = binarySearch(arr, n, target);

    if (resultIndex != -1) {
        // 4. Print the sorted array for visual reference
        printf("\n--- Array Status ---");
        printf("\nSorted Array Elements: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i].value);
        }
        printf("\nSorted Array Indices:  ");
        for (int i = 0; i < n; i++) {
            printf("%d ", i);
        }
        printf("\n--------------------\n");

        // 5. Menu option
        printf("\nHow would you like to view the index?\n");
        printf("1. Position in the ORIGINAL unsorted array\n");
        printf("2. Position in the NEW sorted array\n");
        printf("3. Display BOTH indices\n");
        printf("Enter your choice (1, 2, or 3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nSuccess: Element %d was originally at index %d.\n", 
                       target, arr[resultIndex].originalIndex);
                break;
            case 2:
                printf("\nSuccess: Element %d is currently at index %d in the sorted array.\n", 
                       target, resultIndex);
                break;
            case 3:
                printf("\nSuccess: Element %d tracking details:\n", target);
                printf(" -> Original Array Index: %d\n", arr[resultIndex].originalIndex);
                printf(" -> Sorted Array Index:   %d\n", resultIndex);
                break;
            default:
                printf("\nInvalid choice. Showing both by default:\n");
                printf("Original Index: %d | Sorted Index: %d\n", 
                       arr[resultIndex].originalIndex, resultIndex);
                break;
        }
    } else {
        printf("\nElement %d not found in the array.\n", target);
    }

    return 0;
}



