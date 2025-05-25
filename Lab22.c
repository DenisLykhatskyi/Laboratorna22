#include <stdio.h>
#include <math.h>

#define ROWS 3
#define COLS 4

int main() {
    float matrix[ROWS][COLS];
    float transposed_matrix[COLS][ROWS];
    int i, j;

    printf("Введіть елементи матриці (%d x %d):\n", ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("Елемент [%d][%d]: ", i, j);
            scanf("%f", &matrix[i][j]);
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix[i][j] = fabs(matrix[i][j]);
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            transposed_matrix[j][i] = matrix[i][j];
        }
    }

    FILE *file_pointer;
    file_pointer = fopen("exit.txt", "w");

    if (file_pointer == NULL) {
        printf("Помилка відкриття файлу!\n");
        return 1;
    }

    for (i = 0; i < COLS; i++) {
        for (j = 0; j < ROWS; j++) {
            fprintf(file_pointer, "%f ", transposed_matrix[i][j]);
        }
        fprintf(file_pointer, "\n");
    }

    fclose(file_pointer);
    printf("Транспоновану матрицю з модулями елементів записано у файл 'exit.txt'.\n");

    return 0;
}