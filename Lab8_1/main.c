#include <stdio.h>

int main() {
    int coeff1[] = {2, 0, -4, 0, 0, 7}; // Коэффициенты многочлена L1
    int coeff2[] = {0, -5, 1, 1, 0, -3}; // Коэффициенты многочлена L2
    int degree = 5; // Максимальная степень многочлена

    printf("L1 = ");
    for (int i = degree; i >= 0; i--) {
        if (coeff1[i] != 0) {
            printf("%+dx^%d ", coeff1[i], i);
        }
    }
    printf("\n");

    printf("L2 = ");
    for (int i = degree; i >= 0; i--) {
        if (coeff2[i] != 0) {
            printf("%+dx^%d ", coeff2[i], i);
        }
    }
    printf("\n");

    printf("L = ");
    for (int i = degree; i >= 0; i--) {
        int sum = coeff1[i] + coeff2[i];
        if (sum != 0) {
            printf("%+dx^%d ", sum, i);
        }
    }
    printf("\n");

    return 0;
}
