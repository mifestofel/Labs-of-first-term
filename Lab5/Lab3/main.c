#include <stdio.h>
#include <windows.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Функция для заполнения матрицы значениями, введенными пользователем
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

// Функция для вывода матрицы на экран
void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int m, int n) {
    printf("Исходная матрица %d x %d:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Функция для вычисления суммы элементов в столбце с наибольшим количеством элементов, превышающих среднее арифметическое
int sumOfColumnWithMostAboveAverage(int matrix[MAX_ROWS][MAX_COLS], int m, int n) {
    // Проверка корректности размеров матрицы
    if (m <= 0 || n <= 0) {
        printf("Ошибка: Некорректные размеры матрицы.\n");
        exit(EXIT_FAILURE);
    }

    int maxColumnIndex = 0;
    int maxCount = 0;
    double average = 0.0;

    // Вычисление среднего арифметического всех элементов матрицы
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            average += matrix[i][j];
        }
    }
    average /= (m * n);

    // Поиск столбца с наибольшим количеством элементов, превышающих среднее
    for (int j = 0; j < n; j++) {
        int count = 0;
        for (int i = 0; i < m; i++) {
            if (matrix[i][j] > average) {
                count++;
            }
        }
        // Обновление информации о максимальном столбце
        if (count > maxCount) {
            maxCount = count;
            maxColumnIndex = j;
        }
    }

    // Вычисление суммы элементов в выбранном столбце
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += matrix[i][maxColumnIndex];
    }

    return sum;
}

int main() {
    // Установка кодировки вывода в UTF-8 для корректного отображения символов
    SetConsoleOutputCP(CP_UTF8);

    int m, n;

    // Ввод количества строк матрицы
    printf("Введите количество строк матрицы (m): ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        printf("Ошибка ввода. Введите положительное целое число.\n");
        return EXIT_FAILURE;
    }

    // Ввод количества столбцов матрицы
    printf("Введите количество столбцов матрицы (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Ошибка ввода. Введите положительное целое число.\n");
        return EXIT_FAILURE;
    }

    // Проверка на превышение максимальных размеров матрицы
    if (m > MAX_ROWS || n > MAX_COLS) {
        printf("Ошибка: Превышены максимальные размеры матрицы.\n");
        return EXIT_FAILURE;
    }

    // Объявление и заполнение матрицы
    int matrix[MAX_ROWS][MAX_COLS];
    createMatrix(matrix, m, n);

    // Вывод исходной матрицы
    printMatrix(matrix, m, n);

    // Вычисление и вывод результата
    int result = sumOfColumnWithMostAboveAverage(matrix, m, n);
    printf("Сумма элементов в столбце с наибольшим количеством элементов, превышающих среднее арифметическое: %d\n", result);

    return EXIT_SUCCESS;
}