#include <stdio.h>

char SVG_KRESLI_SPLINE(FILE *file, float x[], float y[], int n) {
    if (n < 2) {
        printf("Chyba: Musite zadat aspon dva body zlomu.\n");
        return 0;
        
        fprintf(file, "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 100 100\">\n");
        fprintf(file, "<line x1=\"0\" y1=\"50\" x2=\"100\" y2=\"50\" stroke=\"black\"/>\n");
        fprintf(file, "<line x1=\"50\" y1=\"0\" x2=\"50\" y2=\"100\" stroke=\"black\"/>\n");
    }
	}
