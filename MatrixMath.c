#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Chelsea Hanson: Homework 2 - Problem 5

int main() {
    
    int n = 0;
    int i, j, k, sum;
    
    printf("\nPlease enter an integer: \n\n");
    
    scanf("%d", &n);
    
    clock_t c0 = clock();
    
    int arrA[n][n];
    int arrB[n][n];
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            arrA[i][j] = rand() % 1024; 
            arrB[i][j] = rand() % 1024;
        }
    }
    
    printf("\n\nMatrix A: \n");
    
    for (i = 0; i < n; i++) {
        printf("[");
        for (j = 0; j < n; j++) {
            printf("%*d", 6, arrA[i][j]);
        }
        printf("] \n");
    }
    
    printf("\n\nMatrix B: \n");
    
    for (i = 0; i < n; i++) {
        printf("[");
        for (j = 0; j < n; j++) {
            printf("%*d", 6, arrB[i][j]);
        }
        printf("] \n");
    }
    
    printf("\n\nMatrix A + Matrix B = \n");
    
    for (i = 0; i < n; i++) {
        printf("[");
        for (j = 0; j < n; j++) {
            printf("%*d", 6, (arrA[i][j] + arrB[i][j]) );
        }
        printf("] \n");
    }
    
    printf("\n\nMatrix A - Matrix B = \n");
    
    for (i = 0; i < n; i++) {
        printf("[");
        for (j = 0; j < n; j++) {
            printf("%*d", 6, (arrA[i][j] - arrB[i][j]) );
        }
        printf("] \n");
    }
    
    printf("\n\nMatrix A * Matrix B = \n");
    
    for (i = 0; i < n; i++) {
        printf("[");
        for (j = 0; j < n; j++) {
            sum = 0;
            for (k = 0; k < n; k++) {
                sum += (arrA[i][k] * arrB[k][j]);
            }
            printf("%*d", 9, (sum) );
        }
        printf("] \n");
    }
    
    clock_t c1 = clock();
    
    double runtime_diff_ms = (c1 - c0) * 1000. / CLOCKS_PER_SEC;
    // printf("\n%lf", runtime_diff_ms);
    
    return 0;
}