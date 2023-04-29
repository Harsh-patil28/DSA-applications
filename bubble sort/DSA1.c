#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random(int n, int p, int q);
void sort(int n);

int main() {
    int n, p, q;


    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);
    printf("Enter the lower bound (P): ");
    scanf("%d", &p);
    printf("Enter the upper bound (Q): ");
    scanf("%d", &q);
    random(n, p, q);
    sort(n);

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

void sort(int n) {
    clock_t start_t, end_t;
    double total_t;
    FILE *infp, *outfp;
    int i, j, temp, a[n];

    infp = fopen("input.txt", "r");
    outfp = fopen("output.txt", "w");

    start_t = clock();
    for (i = 0; i < n; i++) {
        fscanf(infp, "%d", &a[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++) {
        fprintf(outfp, "%d\n", a[i]);
    }
    printf("Random Numbers Generated and Sorted in output.txt\n");
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", total_t  );
    fclose(infp);
    fclose(outfp);
}
