# MatrixKeypad
MatrixKeypad er en 4x4 keypad som er mest brugt på ATMs.

# Kravspecifikation
-Programmet skal indeholder det her metoder: **Init(); ColumnScan(); ReadRows(); DecodeKeyboard();** 

-Programmet skal kunne udskriver den specifik knap som personen har trykket.

-Der skal bruger Logik Analyzer så viser output portene.


![enter image description here](https://i.imgur.com/rT1wfdz.png)

Her er der billeder hvordan en keypad funger. Hvor vi har 4 *'Output Port'* og 4 *'Input Port'*
I min situation jeg har lagt  keypad pins til alle mine PORTK.

|Output Port|Arduino port  |
|--|--|
|C1  |PK3  |
|C2  |PK2 |
|C3  |PK1 |
|C4  |PK0 |

|Input Port|Arduino port  |
|--|--|
|R1  |PK4  |
|R2 |PK5|
|R3  |PK6 |
|R4  |PK7 |

Her er der billeder billeder af min *Logik Analyzer*
![enter image description here](https://i.imgur.com/T5p90uy.png)

# Funktioner
***Init()*** - Funktion der initialiser Pull-up.

***ColumnScan()*** - Funktion der styre C1-C4 via 4 portbit.

***ReadRows()*** - Funktion der læse R1-R4 og returner den specifik row.

***DecodeKeyboard()*** - Funktion som modtager column, row og decoder mine knapper på bestemt koloner og rækker.



Mine funktion proprieties ligger ind **keypad.h** filen og mine funktioner ligger ind i **keypad.c** filen.
