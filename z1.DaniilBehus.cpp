#include <stdio.h>

char SVG_KRESLI_SPLINE(FILE *file, float x[], float y[], int n) {
    if (n < 2) {
        printf("Chyba: Musite zadat aspon dva body zlomu.\n");
        return 0;
    }
	}
