//1
Prvá časť kódu definuje funkciu SVG_KRESLI_SPLINE, ktorá prijíma ukazovateľ na súbor, dva polia s hodnotami typu float (ktoré predstavujú súradnice bodov na grafe) a celé číslo (ktoré predstavuje počet bodov). Kontroluje, či sú v poliach aspoň dva body. Ak nie, vypíše sa chybová správa a vráti sa 0.
//2
Ak je podmienka splnená, funkcia pokračuje v generovaní SVG kódu. Najprv vytvorí dve čiary, ktoré sa pretínajú v strede (predstavujú osi x a y).
//3
Potom vytvorí polyline na základe zadaných bodov a uzavrie SVG súbor. Ak všetko prebehlo úspešne, funkcia vráti 1
//4
Vo funkcii main sa otvorí súbor graph.svg na zápis. Ak sa súbor nedá otvoriť, vypíše sa chybová správa a program sa ukončí s chybovým kódom 1
//5
V tejto časti kódu sa najprv inicializuje generátor náhodných čísel pomocou aktuálneho času (aby sa pri každom spustení programu generovali rôzne náhodné čísla). Potom sa v cykle for generujú náhodné hodnoty pre súradnice x a y bodov. 
//6
Nakoniec sa zavolá funkcia SVG_KRESLI_SPLINE na vytvorenie SVG súboru s týmito bodmi. Ak generovanie SVG kódu zlyhá, vypíše sa chybová správa. Inak sa súbor zavrie a program sa ukončí s návratovým kódom 0.

