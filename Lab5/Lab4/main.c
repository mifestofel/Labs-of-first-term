#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>

// Функция, которая выполняет преобразование слова согласно правилам
void transformWord(char *word, char lastLetter) {
    int i, j = 0;
    for (i = 0; word[i] != '\0'; i++) {
        if (tolower(word[i]) != tolower(lastLetter)) {
            word[j++] = word[i];
        }
    }
    word[j] = '\0';
}

// Функция для проверки корректности ввода строки
bool isValidInputString(const char *str) {
    int len = strlen(str);
    if (len == 0 || str[len - 1] != '\n') {
        return false;
    }
    return true;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    char inputString[100];
    char lastLetter;

    // Ввод строки
    printf("Введите строку: ");
    if (fgets(inputString, sizeof(inputString), stdin) == NULL || !isValidInputString(inputString)) {
        printf("Ошибка ввода строки.\n");
        return EXIT_FAILURE;
    }

    // Находим последнюю букву
    int len = strlen(inputString);
    if (len < 2) {
        printf("Ошибка: Слишком короткая строка.\n");
        return EXIT_FAILURE;
    }

    lastLetter = tolower(inputString[len - 2]);

    // Перебираем слова в строке
    char *token = strtok(inputString, " ");
    while (token != NULL) {
        transformWord(token, lastLetter);
        printf("%s ", token);
        token = strtok(NULL, " ");
    }

    printf(".\n");

    return EXIT_SUCCESS;
}
