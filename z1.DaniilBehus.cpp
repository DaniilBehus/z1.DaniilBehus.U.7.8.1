#include <stdio.h>
//1
char SVG_KRESLI_SPLINE(FILE *file, float x[], float y[], int n) {
    if (n < 2) {
        printf("Chyba: Musite zadat aspon dva body zlomu.\n");
        return 0;
    }
        //2
        fprintf(file, "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 100 100\">\n");
        fprintf(file, "<line x1=\"0\" y1=\"50\" x2=\"100\" y2=\"50\" stroke=\"black\"/>\n");
        fprintf(file, "<line x1=\"50\" y1=\"0\" x2=\"50\" y2=\"100\" stroke=\"black\"/>\n");
        //3
        fprintf(file, "<polyline points=\"");
    for (int i = 0; i < n; i++) {
        fprintf(file, "%.2f,%.2f ", x[i], 100 - y[i]); 
    }
    fprintf(file, "\" fill=\"none\" stroke=\"red\"/>\n");
    fprintf(file, "</svg>");
    return 1;
	}
    
   //4
  int main(){
    FILE *file = fopen("graph.svg", "w");
    if (file == NULL) {
        printf("Nepodarilo sa otvorit subor na zapis.\n");
        return 1;
    }
    //5
    float x[] = {10, 30, 50, 70, 90};
    float y[] = {20, 40, 60, 80, 50};
    int n = sizeof(x) / sizeof(x[0]);  
    //6
		char result = SVG_KRESLI_SPLINE(file, x, y, n);
    if (!result) {
        printf("Generovanie SVG kodu zlyhalo.\n");
    }

    fclose(file);

    return 0;
}  


