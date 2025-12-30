#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} Element;

void convertToSparse(int matrix[4][5], int totalRows, int totalCols) {
    Element sparseMatrix[100];
    int count = 1;

    for (int i = 0; i < totalRows; i++) {
        for (int j = 0; j < totalCols; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[count].row = i;
                sparseMatrix[count].col = j;
                sparseMatrix[count].value = matrix[i][j];
                count++;
            }
        }
    }

    sparseMatrix[0].row = totalRows;
    sparseMatrix[0].col = totalCols;
    sparseMatrix[0].value = count - 1;

    printf("\nSparse Matrix (Triplet Representation):\n");
    printf("Row\tCol\tValue\n");
    printf("---\t---\t-----\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\n", sparseMatrix[i].row, sparseMatrix[i].col, sparseMatrix[i].value);
    }
}

int main() {

	/// HW 1: Sparse matrix transformation.





    // Example
    int matrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    printf("Original Matrix\n");
    convertToSparse(matrix, 4, 5);

    return 0;
}