#include <stdio.h>
#include <windows.h>

// Введем "макросы" - константы - для более легкой реализации массива
#define MAX_ROWS 10
#define MAX_COLS 10

// Функция для формирования исходной матрицы
void createMatrix(int matrix[MAX_ROWS][MAX_COLS], int m, int n) {
    printf("Введите элементы матрицы %d x %d:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]); // Считываем элемент матрицы с клавиатуры
        }
    }
}

// Функция для вывода исходной матрицы
void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int m, int n) {
    printf("Исходная матрица %d x %d:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]); // Выводим элементы матрицы на экран
        }
        printf("\n");
    }
}

// Функция для вычисления суммы элементов в столбце с наибольшим количеством элементов, превышающих среднее арифметическое
int sumOfColumnWithMostAboveAverage(int matrix[MAX_ROWS][MAX_COLS], int m, int n) {
    int maxColumnIndex = 0; // Индекс столбца с максимальным количеством элементов, превышающих среднее арифметическое
    int maxCount = 0; // Максимальное количество элементов, превышающих среднее арифметическое
    double average = 0.0; // Среднее арифметическое элементов матрицы

    // Вычисляем среднее арифметическое элементов матрицы
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            average += matrix[i][j];
        }
    }
    average /= (m * n);

    // Находим столбец с максимальным количеством элементов, превышающих среднее арифметическое
    for (int j = 0; j < n; j++) {
        int count = 0; // Количество элементов в текущем столбце, превышающих среднее арифметическое
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

    // Вычисляем сумму элементов в найденном столбце
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
    scanf("%d", &m);
    printf("Введите количество столбцов матрицы (n): ");
    scanf("%d", &n);
    int matrix[MAX_ROWS][MAX_COLS];
    createMatrix(matrix, m, n);
    printMatrix(matrix, m, n);
    int result = sumOfColumnWithMostAboveAverage(matrix, m, n);
    printf("Сумма элементов в столбце с наибольшим количеством элементов, превышающих среднее арифметическое: %d\n", result);

    return 0;}