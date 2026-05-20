#include <stdio.h>
#include "app.h"

int main() {

    ucitaj();

    int izbor;

    do {
        printf("\nBAC MENU\n");
        printf("1. Dodaj\n");
        printf("2. Prikazi\n");
        printf("3. Azuriraj\n");
        printf("4. Obrisi\n");
        printf("5. Sortiraj\n");
        printf("6. Pretrazi\n");
        printf("7. Spremi\n");
        printf("0. Izlaz\n");
        printf("Izbor: ");

        scanf("%d", &izbor);

        switch (izbor) {

        case 1: dodaj(); break;
        case 2: prikazi(); break;
        case 3: update(); break;
        case 4: obrisi(); break;
        case 5: sortiraj(); break;
        case 6: pretrazi(); break;
        case 7: spremi(); break;
        }

    } while (izbor != 0);

    spremi();

    return 0;
}