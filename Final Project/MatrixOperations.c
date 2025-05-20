#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix of floating-point numbers
typedef struct {
    int rows;
    int cols;
    float** data;
} Matrix;

// Function to allocate memory for a matrix
int allocateMatrix(Matrix* m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->data = (float**)malloc(rows * sizeof(float*));
    if (m->data == NULL) return 0;
    for (int i = 0; i < rows; i++) {
        m->data[i] = (float*)malloc(cols * sizeof(float));
        if (m->data[i] == NULL) return 0;
    }
    return 1;
}

// Function to free the memory of a matrix
void freeMatrix(Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    m->data = NULL;
}

// Function to input matrix data from the user
int inputMatrix(Matrix* m) {
    int rows, cols;
    printf("Enter the number of rows and columns for the matrix: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        printf("Invalid input.\n");
        return 0;
    }

    if (!allocateMatrix(m, rows, cols)) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("\nEnter element [%d][%d]: ", i, j);
            if (scanf("%f", &m->data[i][j]) != 1) {
                printf("Invalid input.\n");
                return 0;
            }
        }
    }
    return 1;
}

// Function to print the matrix
void printMatrix(Matrix* m) {
    printf("Here is the matrix:\n");
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%8.2f ", m->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int addMatrix(Matrix* a, Matrix* b, Matrix* result) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Error: Matrices must have the same dimensions to add them.\n");
        return 0;
    }

    if (!allocateMatrix(result, a->rows, a->cols)) return 0;

    for (int i = 0; i < a->rows; i++)
        for (int j = 0; j < a->cols; j++)
            result->data[i][j] = a->data[i][j] + b->data[i][j];
    return 1;
}

// Subtract matrix b from matrix a
int subtractMatrix(Matrix* a, Matrix* b, Matrix* result) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Error: Matrices must have the same dimensions to subtract them.\n");
        return 0;
    }

    if (!allocateMatrix(result, a->rows, a->cols)) return 0;

    for (int i = 0; i < a->rows; i++)
        for (int j = 0; j < a->cols; j++)
            result->data[i][j] = a->data[i][j] - b->data[i][j];
    return 1;
}

// Multiply matrices
int multiplyMatrix(Matrix* a, Matrix* b, Matrix* result) {
    if (a->cols != b->rows) {
        printf("Error: Matrices can't be multiplied.\n");
        return 0;
    }

    if (!allocateMatrix(result, a->rows, b->cols)) return 0;

    for (int i = 0; i < a->rows; i++)
        for (int j = 0; j < b->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < a->cols; k++)
                result->data[i][j] += a->data[i][k] * b->data[k][j];
        }

    return 1;
}

// Transpose matrix
int transposeMatrix(Matrix* m, Matrix* result) {
    if (!allocateMatrix(result, m->cols, m->rows)) return 0;

    for (int i = 0; i < m->rows; i++)
        for (int j = 0; j < m->cols; j++)
            result->data[j][i] = m->data[i][j];

    return 1;
}

// Scalar multiplication
int scalarMultiplyMatrix(Matrix* m, float scalar, Matrix* result) {
    if (!allocateMatrix(result, m->rows, m->cols)) return 0;

    for (int i = 0; i < m->rows; i++)
        for (int j = 0; j < m->cols; j++)
            result->data[i][j] = m->data[i][j] * scalar;

    return 1;
}

// Determinant Calculation
float determinantMatrix(Matrix* m) {
    if (m->rows != m->cols) {
        printf("Error: Determinant can only be calculated for square matrices.\n");
        return 0;
    }

    int n = m->rows;

    if (n == 1) return m->data[0][0];
    if (n == 2)
        return m->data[0][0] * m->data[1][1] - m->data[0][1] * m->data[1][0];

    float det = 0;

    for (int x = 0; x < n; x++) {
        Matrix sub;
        allocateMatrix(&sub, n - 1, n - 1);
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) continue;
                sub.data[i - 1][subj++] = m->data[i][j];
            }
        }
        float sign = (x % 2 == 0) ? 1 : -1;
        det += sign * m->data[0][x] * determinantMatrix(&sub);
        freeMatrix(&sub);
    }

    return det;
}

