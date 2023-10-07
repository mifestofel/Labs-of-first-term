#include <stdio.h>
#include <string.h>
#include <ctype.h>
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

int main() {
    SetConsoleOutputCP(CP_UTF8);
    char inputString[100];  // Предполагаем максимальную длину строки равной 100 символам
    char lastLetter;

    // Ввод строки
    printf("Введите строку: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Находим последнюю букву
    int len = strlen(inputString);
    lastLetter = tolower(inputString[len - 2]);  // -2 чтобы пропустить точку и перейти к последней букве

    // Перебираем слова в строке
    char *token = strtok(inputString, " ");
    while (token != NULL) {
        transformWord(token, lastLetter);
        printf("%s ", token);
        token = strtok(NULL, " ");
    }

    printf(".\n");  // Добавляем точку в конце строки

    return 0;
}



