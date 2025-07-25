// perform addition, subtraction, and multiplication of matrices using arrays.
// matrices are assumed to be 3x3
#include <stdio.h>
int rowC = 3; // row count
int colC = 3; // column count

int additionOf(int m1[rowC][colC], int m2[rowC][colC], int m3[rowC][colC]){
    for (int r = 0; r < rowC; r++){
        for (int c = 0; c < colC; c++){
            m3[r][c] = m1[r][c] + m2[r][c]; 
        }
    }
}

int substractionOf(int m1[rowC][colC], int m2[rowC][colC], int m3[rowC][colC]){
    for (int r = 0; r < rowC; r++){
        for (int c = 0; c < colC; c++){
            m3[r][c] = m1[r][c] - m2[r][c]; 
        }
    }
}

int multiplicationOf(int m1[rowC][colC], int m2[rowC][colC], int m3[rowC][colC]){
    for (int i = 0; i < rowC; i++){
        for (int j = 0; j < colC; j++){
            m3[i][j] = 0;
            for (int k = 0; k < rowC ; k++){
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int populateMatrix(int m[rowC][colC]){
    printf("input\n");
    for (int r = 0; r < rowC; r++){
        for (int c = 0; c < colC; c++){
            printf("r%d c%d: ", r, c);
            scanf("%d", &m[r][c]);
        }
    }
}

int printMatrix(int m[rowC][colC]){
    printf("output\n");
    for (int r = 0; r < rowC; r++){
        for (int c = 0; c < colC; c++){
            printf("%d\t", m[r][c]);
        }
        printf("\n");
    }
}

int main(void){
    int m1[rowC][colC], m2[rowC][colC];

    populateMatrix(m1);
    populateMatrix(m2);

    int madd[rowC][colC], msub[rowC][colC], mmul[rowC][colC];

    additionOf(m1, m2, madd);
    printMatrix(madd);

    substractionOf(m1, m2, msub);
    printMatrix(msub);
    
    multiplicationOf(m1, m2, mmul);
    printMatrix(mmul);
}