// LU Factorization
int LUFactorization(Matrix* m, Matrix* L, Matrix* U) {
    if (m->rows != m->cols) {
        printf("Error: LU factorization requires a square matrix.\n");
        return 0;
    }

    int n = m->rows;
    allocateMatrix(L, n, n);
    allocateMatrix(U, n, n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            L->data[i][j] = (i == j) ? 1 : 0;
            U->data[i][j] = m->data[i][j];
        }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (U->data[i][i] == 0) {
                printf("Error: Singular matrix.\n");
                return 0;
            }
            float factor = U->data[j][i] / U->data[i][i];
            L->data[j][i] = factor;

            for (int k = 0; k < n; k++)
                U->data[j][k] -= factor * U->data[i][k];
        }
    }

    return 1;
}

// Row Echelon Form (Gaussian Elimination)
int rowEchelonForm(Matrix* m) {
    int lead = 0;
    for (int r = 0; r < m->rows; r++) {
        if (lead >= m->cols) return 1;
        int i = r;
        while (m->data[i][lead] == 0) {
            i++;
            if (i == m->rows) {
                i = r;
                lead++;
                if (lead == m->cols) return 1;
            }
        }

        if (i != r) {
            float* temp = m->data[r];
            m->data[r] = m->data[i];
            m->data[i] = temp;
        }

        float div = m->data[r][lead];
        if (div != 0) {
            for (int j = 0; j < m->cols; j++)
                m->data[r][j] /= div;
        }

        for (int i = r + 1; i < m->rows; i++) {
            float mult = m->data[i][lead];
            if (mult != 0) {
                for (int j = 0; j < m->cols; j++)
                    m->data[i][j] -= m->data[r][j] * mult;
            }
        }
        lead++;
    }
    return 1;
}

// Main program
int main() {
    int choice;
    float scalar;
    Matrix A, B, C, L, U;

    do {
        printf("\nMatrix Operations Menu:\n"
               "1. Add Matrices\n"
               "2. Subtract Matrices\n"
               "3. Multiply Matrices\n"
               "4. Transpose Matrix\n"
               "5. Scalar Multiply Matrix\n"
               "6. Determinant of NxN Matrix\n"
               "7. LU Factorization\n"
               "8. Row Echelon Form\n"
               "0. Exit\n"
               "Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputMatrix(&A);
                inputMatrix(&B);
                if (addMatrix(&A, &B, &C)) {
                    printMatrix(&C);
                    freeMatrix(&C);
                }
                freeMatrix(&A);
                freeMatrix(&B);
                break;
            case 2:
                inputMatrix(&A);
                inputMatrix(&B);
                if (subtractMatrix(&A, &B, &C)) {
                    printMatrix(&C);
                    freeMatrix(&C);
                }
                freeMatrix(&A);
                freeMatrix(&B);
                break;
            case 3:
                inputMatrix(&A);
                inputMatrix(&B);
                if (multiplyMatrix(&A, &B, &C)) {
                    printMatrix(&C);
                    freeMatrix(&C);
                }
                freeMatrix(&A);
                freeMatrix(&B);
                break;
            case 4:
                inputMatrix(&A);
                if (transposeMatrix(&A, &C)) {
                    printMatrix(&C);
                    freeMatrix(&C);
                }
                freeMatrix(&A);
                break;
            case 5:
                inputMatrix(&A);
                printf("Enter scalar: ");
                scanf("%f", &scalar);
                if (scalarMultiplyMatrix(&A, scalar, &C)) {
                    printMatrix(&C);
                    freeMatrix(&C);
                }
                freeMatrix(&A);
                break;
            case 6:
                inputMatrix(&A);
                float det;
                det = determinantMatrix(&A);
                printf("Determinant: %.2f\n", det);
                freeMatrix(&A);
                break;
            case 7:
                inputMatrix(&A);
                if (LUFactorization(&A, &L, &U)) {
                    printf("L Matrix:\n");
                    printMatrix(&L);
                    printf("U Matrix:\n");
                    printMatrix(&U);
                    freeMatrix(&L);
                    freeMatrix(&U);
                }
                freeMatrix(&A);
                break;
            case 8:
                inputMatrix(&A);
                if (rowEchelonForm(&A)) {
                    printf("Row Echelon Form:\n");
                    printMatrix(&A);
                }
                freeMatrix(&A);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
