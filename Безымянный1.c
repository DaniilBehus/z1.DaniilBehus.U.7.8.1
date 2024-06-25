#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// ������� ��� ��������� SVG ���� ��� ����� (polyline)
void SVG_KRESLI_SPLINE(FILE *file, const float *x, const float *y, int n) {
    // ����������� ��������� �� ������������ ������� x �� y ��� ���������� ����������
    float minX = x[0], maxX = x[0], minY = y[0], maxY = y[0];
    int i; // ����� i ��� ��������� � ������
    for (i = 1; i < n; i++) {
        if (x[i] < minX) minX = x[i];
        if (x[i] > maxX) maxX = x[i];
        if (y[i] < minY) minY = y[i];
        if (y[i] > maxY) maxY = y[i];
    }

    // ���������� �������� �� ����� ��� ����������� ��������� �� ������� 0-100
    float scaleX = 100 / (maxX - minX);
    float scaleY = 100 / (maxY - minY);
    float offsetX = -minX * scaleX;
    float offsetY = -minY * scaleY;

    // ������� SVG ��������� � ������ 100x100 ������
    fprintf(file, "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 100 100\">\n");

    // ��������� ������������� �� ����������� �� � ��������� �����������
    fprintf(file, "  <line x1=\"0\" y1=\"%.2f\" x2=\"100\" y2=\"%.2f\" stroke=\"black\" />\n", 100 - offsetY, 100 - offsetY);
    fprintf(file, "  <line x1=\"%.2f\" y1=\"0\" x2=\"%.2f\" y2=\"100\" stroke=\"black\" />\n", offsetX, offsetX);

    // ���������� ����
    for (i = ceil(minX); i <= floor(maxX); i++) {
        fprintf(file, "  <text x=\"%.2f\" y=\"%.2f\" font-size=\"3\" text-anchor=\"middle\">%.0f</text>\n", 
               i * scaleX + offsetX, 100 - offsetY + 5, i);
    }
    for (i = ceil(minY); i <= floor(maxY); i++) {
        fprintf(file, "  <text x=\"%.2f\" y=\"%.2f\" font-size=\"3\" text-anchor=\"end\" alignment-baseline=\"middle\">%.0f</text>\n", 
               offsetX - 5, 100 - (i * scaleY + offsetY), i);
    }

    // ������� �������� polyline ��� ��������� ��
    fprintf(file, "  <polyline points=\"");

    // ���� ��� ��������� ��������� ����� � ����� � ������������
    int j;
    for (i = 0, j = 0; i < n; i++, j++) {
        fprintf(file, "%.2f,%.2f ", x[j] * scaleX + offsetX, 100 - (y[j] * scaleY + offsetY));
    }

    // ʳ���� �������� polyline �� SVG ���������
    fprintf(file, "\" fill=\"none\" stroke=\"red\" />\n</svg>\n");
}

// ������� �������
int main() {
    // ����������� ���������� ���������� �����
    srand(time(NULL));

    // ʳ������ ����� ��� �����
    int n = 10;

    // �������� �������� ���'�� ��� ������ ���������
    float *x = (float*)malloc(n * sizeof(float));
    float *y = (float*)malloc(n * sizeof(float));

    // ��������, �� ������� ��������� ���'���
    if (x == NULL || y == NULL) {
        fprintf(stderr, "�������: �� ������� ������� ���'���.\n");
        return 1;
    }

    // ���� ��� ��������� ���������� ��������� ����ֲ�
    float i; // ����� i ��� ��������� � ����
    int j; // ����� j ��� ���������� ������
    for (i = 0, j = 0; i < n; i++, j++) { // ������������� j �� ������
        x[j] = (float)i / (n - 1) * 10; // �������� x �� 0 �� 10
        y[j] = sin(x[j]);               // ������������� j ��� ���������� x
    }

    // ³������� ����� graph.svg ��� ������
    FILE *file = fopen("graph.svg", "w");
    if (file == NULL) {
        fprintf(stderr, "�������: �� ������� ������� ���� graph.svg ��� ������.\n");
        free(x); // ��������� ���'�� ����� ������� � ��������
        free(y);
        return 1;
    }

    // ������ ������� ��� ��������� SVG ���� (����� ������ � ����)
    SVG_KRESLI_SPLINE(file, x, y, n);

    // �������� �����
    fclose(file);

    // ��������� ������� ���'��
    free(x);
    free(y);

    return 0;
}

