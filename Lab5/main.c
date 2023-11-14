#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_LINE_LENGTH 1000

// Функция для удаления пробелов в начале и конце строки
void trim(char *str) {
    int len = strlen(str);

    // Удаление пробелов в начале строки
    int start = 0;
    while (str[start] == ' ' || str[start] == '\t') {
        start++;
    }

    // Удаление пробелов в конце строки
    int end = len - 1;
    while (end >= 0 && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n')) {
        end--;
    }

    // Сдвиг символов, чтобы убрать пробелы
    int i, j = 0;
    for (i = start; i <= end; i++) {
        str[j++] = str[i];
    }
    str[j] = '\0';
}

// Функция для сравнения строк по их длине
int compareLength(const void *a, const void *b) {
    return strlen(*(const char **)a) - strlen(*(const char **)b);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    char filename_f[] = "f.txt";  // Имя файла f
    char filename_g[] = "g.txt";  // Имя файла g

    FILE *file_f = fopen(filename_f, "r");
    FILE *file_g = fopen(filename_g, "w");

    if (file_f == NULL || file_g == NULL) {
        perror("Ошибка при открытии файлов");
        return 1;
    }

    char buffer[MAX_LINE_LENGTH];
    char *lines[MAX_LINE_LENGTH];
    int num_lines = 0;

    // Чтение строк из файла f и удаление пробелов в начале и конце
    while (fgets(buffer, MAX_LINE_LENGTH, file_f) != NULL) {
        trim(buffer);

        // Проверка длины строки перед добавлением в массив
        if (strlen(buffer) >= MAX_LINE_LENGTH) {
            fprintf(stderr, "Ошибка: строка слишком длинная.\n");
            return 1;
        }

        lines[num_lines] = strdup(buffer);  // Копируем строку в динамический буфер
        num_lines++;

        // Проверка на превышение максимального количества строк
        if (num_lines >= MAX_LINE_LENGTH) {
            fprintf(stderr, "Ошибка: превышено максимальное количество строк.\n");
            return 1;
        }
    }

    fclose(file_f);

    // Сортировка строк по длине
    qsort(lines, num_lines, sizeof(char *), compareLength);

    // Запись отсортированных строк в файл g
    for (int i = 0; i < num_lines; i++) {
        fprintf(file_g, "%s\n", lines[i]);
        free(lines[i]);  // Освобождаем память, выделенную для каждой строки
    }

    fclose(file_g);

    return 0;
}