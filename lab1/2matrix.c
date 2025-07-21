// perform addition, subtraction, and multiplication of matrices using arrays.
// matrices are assumed to be 3x3
#include <stdio.h>
int rowC = 3; // row count
int colC = 3; // column count

int additionOf(int m1[rowC][colC], int m2[rowC][colC]){
    // return addition of matrix m1 & m2
    int m3[rowC][colC];
    for (int r = 0; r < rowC; r++){
        for (int c = 0; c < colC; c++){
            m3[r][c] = m1[r][c] + m2[r][c]; 
        }
    }
    return m3;
}

int substractionOf(int m1[rowC][colC], int m2[rowC][colC]){
    // return substraction of matrix m1 & m2
    int m3[rowC][colC];
    for (int r = 0; r < rowC; r++){
        for (int c = 0; c < colC; c++){
            m3[r][c] = m1[r][c] - m2[r][c]; 
        }
    }
    return m3;
}

int multiplicationOf(int m1[rowC][colC], int m2[rowC][colC]){
       
}