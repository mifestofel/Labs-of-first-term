#include <stdio.h>
#include <windows.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void createMatrix(int matrix[MAX_ROWS][MAX_COLS], int m, int n) {
    printf("Введите элементы матрицы %d x %d:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("matrix[%d][%d]: ", i, j);
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Ошибка ввода. Введите целое число.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int m, int n) {
    printf("Исходная матрица %d x %d:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int sumOfColumnWithMostAboveAverage(int matrix[MAX_ROWS][MAX_COLS], int m, int n) {
    if (m <= 0 || n <= 0) {
        printf("Ошибка: Некорректные размеры матрицы.\n");
        exit(EXIT_FAILURE);
    }

    int maxColumnIndex = 0;
    int maxCount = 0;
    double average = 0.0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            average += matrix[i][j];
        }
    }
    average /= (m * n);

    for (int j = 0; j < n; j++) {
        int count = 0;
        for (int i = 0; i < m; i++) {
            if (matrix[i][j] > average) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxColumnIndex = j;
        }
    }

    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += matrix[i][maxColumnIndex];
    }

    return sum;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int m, n;

    printf("Введите количество строк матрицы (m): ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        printf("Ошибка ввода. Введите положительное целое число.\n");
        return EXIT_FAILURE;
    }

    printf("Введите количество столбцов матрицы (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Ошибка ввода. Введите положительное целое число.\n");
        return EXIT_FAILURE;
    }

    if (m > MAX_ROWS || n > MAX_COLS) {
        printf("Ошибка: Превышены максимальные размеры матрицы.\n");
        return EXIT_FAILURE;
    }

    int matrix[MAX_ROWS][MAX_COLS];
    createMatrix(matrix, m, n);
    printMatrix(matrix, m, n);

    int result = sumOfColumnWithMostAboveAverage(matrix, m, n);
    printf("Сумма элементов в столбце с наибольшим количеством элементов, превышающих среднее арифметическое: %d\n", result);

    return EXIT_SUCCESS;
}
