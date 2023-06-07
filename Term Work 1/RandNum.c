#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void random(int n, int p, int q);
int main() {
    int n, p, q;
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);
    printf("Enter the lower bound (P): ");
    scanf("%d", &p);
    printf("Enter the upper bound (Q): ");
    scanf("%d", &q);
    random(n, p, q);
    return 0;
}
void random(int n, int p, int q) {
    int i, num;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        num = rand() % (q - p + 1) + p;
        printf( "%d\n", num);
    }
}

