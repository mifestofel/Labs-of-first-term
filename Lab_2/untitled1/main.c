#include <stdio.h>
#include <windows.h>

// Функция для создания массива
void createArray(int B[], int k) {
    printf("Введите элементы массива B:\n");
    for (int i = 0; i < k; i++) {
        printf("B[%d]: ", i);
        if (scanf("%d", &B[i]) != 1) {
            printf("Ошибка ввода. Введите целое число.\n");
            exit(EXIT_FAILURE);
        }
    }
}

// Функция для вывода массива на экран
void printArray(int B[], int k) {
    printf("Массив B: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Устанавливаем кодировку вывода на UTF-8

    int k, x, y;

    printf("Введите количество элементов массива B (k): ");
    if (scanf("%d", &k) != 1 || k <= 0) {
        printf("Ошибка ввода. Введите положительное целое число.\n");
        return EXIT_FAILURE;
    }

    int B[k];

    createArray(B, k);
    printArray(B, k);

    printf("Введите пороговые значения x и y: ");
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Ошибка ввода. Введите два целых числа.\n");
        return EXIT_FAILURE;
    }

    int minVal = y;

    for (int i = 0; i < k; i++) {
        if (B[i] < y && B[i] < minVal) {
            minVal = B[i];
        }
    }

    printf("Минимальный элемент < y: %d\n", minVal);

    int firstEvenIndex = -1;
    int lastEvenIndex = -1;

    for (int i = 0; i < k; i++) {
        if (B[i] % 2 == 0) {
            if (firstEvenIndex == -1) {
                firstEvenIndex = i;
            }
            lastEvenIndex = i;
        }
    }

    if (firstEvenIndex != -1 && lastEvenIndex != -1 && firstEvenIndex != lastEvenIndex) {
        double sum = 0;
        int count = 0;

        for (int i = firstEvenIndex + 1; i < lastEvenIndex; i++) {
            sum += B[i];
            count++;
        }

        if (count > 0) {
            double average = sum / count;
            printf("Среднее арифметическое элементов между первым и последним четными элементами: %.2lf\n", average);
        } else {
            printf("Между первым и последним четными элементами нет других элементов.\n");
        }
    } else {
        printf("В массиве нет четных элементов или есть только один четный элемент.\n");
    }

    return EXIT_SUCCESS;
}
