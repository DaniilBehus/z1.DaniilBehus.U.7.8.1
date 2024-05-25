# SVG_KRESLI_SPLINE

## Popis funkcií

### Funkcia `SVG_KRESLI_SPLINE`

Táto funkcia vykonáva nasledujúce kroky:

1. **Kontrola vstupných údajov**:
    - Overuje, či je zadaný dostatočný počet bodov (aspoň dva) pre vytvorenie krivky (polyline).

2. **Vytvorenie SVG dokumentu**:
    - Vytvorí SVG dokument s definovanou oblasťou zobrazenia 100x100 pixelov.

3. **Pridanie osí**:
    - Pridá horizontálnu (os x) a vertikálnu (os y) os do grafu.

4. **Vytvorenie elementu polyline**:
    - Vytvorí element `<polyline>`, ktorý bude obsahovať súradnice bodov krivky.

5. **Transformácia a zápis súradníc**:
    - Transformuje súradnice bodov pre správne zobrazenie v SVG a zapíše ich do súboru.

6. **Ukončenie SVG**:
    - Uzavrie element `<polyline>` a ukončí SVG dokument.

7. **Návratová hodnota**:
    - Funkcia vráti hodnotu 1, čo signalizuje úspešné vykonanie funkcie.

### Funkcia `main`

Táto funkcia vykonáva nasledujúce kroky:

1. **Otvorenie súboru**:
    - Otvorí súbor `graph.svg` pre zápis. Ak sa vyskytne chyba, zobrazí chybové hlásenie a program sa ukončí.

2. **Inicializácia generátora náhodných čísel**:
    - Inicializuje generátor náhodných čísel, aby sa pri každom spustení získali rôzne súradnice.

3. **Nastavenie počtu bodov**:
    - Definuje počet bodov pre krivku.

4. **Alokácia pamäte**:
    - Dynamicky alokuje pamäť pre polia, ktoré budú uchovávať súradnice bodov. Ak alokácia zlyhá, zobrazí chybové hlásenie a program sa ukončí.

5. **Generovanie súradníc**:
    - Polia sa naplnia náhodnými súradnicami v rozsahu od 0 do 100.

6. **Vykreslenie krivky**:
    - Zavolá funkciu `SVG_KRESLI_SPLINE` na vytvorenie SVG kódu krivky.

7. **Uvoľnenie pamäte**:
    - Alokovaná pamäť sa uvoľní.

8. **Zatvorenie súboru**:
    - Súbor `graph.svg` sa zatvorí.

9. **Návratová hodnota**:
    - Funkcia vráti hodnotu 0, čo znamená úspešné ukončenie programu

