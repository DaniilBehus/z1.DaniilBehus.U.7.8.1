#include <stdio.h>
//
char SVG_KRESLI_SPLINE(FILE *file, float x[], float y[], int n) {
    if (n < 2) {
        printf("Chyba: Musite zadat aspon dva body zlomu.\n");
        return 0;
        //
        fprintf(file, "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 100 100\">\n");
        fprintf(file, "<line x1=\"0\" y1=\"50\" x2=\"100\" y2=\"50\" stroke=\"black\"/>\n");
        fprintf(file, "<line x1=\"50\" y1=\"0\" x2=\"50\" y2=\"100\" stroke=\"black\"/>\n");
        //
        fprintf(file, "<polyline points=\"");
    for (int i = 0; i < n; i++) {
        fprintf(file, "%.2f,%.2f ", x[i], 100 - y[i]); 
    }
    fprintf(file, "\" fill=\"none\" stroke=\"red\"/>\n");
    fprintf(file, "</svg>");
    return 1;
	}
