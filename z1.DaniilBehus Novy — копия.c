#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <math.h>

// Funkcia na vytvorenie SVG kodu pre krivku (polyline)
char SVG_KRESLI_SPLINE(FILE *file, const float *x, const float *y, int n) {
    // Kontrola, ci je zadany dostatocny pocet bodov
    if (n < 2) {
        fprintf(stderr, "Chyba: Je potrebne zadat aspon dva body zlomu.\n");
        return 0; 
    }

    // Zaciatok SVG dokumentu s vyrezom 100x100 pixelov
    fprintf(file, "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 100 100\">\n");

    // Pridanie horizontalnej a vertikalnej osi
    fprintf(file, "  <line x1=\"0\" y1=\"50\" x2=\"100\" y2=\"50\" stroke=\"black\" />\n");
    fprintf(file, "  <line x1=\"50\" y1=\"0\" x2=\"50\" y2=\"100\" stroke=\"black\" />\n");

    // Zaciatok elementu polyline pre kreslenie ciary
    fprintf(file, "  <polyline points=\"");

    // Cyklus pre pridanie suradnic bodov do krivky
    int i;
    for (i = 0; i < n; i++) {
        // Prevod suradnice y pre zobrazenie v hornej casti SVG
        fprintf(file, "%.2f,%.2f ", x[i], 100 - y[i]);
    }

    // Ukoncenie elementu polyline
    fprintf(file, "\" fill=\"none\" stroke=\"red\" />\n");

    // Koniec SVG dokumentu
    fprintf(file, "</svg>");

    return 1; 
}

// Hlavna funkcia
int main() {
    // Otvorenie suboru graph.svg na zapis
    FILE *file = fopen("graph.svg", "w");
    if (file == NULL) {
        perror("Chyba pri otvarani suboru");
        return 1;
    }

    // Inicializacia generatora nahodnych cisel
    srand(time(NULL));

    // Pocet bodov pre krivku
    int n = 5;

    // Dynamicka alokacia pamate pre polia suradnic
    float *x = (float*)malloc(n * sizeof(float));
    float *y = (float*)malloc(n * sizeof(float));

    // Kontrola, ci sa podarilo alokovat pamat
    if (x == NULL || y == NULL) {
        fprintf(stderr, "Chyba: Nepodarilo sa alokovat pamat. (%s)\n", strerror(errno)); 
        fclose(file);
        return 1;
    }

    // Cyklus pre generovanie nahodnych suradnic
    int i; 
    for (i = 0; i < n; i++) {
        x[i] = (float)rand() / RAND_MAX * 100;
        y[i] = (float)rand() / RAND_MAX * 100;
    }

    // Volanie funkcie na vytvorenie SVG kodu
    char result = SVG_KRESLI_SPLINE(file, x, y, n);
    if (!result) {
        fprintf(stderr, "Chyba generovania SVG kodu.\n"); // Vypis chyby generovania SVG
    }

    // Uvolnenie alokovanej pamate
    free(x);
    free(y);
    fclose(file); // Zatvorenie suboru

    return 0;
}


//PS
//Rozhodol som sa preformatovat ulohu z "CPP" na "C" a kvoli tomu som mal problemy.

//¹1 Prvy nie je problem s chybovym vystupom a na tento ucel som pouzil "stderr" a "#include <errno.h>"

//¹2 Namiesto pouzitia float x[n]; a float y[n];  Rozhodol som sa ho lepsie vyuzit na dynamicku alokaciu pamate pomocou malloc, kedze umozni pracu s poliami premenlivej dlzky.

//¹3 Kvoli prechodu na format "C" prvky "for (i = 0; i < n; i++)" nechceli fungova bez "-std=c99" a rozhodol som sa jednoducho pridat "int i" v pred nimi



