#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

// Структура для представления узла списка
typedef struct Node {
    char word[50];
    struct Node *next;
} Node;

// Функция для создания нового узла списка
Node *createNode(const char *word) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Ошибка при выделении памяти для узла\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->word, word);
    newNode->next = NULL;
    return newNode;
}

// Функция для добавления узла в начало списка
Node *prepend(Node *head, const char *word) {
    Node *newNode = createNode(word);
    newNode->next = head;
    return newNode;
}

// Функция для проверки, начинается ли слово с гласной буквы
int startsWithVowel(const char *word) {
    if (word[0] == '\0') {
        return 0; // Слово пустое
    }
    char firstChar = tolower(word[0]);
    return (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u');
}

// Функция для вывода списка в консоль
void printList(Node *head) {
    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }
    Node *current = head;
    while (current != NULL) {
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    // Список слов
    Node *head = NULL;
    head = prepend(head, "apple");
    head = prepend(head, "banana");
    head = prepend(head, "cherry");
    head = prepend(head, "orange");
    head = prepend(head, "grape");
    head = prepend(head, "kiwi");

    printf("Исходный список: ");
    printList(head);

    // Переставляем слова, начинающиеся с гласных, в начало списка
    Node *newHead = NULL;
    Node *current = head;
    while (current != NULL) {
        if (startsWithVowel(current->word)) {
            newHead = prepend(newHead, current->word);
        } else {
            // Если слово не начинается с гласной, добавляем его в конец нового списка
            Node *newCurrent = newHead;
            if (newCurrent != NULL) {
                while (newCurrent->next != NULL) {
                    newCurrent = newCurrent->next;
                }
                newCurrent->next = createNode(current->word);
            } else {
                newHead = createNode(current->word);
            }
        }
        current = current->next;
    }

    printf("Список после перестановки: ");
    printList(newHead);

    // Освобождаем память, выделенную для узлов списка
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    while (newHead != NULL) {
        Node *temp = newHead;
        newHead = newHead->next;
        free(temp);
    }

    return 0;
}