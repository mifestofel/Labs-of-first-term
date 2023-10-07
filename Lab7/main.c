#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Максимальное количество записей в базе данных
#define MAX_RECORDS 100

// Структура для хранения записи в базе данных
typedef struct {
    char name[50];
    char club[50];
    int age;
    int matches;
    int goals;
} DBRecord;

// Массив для хранения базы данных
DBRecord database[MAX_RECORDS];
int numRecords = 0;

// Прототипы функций
void addRecordToDatabase(DBRecord record);
void removeRecordFromDatabase(const char* name);
void searchRecordsByField(const char* field);
void editRecordInDatabase(const char* name);
void sortDatabaseByField(const char* field);
void printDatabase();
DBRecord readDBRecordFromUser();

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int choice;
    char searchField[50];
    DBRecord dbRecord;

    while (1) {
        printf("\nМеню:\n");
        printf("1. Добавить запись в базу\n");
        printf("2. Удалить запись из базы\n");
        printf("3. Поиск записей по полю\n");
        printf("4. Редактировать запись в базе\n");
        printf("5. Сортировать данные в базе\n");
        printf("6. Вывести базу на экран\n");
        printf("7. Выйти\n");
        printf("Выберите действие (1-7): ");
        scanf("%d", &choice);

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

void addRecordToDatabase(DBRecord record) {
    if (numRecords < MAX_RECORDS) {
        database[numRecords] = record;
        numRecords++;
        printf("Запись успешно добавлена в базу данных.\n");
    } else {
        printf("База данных полна. Запись не может быть добавлена.\n");
    }
}

void removeRecordFromDatabase(const char* name) {
    int found = 0;
    for (int i = 0; i < numRecords; i++) {
        if (strcmp(database[i].name, name) == 0) {
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

void searchRecordsByField(const char* field) {
    int found = 0;
    printf("\nРезультаты поиска по полю %s:\n", field);
    for (int i = 0; i < numRecords; i++) {
        if (strstr(database[i].name, field) || strstr(database[i].club, field)) {
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

void editRecordInDatabase(const char* name) {
    int found = 0;
    for (int i = 0; i < numRecords; i++) {
        if (strcmp(database[i].name, name) == 0) {
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

void sortDatabaseByField(const char* field) {
    int i, j;
    DBRecord temp;
    for (i = 0; i < numRecords - 1; i++) {
        for (j = i + 1; j < numRecords; j++) {
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

void printDatabase() {
    printf("\nБаза данных о членах сборной команды по волейболу:\n");
    for (int i = 0; i < numRecords; i++) {
        printf("\nЗапись %d:\n", i + 1);
        printf("ФИО: %s\n", database[i].name);
        printf("Клуб: %s\n", database[i].club);
        printf("Возраст: %d\n", database[i].age);
        printf("Количество матчей: %d\n", database[i].matches);
        printf("Количество забитых мячей: %d\n", database[i].goals);
    }
}

DBRecord readDBRecordFromUser() {
    DBRecord record;
    printf("Введите ФИО: ");
    scanf(" %[^\n]s", record.name);
    printf("Введите название клуба: ");
    scanf(" %[^\n]s", record.club);
    printf("Введите возраст: ");
    scanf("%d", &record.age);
    printf("Введите количество матчей, проведенных за сборную: ");
    scanf("%d", &record.matches);
    printf("Введите количество забитых за сборную мячей: ");
    scanf("%d", &record.goals);
    return record;
}