V tomto projekte som vytvoril program, ktorý generuje SVG súbor. Tento
súbor obsahuje graf, ktorý je vytvorený na základe dát, ktoré som
zadefinoval v poliach x a y. Tieto polia predstavujú súradnice bodov na
grafe.

Funkcia SVG_KRESLI_SPLINE je hlavnou časťou tohto programu. Táto funkcia
prijíma súbor a tri parametre: polia x a y a počet bodov n. Najprv
skontroluje, či sú v poliach aspoň dva body. Ak nie, vypíše chybovú
správu.

Ak je podmienka splnená, funkcia pokračuje v generovaní SVG kódu. Najprv
vytvorí dve čiary, ktoré sa pretínajú v strede (predstavujú osi x a y),
a potom vytvorí polyline na základe zadaných bodov.

Vo funkcii main sa otvorí súbor graph.svg na zápis. Ak sa súbor nedá
otvoriť, vypíše sa chybová správa. Potom sa vytvoria dva polia x a y,
ktoré predstavujú súradnice bodov, a zavolá sa funkcia SVG_KRESLI_SPLINE
na vytvorenie SVG súboru s týmito bodmi.

Ak generovanie SVG kódu zlyhá, vypíše sa chybová správa. Inak sa súbor
zavrie a program sa ukončí.

Záver: Tento projekt mi umožnil lepšie pochopiť, ako môžem využiť svoje
znalosti programovania v jazyku C pre prácu so súbormi a vizualizáciu
dát.
