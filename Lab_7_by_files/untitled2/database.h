// database.h
#ifndef DATABASE_H
#define DATABASE_H

#define MAX_RECORDS 100

typedef struct {
    char name[50];
    char club[50];
    int age;
    int matches;
    int goals;
} DBRecord;

void addRecordToDatabase(DBRecord record);
void removeRecordFromDatabase(const char* name);
void searchRecordsByField(const char* field);
void editRecordInDatabase(const char* name);
void sortDatabaseByField(const char* field);
void printDatabase();
DBRecord readDBRecordFromUser();

#endif // DATABASE_H