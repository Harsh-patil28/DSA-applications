#include <stdio.h>
void printSubset(int subset[], int size) {
    printf("Subset: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}
void subsetSumUtil(int set[], int subset[], int n, int sum, int index, int subsetSize) {
    if (sum == 0) {
        printSubset(subset, subsetSize);
        return;
    }
    if (index >= n || sum < 0) {
        return;
    }
    subset[subsetSize] = set[index];
    subsetSumUtil(set, subset, n, sum - set[index], index + 1, subsetSize + 1);

    subsetSumUtil(set, subset, n, sum, index + 1, subsetSize);
}
void subsetSum(int set[], int n, int sum) {
    int subset[n];
    subsetSumUtil(set, subset, n, sum, 0, 0);
}

int main() {
    int n, sum;
    printf("Enter the size of the set: ");
    scanf("%d", &n);
    int set[n];
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the desired sum: ");
    scanf("%d", &sum);
    subsetSum(set, n, sum);
    return 0;
}
