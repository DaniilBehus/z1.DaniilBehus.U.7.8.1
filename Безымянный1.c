#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Функція для створення SVG коду для кривої (polyline)
void SVG_KRESLI_SPLINE(FILE *file, const float *x, const float *y, int n) {
    // Знаходження мінімальних та максимальних значень x та y для динамічного окотування
    float minX = x[0], maxX = x[0], minY = y[0], maxY = y[0];
    int i; // Змінна i для обчислень у циклах
    for (i = 1; i < n; i++) {
        if (x[i] < minX) minX = x[i];
        if (x[i] > maxX) maxX = x[i];
        if (y[i] < minY) minY = y[i];
        if (y[i] > maxY) maxY = y[i];
    }

    // Обчислення масштабу та зсуву для нормалізації координат на діапазон 0-100
    float scaleX = 100 / (maxX - minX);
    float scaleY = 100 / (maxY - minY);
    float offsetX = -minX * scaleX;
    float offsetY = -minY * scaleY;

    // Початок SVG документа з вирізом 100x100 пікселів
    fprintf(file, "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 100 100\">\n");

    // Додавання горизонтальної та вертикальної осі з динамічним окотуванням
    fprintf(file, "  <line x1=\"0\" y1=\"%.2f\" x2=\"100\" y2=\"%.2f\" stroke=\"black\" />\n", 100 - offsetY, 100 - offsetY);
    fprintf(file, "  <line x1=\"%.2f\" y1=\"0\" x2=\"%.2f\" y2=\"100\" stroke=\"black\" />\n", offsetX, offsetX);

    // Окотування осей
    for (i = ceil(minX); i <= floor(maxX); i++) {
        fprintf(file, "  <text x=\"%.2f\" y=\"%.2f\" font-size=\"3\" text-anchor=\"middle\">%.0f</text>\n", 
               i * scaleX + offsetX, 100 - offsetY + 5, i);
    }
    for (i = ceil(minY); i <= floor(maxY); i++) {
        fprintf(file, "  <text x=\"%.2f\" y=\"%.2f\" font-size=\"3\" text-anchor=\"end\" alignment-baseline=\"middle\">%.0f</text>\n", 
               offsetX - 5, 100 - (i * scaleY + offsetY), i);
    }

    // Початок елементу polyline для малювання лінії
    fprintf(file, "  <polyline points=\"");

    // Цикл для додавання координат точок у криву з нормалізацією
    int j;
    for (i = 0, j = 0; i < n; i++, j++) {
        fprintf(file, "%.2f,%.2f ", x[j] * scaleX + offsetX, 100 - (y[j] * scaleY + offsetY));
    }

    // Кінець елементу polyline та SVG документа
    fprintf(file, "\" fill=\"none\" stroke=\"red\" />\n</svg>\n");
}

// Головна функція
int main() {
    // Ініціалізація генератора випадкових чисел
    srand(time(NULL));

    // Кількість точок для кривої
    int n = 10;

    // Динамічна алокація пам'яті для масивів координат
    float *x = (float*)malloc(n * sizeof(float));
    float *y = (float*)malloc(n * sizeof(float));

    // Перевірка, чи вдалося алокувати пам'ять
    if (x == NULL || y == NULL) {
        fprintf(stderr, "Помилка: Не вдалося виділити пам'ять.\n");
        return 1;
    }

    // Цикл для генерації випадкових координат ФУНКЦІЇ
    float i; // Змінна i для обчислень у циклі
    int j; // Змінна j для індексації масивів
    for (i = 0, j = 0; i < n; i++, j++) { // Використовуємо j як індекс
        x[j] = (float)i / (n - 1) * 10; // Значення x від 0 до 10
        y[j] = sin(x[j]);               // Використовуємо j для індексації x
    }

    // Відкриття файлу graph.svg для запису
    FILE *file = fopen("graph.svg", "w");
    if (file == NULL) {
        fprintf(stderr, "Помилка: Не вдалося відкрити файл graph.svg для запису.\n");
        free(x); // Звільнення пам'яті перед виходом з програми
        free(y);
        return 1;
    }

    // Виклик функції для створення SVG коду (тепер записує у файл)
    SVG_KRESLI_SPLINE(file, x, y, n);

    // Закриття файлу
    fclose(file);

    // Звільнення виділеної пам'яті
    free(x);
    free(y);

    return 0;
}

