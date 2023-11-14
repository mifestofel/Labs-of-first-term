#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>

// Объявления функций
double calculate_arcsin_with_precision(double x, double precision);
double calculate_arcsin_with_terms(double x, int max_terms);

// Функции для проверки ввода double
bool isValidDouble(double num);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    double x, precision;
    int max_terms, choice;

    // Ввод значения x
    printf("Введите значение x: ");
    if (scanf("%lf", &x) != 1 || !isValidDouble(x) || x <= 0) {
        printf("Ошибка: Некорректный ввод для x.\n");
        return 1;
    }

    // Выбор метода вычисления
    printf("Выберите метод вычисления:\n");
    printf("1. С точностью\n");
    printf("2. Заданное количество членов ряда\n");
    printf("Выбор: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Ввод точности
            printf("Введите точность: ");
            scanf("%lf", &precision);
            if (!isValidDouble(precision) || precision <= 0) {
                printf("Ошибка: Некорректный ввод для точности.\n");
                return 1;
            }

            double result_precision = calculate_arcsin_with_precision(x, precision);
            printf("arcsin(%lf) с точностью %lf: %lf\n", x, precision, result_precision);
            break;

        case 2:
            // Ввод максимального количества членов ряда
            printf("Введите максимальное количество членов ряда: ");
            scanf("%d", &max_terms);
            if (max_terms <= 1 || isValidDouble(max_terms)){
                printf("Ошибка: Некорректный ввод для количества членов ряда. Количество членов ряда может быть только > 1\n");
                return 1;
            }
            double result_terms = calculate_arcsin_with_terms(x, max_terms);
            printf("arcsin(%lf) с %d членами ряда: %lf\n", x, max_terms, result_terms);
            break;

        default:
            printf("Неверный выбор.\n");
            return 1;
    }

    return 0;
}

// Определения функций calculate_arcsin_with_precision и calculate_arcsin_with_terms
double calculate_arcsin_with_precision(double x, double precision) {
    double result = x;
    double term = x;
    double x_squared = x * x;
    int n = 1;

    while (fabs(term) >= precision) {
        term *= (2 * n - 1) * (2 * n - 1) * x_squared / (2 * n * (2 * n + 1));
        result += term;
        n++;
    }

    return result;
}
// Функция calculate_arcsin_with_terms вычисляет приближенное значение arcsin(x) с заданным количеством членов ряда.
double calculate_arcsin_with_terms(double x, int max_terms) {
    double result = x;
    double term = x;
    double x_squared = x * x;

    for (int n = 1; n < max_terms; n++) {
        term *= (2 * n - 1) * (2 * n - 1) * x_squared / (2 * n * (2 * n + 1));
        result += term;
    }
    return result;
}
// Определения функций isValidDouble
bool isValidDouble(double num) {
    return !isnan(num) && isfinite(num);
}