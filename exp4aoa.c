#include <stdio.h>

struct Item {
    int weight;
    int value;
    float ratio;
};

// Function to sort items by value/weight ratio in descending order
void sortItems(struct Item items[], int n) {
    int i, j;
    struct Item temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    int n, capacity;
    float totalValue = 0.0;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items based on value/weight ratio
    sortItems(items, n);

    printf("\nSelected items:\n");

    for (int i = 0; i < n; i++) {
        if (capacity == 0)
            break;

        if (items[i].weight <= capacity) {
            // Take the whole item
            printf("Take 100%% of item (Value=%d, Weight=%d)\n",
                   items[i].value, items[i].weight);

            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // Take a fraction of the item
            float fraction = (float)capacity / items[i].weight;
            printf("Take %.2f%% of item (Value=%d, Weight=%d)\n",
                   fraction * 100, items[i].value, items[i].weight);

            totalValue += items[i].value * fraction;
            capacity = 0;
        }
    }

    printf("\nMaximum value in knapsack = %.2f\n", totalValue);

    return 0;
}