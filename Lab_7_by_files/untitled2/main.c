#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "database.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int choice;
    char searchField[50];
    DBRecord dbRecord;

    while (1) {
        printf("\nМеню:\n");
        printf("1. Добавить запись в базу данных\n");
        printf("2. Удалить запись из базы данных\n");
        printf("3. Поиск записей по полю\n");
        printf("4. Редактировать запись в базе данных\n");
        printf("5. Сортировать данные в базе\n");
        printf("6. Вывести базу данных на экран\n");
        printf("7. Выйти\n");
        printf("Выберите действие (1-7): ");
        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
            exit(1);
        }

        switch (choice) {
            case 1:
                dbRecord = readDBRecordFromUser();
                addRecordToDatabase(dbRecord);
                break;
            case 2:
                printf("Введите ФИО для удаления: ");
                scanf(" %[^\n]s", searchField);
                removeRecordFromDatabase(searchField);
                break;
            case 3:
                printf("Введите поле для поиска: ");
                scanf(" %[^\n]s", searchField);
                searchRecordsByField(searchField);
                break;
            case 4:
                printf("Введите ФИО для редактирования: ");
                scanf(" %[^\n]s", searchField);
                editRecordInDatabase(searchField);
                break;
            case 5:
                printf("Введите поле для сортировки: ");
                scanf(" %[^\n]s", searchField);
                sortDatabaseByField(searchField);
                break;
            case 6:
                printDatabase();
                break;
            case 7:
                exit(0);
            default:
                printf("Неверный выбор. Пожалуйста, выберите снова.\n");
        }
    }
    return 0;
}
