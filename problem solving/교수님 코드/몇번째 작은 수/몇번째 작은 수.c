# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int partition(int* A, int p, int r) {

    int i, j;
    int temp;

    i = p - 1;
    for (j = p; j < r; j++) {
        if (A[j] < A[r]) {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    i++;
    temp = A[i];
    A[i] = A[r];
    A[r] = temp;

    return i;
}

int selection(int* A, int p, int r, int i) {

    int q;
    int rank;

    q = partition(A, p, r);
    rank = q - p + 1;

    if (i == rank)
        return A[q];
    else if (i < rank)
        return selection(A, p, q - 1, i);
    else
        return selection(A, q + 1, r, i - rank);

}

int main() {

    int* A;
    int n, i, rank;

    scanf("%d", &n);
    scanf("%d", &rank);

    A = (int*)malloc(sizeof(int) * n);

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        A[i] = rand() % 1000;
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("%d\n", selection(A, 0, n - 1, rank));
    return 0;
}