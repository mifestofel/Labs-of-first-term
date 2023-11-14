#include <stdio.h>
#include <stdlib.h>

int main() {
    int coeff1[] = {2, 0, -4, 0, 0, 7}; // Коэффициенты многочлена L1
    int coeff2[] = {0, -5, 1, 1, 0, -3}; // Коэффициенты многочлена L2
    int degree = 5; // Максимальная степень многочлена

    // Вывод L1
    printf("L1 = ");
    for (int i = degree; i >= 0; i--) {
        if (coeff1[i] != 0) {
            printf("%+dx^%d ", coeff1[i], i);
        }
    }
    printf("\n");

    // Вывод L2
    printf("L2 = ");
    for (int i = degree; i >= 0; i--) {
        if (coeff2[i] != 0) {
            printf("%+dx^%d ", coeff2[i], i);
        }
    }
    printf("\n");

    // Сложение многочленов
    int isEmpty = 1;
    printf("L = ");
    for (int i = degree; i >= 0; i--) {
        int sum = coeff1[i] + coeff2[i];
        if (sum != 0) {
            isEmpty = 0;
            printf("%+dx^%d ", sum, i);
        }
    }

    if (isEmpty) {
        printf("0"); // Выводим 0, если многочлен пустой
    }

    printf("\n");

    return 0;
}
