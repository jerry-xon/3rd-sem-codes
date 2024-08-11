#include <stdio.h>
#include <stdlib.h>

int main() {
    int **mat1, **mat2, **res, i, j, k, r1, c1, r2, c2;

    printf("\nEnter the Order of the First matrix...\n");
    scanf("%d %d", &r1, &c1);

    printf("\nEnter the Order of the Second matrix...\n");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Invalid Order of matrix");
        exit(EXIT_SUCCESS);
    }

    mat1 = (int **)malloc(r1 * sizeof(int *));
    for (i = 0; i < r1; i++)
        mat1[i] = (int *)malloc(c1 * sizeof(int));

    mat2 = (int **)malloc(r2 * sizeof(int *));
    for (i = 0; i < r2; i++)
        mat2[i] = (int *)malloc(c2 * sizeof(int));

    res = (int **)calloc(r1, sizeof(int *));
    for (i = 0; i < r1; i++)
        res[i] = (int *)calloc(c2, sizeof(int));

    // Input Matrix1
    printf("\nEnter elements of Matrix 1:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++)
            scanf("%d", &mat1[i][j]);
    }

    // Input Matrix2
    printf("\nEnter elements of Matrix 2:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++)
            scanf("%d", &mat2[i][j]);
    }

    // Printing Input Matrix 1 and 2
    printf("\nEntered Matrix 1:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++)
            printf("%d ", mat1[i][j]);
        printf("\n");
    }

    printf("\nEntered Matrix 2:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++)
            printf("%d ", mat2[i][j]);
        printf("\n");
    }

    // Computation
    // Multiplication
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            for (k = 0; k < c1; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }

    printf("\nThe Multiplication of two matrix is:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++)
            printf("%d\t", res[i][j]);
        printf("\n");
    }

    // Free allocated memory
    for (i = 0; i < r1; i++)
        free(mat1[i]);
    free(mat1);

    for (i = 0; i < r2; i++)
        free(mat2[i]);
    free(mat2);

    for (i = 0; i < r1; i++)
        free(res[i]);
    free(res);

    return 0;
}


/*Matrix multiplication using
 dynamic memory allocation ( malloc)*/