// perform addition, subtraction, and multiplication of matrices using arrays.
// matrices are assumed to be 3x3
#include <stdio.h>

int rowC = 3; // row count
int colC = 3; // column count

int populateMatrix(int m[rowC][colC], int matrixNumber);
int additionOf(int m1[rowC][colC], int m2[rowC][colC], int m3[rowC][colC]);
int substractionOf(int m1[rowC][colC], int m2[rowC][colC], int m3[rowC][colC]);
int multiplicationOf(int m1[rowC][colC], int m2[rowC][colC], int m3[rowC][colC]);
int printMatrix(int m[rowC][colC]);

int main(void){
    int m1[rowC][colC], m2[rowC][colC];

    // Populate matrices with clear labels
    populateMatrix(m1, 1);
    populateMatrix(m2, 2);

    int madd[rowC][colC], msub[rowC][colC], mmul[rowC][colC];

    // Addition
    additionOf(m1, m2, madd);
    printf("Matrix Addition Result:\n");
    printMatrix(madd);

    // Subtraction
    substractionOf(m1, m2, msub);
    printf("Matrix Subtraction Result:\n");
    printMatrix(msub);
    
    // Multiplication
    multiplicationOf(m1, m2, mmul);
    printf("Matrix Multiplication Result:\n");
    printMatrix(mmul);
    
    return 0; // Good practice to return from main
}

int additionOf(int m1[rowC][colC], int m2[rowC][colC], int m3[rowC][colC]){
    for (int r = 0; r < rowC; r++){
        for (int c = 0; c < colC; c++){
            m3[r][c] = m1[r][c] + m2[r][c]; 
        }
    }
    return 0; // Add return statement for consistency
}

int substractionOf(int m1[rowC][colC], int m2[rowC][colC], int m3[rowC][colC]){
    for (int r = 0; r < rowC; r++){
        for (int c = 0; c < colC; c++){
            m3[r][c] = m1[r][c] - m2[r][c]; 
        }
    }
    return 0;
}

int multiplicationOf(int m1[rowC][colC], int m2[rowC][colC], int m3[rowC][colC]){
    for (int i = 0; i < rowC; i++){
        for (int j = 0; j < colC; j++){
            m3[i][j] = 0;
            for (int k = 0; k < rowC; k++){
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return 0;
}

int populateMatrix(int m[rowC][colC], int matrixNumber){
    printf("Enter elements for Matrix %d:\n", matrixNumber);
    for (int r = 0; r < rowC; r++){
        for (int c = 0; c < colC; c++){
            printf("Element [%d][%d]: ", r, c);
            scanf("%d", &m[r][c]);
        }
    }
    printf("\n");
    return 0;
}

int printMatrix(int m[rowC][colC]){
    for (int r = 0; r < rowC; r++){
        for (int c = 0; c < colC; c++){
            printf("%d\t", m[r][c]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
