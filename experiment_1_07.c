#include <stdio.h>

// Function to print array
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Insertion Sort with Steps
void insertionSort(int array[], int size)
{
    int key, j;

    printf("\nINSERTION SORT\n");

    for(int i = 1; i < size; i++)
    {
        key = array[i];
        j = i;

        printf("\nPass %d:\n", i);
        printf("Key = %d\n", key);

        while(j > 0 && array[j-1] > key)
        {
            printf("  %d > %d, Shift %d to right\n",
                   array[j-1], key, array[j-1]);

            array[j] = array[j-1];
            j--;

            printf("  Current Array: ");
            printArray(array, size);
        }

        array[j] = key;

        printf("Insert %d at position %d\n", key, j);

        printf("Array after Pass %d: ", i);
        printArray(array, size);
    }
}

// Selection Sort with Steps
void selectionSort(int arr[], int n)
{
    int temp;

    printf("\nSELECTION SORT\n");

    for(int i = 0; i < n - 1; i++)
    {
        int min_idx = i;

        printf("\nPass %d:\n", i + 1);
        printf("Current Minimum = %d\n", arr[min_idx]);

        for(int j = i + 1; j < n; j++)
        {
            printf("Compare %d and %d\n", arr[min_idx], arr[j]);

            if(arr[j] < arr[min_idx])
            {
                min_idx = j;
                printf("New Minimum = %d\n", arr[min_idx]);
            }
        }

        if(min_idx != i)
        {
            printf("Swap %d and %d\n", arr[i], arr[min_idx]);

            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
        else
        {
            printf("No Swap Needed\n");
        }

        printf("Array after Pass %d: ", i + 1);
        printArray(arr, n);
    }
}

int main()
{
    int n, choice;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nOriginal Array: ");
    printArray(arr, n);

    printf("\n1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Exit\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            insertionSort(arr, n);
            printf("\nFinal Sorted Array: ");
            printArray(arr, n);
            break;

        case 2:
            selectionSort(arr, n);
            printf("\nFinal Sorted Array: ");
            printArray(arr, n);
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice!\n");
    }

    return 0;
}
