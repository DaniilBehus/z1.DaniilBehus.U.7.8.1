#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <math.h>

// Funkcia na generovanie SVG kodu pre krivku (polyline)
char SVG_KRESLI_SPLINE(FILE *file, const float *x, const float *y, int n) {
    // Kontrola, ci bolo zadane dostatocne mnozstvo bodov
    if (n < 2) {
        fprintf(stderr, "Chyba: Treba zadat aspon dva body.\n");
        return 0; 
    }

    // Zacinok SVG dokumentu s oblastou zobrazenia od -50 do +50 po oboch osiach
    fprintf(file, "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"-50 -50 100 100\">\n");

    // Pridanie vodorovnej osi (OX) od -50 do +50 s oznaceniami kazdych 10 jednotiek
    {
        int i;
        fprintf(file, "  <line x1=\"-50\" y1=\"0\" x2=\"50\" y2=\"0\" stroke=\"black\" />\n");
        for (i = -50; i <= 50; i += 10) {
            fprintf(file, "  <text x=\"%d\" y=\"-3\" font-size=\"3\" text-anchor=\"middle\">%d</text>\n", i, i);
            fprintf(file, "  <line x1=\"%d\" y1=\"-1\" x2=\"%d\" y2=\"1\" stroke=\"black\" />\n", i, i);
        }
    }

    // Pridanie zvislej osi (OY) od -50 do +50 s oznaceniami kazdych 10 jednotiek
    {
        int i;
        fprintf(file, "  <line x1=\"0\" y1=\"-50\" x2=\"0\" y2=\"50\" stroke=\"black\" />\n");
        for (i = -50; i <= 50; i += 10) {
            fprintf(file, "  <text x=\"3\" y=\"%d\" font-size=\"3\" text-anchor=\"start\">%d</text>\n", -i, i);
            fprintf(file, "  <line x1=\"-1\" y1=\"%d\" x2=\"1\" y2=\"%d\" stroke=\"black\" />\n", -i, -i);
        }
    }

    // Zacinok elementu polyline na kreslenie ciar
    fprintf(file, "  <polyline points=\"");

    // Cyklus na pridanie suradnic bodov do krivky
    {
        int i;
        for (i = 0; i < n; i++) {
            // Obmedzenie suradnic x a y do rozsahu od -50 do +50
            float clamped_x = (x[i] < -50) ? -50 : ((x[i] > 50) ? 50 : x[i]);
            float clamped_y = (y[i] < -50) ? -50 : ((y[i] > 50) ? 50 : y[i]);
            // Transformacia suradnice y pre zobrazenie v hornej casti SVG
            fprintf(file, "%.2f,%.2f ", clamped_x, -clamped_y); // -clamped_y transformuje y suradnicu do SVG suradnice
        }
    }

    // Ukoncenie elementu polyline
    fprintf(file, "\" fill=\"none\" stroke=\"red\" />\n");

    // Koniec SVG dokumentu
    fprintf(file, "</svg>");

    return 1; 
}

