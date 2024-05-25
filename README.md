Funkcia SVG_KRESLI_SPLINE:

Kontrola vstupných údajov: Overuje sa, či je zadaný dostatočný počet bodov (aspoň dva) pre vytvorenie krivky (polyline).
Vytvorenie SVG dokumentu: Vytvorí sa SVG dokument s definovanou oblasťou zobrazenia 100x100 pixelov.
Pridanie osí: Do grafu sa pridajú horizontálna (os x) a vertikálna (os y) os.
Vytvorenie elementu polyline: Vytvorí sa element <polyline>, ktorý bude obsahovať súradnice bodov krivky.
Transformácia a zápis súradníc: Súradnice bodov sa transformujú pre správne zobrazenie v SVG a zapíšu sa do súboru.
Ukončenie SVG: Element <polyline> sa uzavrie a SVG dokument sa ukončí.
Návratová hodnota: Funkcia vráti hodnotu 1, čo signalizuje úspešné vykonanie funkcie.

Funkcia main:

Otvorenie súboru: Otvorí sa súbor graph.svg pre zápis. Ak sa vyskytne chyba, zobrazí sa chybové hlásenie a program sa ukončí.
Inicializácia generátora náhodných čísel: Inicializuje sa generátor náhodných čísel, aby sa pri každom spustení získali rôzne súradnice.
Nastavenie počtu bodov: Definuje sa počet bodov pre krivku.
Alokácia pamäte: Dynamicky sa alokuje pamäť pre polia, ktoré budú uchovávať súradnice bodov. Ak alokácia zlyhá, zobrazí sa chybové hlásenie a program sa ukončí.
Generovanie súradníc: Polia sa naplnia náhodnými súradnicami v rozsahu od 0 do 100.
Vykreslenie krivky: Zavolá sa funkcia SVG_KRESLI_SPLINE na vytvorenie SVG kódu krivky.
Uvoľnenie pamäte: Alokovaná pamäť sa uvoľní.
Zatvorenie súboru: Súbor graph.svg sa zatvorí.
Návratová hodnota: Funkcia vráti hodnotu 0, čo znamená úspešné ukončenie programu.

