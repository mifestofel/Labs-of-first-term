#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define MAX_LINE_LENGTH 1000

// Функция для нахождения наименьшего значения в файле
double findMinValue(FILE *file) {
    double minValue;
    int firstValue = 1; // Флаг, чтобы пометить первое значение как наименьшее

    rewind(file); // Перемещаем указатель в начало файла

    if (fscanf(file, "%lf", &minValue) != 1) {
        perror("Ошибка при чтении первого значения из файла");
        exit(1);
    }

    while (!feof(file)) {
        double value;
        if (fscanf(file, "%lf", &value) == 1) { // Считываем число из файла
            if (value < minValue) {
                minValue = value;
            }
        }
    }

    return minValue;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    FILE *file = fopen("f.txt", "r");

    if (file == NULL) {
        perror("Ошибка при открытии файла");
        return 1;
    }

    double minValue = findMinValue(file); // Находим наименьшее значение в файле
    fclose(file);

    // Повторное открытие файла для обработки значений
    file = fopen("f.txt", "r");

    if (file == NULL) {
        perror("Ошибка при открытии файла");
        return 1;
    }

    // Создаем временный файл для записи результата
    FILE *tempFile = fopen("temp.txt", "w");

    if (tempFile == NULL) {
        perror("Ошибка при создании временного файла");
        fclose(file);
        return 1;
    }

    int foundFirstMax = 0; // Флаг для обнаружения первого наибольшего значения

    double firstValue;
    if (fscanf(file, "%lf", &firstValue) != 1) {
        perror("Ошибка при чтении первого значения из файла");
        fclose(file);
        fclose(tempFile);
        return 1;
    }

    // Обработка значений и запись во временный файл
    while (!feof(file)) {
        double value;
        if (fscanf(file, "%lf", &value) == 1) {
            if (value > firstValue && !foundFirstMax) {
                // Записываем наименьшее значение перед первым наибольшим
                fprintf(tempFile, "%.2lf\n", minValue);
                foundFirstMax = 1;
            }
            fprintf(tempFile, "%.2lf\n", value);
        }
    }

    fclose(file);
    fclose(tempFile);

    // Удаляем существующий файл "f.txt"
    if (remove("f.txt") != 0) {
        perror("Ошибка при удалении файла");
        return 1;
    }

    // Заменяем файл "f.txt" содержимым временного файла "temp.txt"
    if (rename("temp.txt", "f.txt") != 0) {
        perror("Ошибка при замене файла");
        return 1;
    }

    printf("Наименьшее значение: %.2lf\n", minValue);

    return 0;
}
