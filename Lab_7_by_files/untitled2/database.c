#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

DBRecord database[MAX_RECORDS]; // Массив записей в базе данных
int numRecords = 0; // Количество текущих записей в базе данных

// Функция для добавления записи в базу данных
void addRecordToDatabase(DBRecord record) {
    if (numRecords < MAX_RECORDS) {
        database[numRecords] = record;
        numRecords++;
        printf("Запись успешно добавлена в базу данных.\n");
    } else {
        printf("База данных полна. Запись не может быть добавлена.\n");
    }
}

// Функция для удаления записи из базы данных по ФИО
void removeRecordFromDatabase(const char* name) {
    int found = 0;
    for (int i = 0; i < numRecords; i++) {
        if (strcmp(database[i].name, name) == 0) {
            // Сдвигаем элементы влево для удаления записи
            for (int j = i; j < numRecords - 1; j++) {
                database[j] = database[j + 1];
            }
            numRecords--;
            found = 1;
            printf("Запись успешно удалена из базы данных.\n");
            break;
        }
    }
    if (!found) {
        printf("Запись с ФИО %s не найдена.\n", name);
    }
}

// Функция для поиска записей в базе данных по ФИО или клубу
void searchRecordsByField(const char* field) {
    int found = 0;
    printf("\nРезультаты поиска по полю %s:\n", field);
    for (int i = 0; i < numRecords; i++) {
        if (strstr(database[i].name, field) || strstr(database[i].club, field)) {
            // Выводим информацию о найденной записи
            printf("Запись %d:\n", i + 1);
            printf("ФИО: %s\n", database[i].name);
            printf("Клуб: %s\n", database[i].club);
            printf("Возраст: %d\n", database[i].age);
            printf("Количество матчей: %d\n", database[i].matches);
            printf("Количество забитых мячей: %d\n", database[i].goals);
            found = 1;
        }
    }
    if (!found) {
        printf("Записи не найдены.\n");
    }
}

// Функция для редактирования записи в базе данных по ФИО
void editRecordInDatabase(const char* name) {
    int found = 0;
    for (int i = 0; i < numRecords; i++) {
        if (strcmp(database[i].name, name) == 0) {
            // Заменяем существующую запись новыми данными
            printf("Введите новые данные для записи:\n");
            database[i] = readDBRecordFromUser();
            found = 1;
            printf("Запись успешно отредактирована.\n");
            break;
        }
    }
    if (!found) {
        printf("Запись с ФИО %s не найдена.\n", name);
    }
}

// Функция для сортировки базы данных по указанному полю
void sortDatabaseByField(const char* field) {
    int i, j;
    DBRecord temp;
    for (i = 0; i < numRecords - 1; i++) {
        for (j = i + 1; j < numRecords; j++) {
            // Сортировка по различным полям
            if (strcmp(field, "name") == 0) {
                if (strcmp(database[i].name, database[j].name) > 0) {
                    temp = database[i];
                    database[i] = database[j];
                    database[j] = temp;
                }
            } else if (strcmp(field, "club") == 0) {
                if (strcmp(database[i].club, database[j].club) > 0) {
                    temp = database[i];
                    database[i] = database[j];
                    database[j] = temp;
                }
            } else if (strcmp(field, "age") == 0) {
                if (database[i].age > database[j].age) {
                    temp = database[i];
                    database[i] = database[j];
                    database[j] = temp;
                }
            } else if (strcmp(field, "matches") == 0) {
                if (database[i].matches > database[j].matches) {
                    temp = database[i];
                    database[i] = database[j];
                    database[j] = temp;
                }
            } else if (strcmp(field, "goals") == 0) {
                if (database[i].goals > database[j].goals) {
                    temp = database[i];
                    database[i] = database[j];
                    database[j] = temp;
                }
            }
        }
    }
    printf("База данных отсортирована по полю %s.\n", field);
}

// Функция для вывода всей базы данных
void printDatabase() {
    printf("\nБаза данных о членах сборной команды по волейболу:\n");
    for (int i = 0; i < numRecords; i++) {
        // Вывод информации о каждой записи
        printf("\nЗапись %d:\n", i + 1);
        printf("ФИО: %s\n", database[i].name);
        printf("Клуб: %s\n", database[i].club);
        printf("Возраст: %d\n", database[i].age);
        printf("Количество матчей: %d\n", database[i].matches);
        printf("Количество забитых мячей: %d\n", database[i].goals);
    }
}

// Функция для чтения записи из базы данных с консоли
DBRecord readDBRecordFromUser() {
    DBRecord record;
    printf("Введите ФИО: ");
    if (scanf(" %[^\n]s", record.name) != 1) {
        printf("Ошибка ввода ФИО.\n");
        exit(1);
    }
    printf("Введите название клуба: ");
    if (scanf(" %[^\n]s", record.club) != 1) {
        printf("Ошибка ввода названия клуба.\n");
        exit(1);
    }
    printf("Введите возраст: ");
    if (scanf("%d", &record.age) != 1) {
        printf("Ошибка ввода возраста.\n");
        exit(1);
    }
    printf("Введите количество матчей, проведенных за сборную: ");
    if (scanf("%d", &record.matches) != 1) {
        printf("Ошибка ввода количества матчей.\n");
        exit(1);
    }
    printf("Введите количество забитых за сборную мячей: ");
    if (scanf("%d", &record.goals) != 1) {
        printf("Ошибка ввода количества забитых мячей.\n");
        exit(1);
    }
    return record;
}
