/*Given a knapsack of maximum capacity w. N items are provided, each having its
own value and weight. You have to Design an algorithm and implement it using a
program to find the list of the selected items such that the final selected content has
weight w and has maximum value. You can take fractions of items,i.e. the items can
be broken into smaller pieces so that you have to carry
only a fraction xi of item i, where 0 ≤xi≤ 1.*/

[9:12 AM, 5/3/2024] Anushka: #include <stdio.h>
#include <stdlib.h>
struct Item {
    int value;
    int weight;
    float valuePerWeight;
};
int compare(const void* a, const void* b) {
    struct Item* item1 = (struct Item*)a;
    struct Item* item2 = (struct Item*)b;
    return (int)(item2->valuePerWeight - item1->valuePerWeight);
}
float fractionalKnapsack(struct Item* items, int n, int W) {
    qsort(items, n, sizeof(items[0]), compare);

    float totalValue = 0.0; 
    int currentWeight = 0; 
    
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        } else {
            float remainingWeight = W - currentWeight;
            totalValue += items[i].valuePerWeight * remainingWeight;
            break; 
        }
    }
    return totalValue;
}
int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);

    struct Item* items = (struct Item*)malloc(n * sizeof(struct Item));
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].valuePerWeight = (float)items[i].value / items[i].weight;
    }

    float maxValue = fractionalKnapsack(items, n, W);

    printf("Maximum value that can be obtained: %.2f\n", maxValue);

    free(items);

    return 0;
}