// Hlavna funkcia
int main() {
    // Otvaranie suboru graph.svg na zapis
    FILE *file = fopen("graph.svg", "w");
    if (file == NULL) {
        perror("Chyba pri otvarani suboru");
        return 1;
    }

    // Inicializacia generatora nahodnych cisel
    srand((unsigned int)time(NULL));

    // Pocet bodov pre krivku
    int n = 100;

    // Dynamicke alokovanie pamate pre polia suradnic
    float *x = (float*)malloc(n * sizeof(float));
    float *y = (float*)malloc(n * sizeof(float));

    // Kontrola, ci sa pamat uspesne alokovala
    if (x == NULL || y == NULL) {
        fprintf(stderr, "Chyba: Nepodarilo sa alokovat pamat. (%s)\n", strerror(errno)); 
        fclose(file);
        return 1;
    }

    // Nahodny vyber funkcie (od 1 do 3)
    int func_choice = (rand() % 3) + 1;

    // Vybrane parametre funkcii
    int K, F, M, A, D, H, L, J, C, E, O;
    int P_func_choice;

    switch (func_choice) {
        case 1:
            // Prva funkcia: y = K + F * (M + x^A)
            K = (rand() % 21) - 10;  // K od -10 do 10
            F = (rand() % 41) - 20;  // F od -20 do 20
            M = (rand() % 61) - 30;  // M od -30 do 30
            A = (rand() % 11) - 5;   // A od -5 do 5
            printf("Zvolena funkcia: y = K + F * (M + x^A)\n");
            printf("Hodnota K: %d\n", K);
            printf("Hodnota F: %d\n", F);
            printf("Hodnota M: %d\n", M);
            printf("Hodnota A: %d\n", A);
            {
                int i;
                for (i = 0; i < n; i++) {
                    x[i] = (float)(i - 50); // x bude -50, -49, -48, ..., 49
                    if (x[i] == 0 && A < 0) { // Vyhneme sa deleniu nulou pri zapornych exponentoch
                        y[i] = K + F * M;
                    } else {
                        y[i] = K + F * (M + powf(x[i], A)); // y bude K + F * (M + x[i] na A)
                    }
                }
            }
            break;
        case 2:
            // Druha funkcia: y = D + H * sqrt[J](x + L)
            D = (rand() % 61) - 30;  // D od -30 do 30
            H = (rand() % 11) - 5;   // H od -5 do 5
            L = (rand() % 61) - 30;  // L od -30 do 30
            J = (rand() % 11) - 5;   // J od -5 do 5
            if (J == 0) J = 1;       // Vyhneme sa deleniu nulou
            printf("Zvolena funkcia: y = D + H * sqrt[J](x + L)\n");
            printf("Hodnota D: %d\n", D);
            printf("Hodnota H: %d\n", H);
            printf("Hodnota L: %d\n", L);
            printf("Hodnota J: %d\n", J);
            {
                int i;
                for (i = 0; i < n; i++) {
                    x[i] = (float)(i - 50); // x bude -50, -49, -48, ..., 49
                    if (x[i] + L < 0) {
                        y[i] = D; // sqrt nie je definovane pre zaporne cisla, preto pouzivame D
                    } else {
                        y[i] = D + H * powf(x[i] + L, 1.0f / J); // y bude D + H * (sqrt[J](x + L))
                    }
                }
            }
            break;
        case 3:
            // Tretia funkcia: y = C + E * P(x)^O
            C = (rand() % 61) - 30;  // C od -30 do 30
            E = (rand() % 11) - 5;   // E od -5 do 5
            O = (rand() % 11) - 5;   // O od -5 do 5
            P_func_choice = (rand() % 4);  // Nahodny vyber funkcie P (0: sin, 1: cos, 2: tan, 3: cotan)
            const char *P_func_name;
            printf("Zvolena funkcia: y = C + E * P(x)^O\n");
            printf("Hodnota C: %d\n", C);
            printf("Hodnota E: %d\n", E);
            printf("Hodnota O: %d\n", O);
            printf("Hodnota P_func_choice: %d\n", P_func_choice);
            {
                int i;
                for (i = 0; i < n; i++) {
                    x[i] = (float)(i - 50); // x bude -50, -49, -48, ..., 49
                    float P;
                    switch (P_func_choice) {
                        case 0:
                            P = sinf(x[i]);
                            P_func_name = "sin";
                            break;
                        case 1:
                            P = cosf(x[i]);
                            P_func_name = "cos";
                            break;
                        case 2:
                            P = tanf(x[i]);
                            P_func_name = "tan";
                            break;
                        case 3:
                            if (x[i] == 0) {
                                P = 0; // cotan(0) nie je definovany
                            } else {
                                P = 1.0f / tanf(x[i]);
                            }
                            P_func_name = "cotan";
                            break;
                    }
                    if (O == 0) O = 1; // Vyhneme sa deleniu nulou alebo umocnovaniu na nultu
                    y[i] = C + E * powf(P, O); // y bude C + E * (P(x)^O)
                }
                printf("Pouzita funkcia P: %s(x)\n", P_func_name);
            }
            break;
    }

    // Volanie funkcie na generovanie SVG grafu
    char result = SVG_KRESLI_SPLINE(file, x, y, n);
    if (!result) {
        fprintf(stderr, "Chyba pri vytvarani SVG suboru.\n"); // Hlasenie o chybe pri vytvarani SVG
    }

    // Uvolnenie pamate
    free(x);
    free(y);
    fclose(file); // Zatvorenie suboru

    return 0;
}

