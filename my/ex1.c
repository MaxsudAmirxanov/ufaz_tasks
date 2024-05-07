#include <stdio.h>
#include <math.h>

double sqrt_newton(double a, double tolerance) {
    double u = a; // Начальное значение
    double u_next;
    
    // Итеративное улучшение
    do {
        u_next = (u + a / u) / 2;
        if (fabs(u_next - u) < tolerance) // Проверка на сходимость
            return u_next;
        u = u_next;
    } while (1);
}

int main() {
    double a = 10; // Число, из которого мы хотим найти квадратный корень
    double tolerance = 1e-10; // Порог точности
    
    double result = sqrt_newton(a, tolerance);
    printf("Квадратный корень из %.2f приблизительно равен %.8f\n", a, result);
    
    return 0;
}