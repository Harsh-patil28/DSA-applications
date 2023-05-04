#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100000
void random(int n,int p,int q);
void sort();
int main() {
    int n,p,q;
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);
    printf("Enter the lower bound (P): ");
    scanf("%d", &p);
    printf("Enter the upper bound (Q): ");
    scanf("%d", &q);

    random(p, q, n);
    sort();

    return 0;
}
void random(int n, int p, int q) {
    FILE *fp;
    int i, num;
    fp = fopen("input.txt", "w");
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        num = rand() % (q - p + 1) + p;
        fprintf(fp, "%d\n", num);
    }
    fclose(fp);
}
// Function to merge two arrays
void merge(int a[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] < right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }

        k++;
    }

    while (i < leftSize) {
        a[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        a[k] = right[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
void mergeSort(int a[], int size) {

    if (size < 2) {
        return;
    }

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = a[i];
    }

    for (int i = mid; i < size; i++) {
        right[i - mid] = a[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(a, left, mid, right, size - mid);

}

// Function to read input file and perform merge sort
void sort() {
    clock_t start_t, end_t;
    double total_t;
     start_t = clock();
    FILE *infp = fopen("Input.txt", "r");


    int a[MAX_NUMBERS];
    int size = 0;
    int num;

    while (fscanf(infp, "%d", &num) == 1) {
        a[size++] = num;
    }

    fclose(infp);

    mergeSort(a, size);

    FILE *outfp = fopen("Output.txt", "w");



    for (int i = 0; i < size; i++) {
        fprintf(outfp, "%d\n", a[i]);
    }

    fclose(outfp);
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Random Numbers Generated and Sorted in output.txt\n");
    printf("Total time taken by CPU: %f\n", total_t  );
}


