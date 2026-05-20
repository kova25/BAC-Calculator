#include <stdio.h>
#include <stdlib.h>
#include "app.h"

/*SAVE*/
void spremi(Korisnik* lista, int n) {

    FILE* f = fopen("bac.bin", "wb");

    if (!f) return;

    fwrite(&n, sizeof(int), 1, f);
    fwrite(lista, sizeof(Korisnik), n, f);

    fclose(f);
}

/*LOAD*/
void ucitaj(Korisnik** lista, int* n) {

    FILE* f = fopen("bac.bin", "rb");

    if (!f) return;

    fread(n, sizeof(int), 1, f);

    *lista = realloc(*lista, (*n) * sizeof(Korisnik));

    fread(*lista, sizeof(Korisnik), *n, f);

    fclose(f);
}

/*SORT*/
int cmp(const void* a, const void* b) {

    Korisnik* k1 = (Korisnik*)a;
    Korisnik* k2 = (Korisnik*)b;

    if (k1->bac < k2->bac) return 1;
    if (k1->bac > k2->bac) return -1;
    return 0;
}

void sortiraj(Korisnik* lista, int n) {
    qsort(lista, n, sizeof(Korisnik), cmp);
}

/*SEARCH*/
int cmpSearch(const void* a, const void* b) {

    Korisnik* k = (Korisnik*)a;
    float* x = (float*)b;

    if (k->bac < *x) return -1;
    if (k->bac > *x) return 1;
    return 0;
}

Korisnik* pretrazi(Korisnik* lista, int n, float key) {
    return (Korisnik*)bsearch(&key, lista, n, sizeof(Korisnik), cmpSearch);
}