#include <stdio.h>
#include <stdlib.h>
#include "app.h"

Korisnik* lista=NULL;
int n=0;

/*BAC*/
float izracunBAC(Korisnik k){

    float alkohol=0;

    alkohol += k.pivo * 500 * 0.05f * 0.789f;
    alkohol += k.vino * 150 * 0.12f * 0.789f;
    alkohol += k.zestoko * 30 * 0.40f * 0.789f;

    float bac;

    if (k.spol == 'M' || k.spol == 'm')
        bac = alkohol / (k.tezina * 0.68f);
    else
        bac = alkohol / (k.tezina * 0.55f);

    int trajanje = k.end_sat - k.start_sat;
    if (trajanje < 0) trajanje = 0;

    bac -= 0.15f * trajanje;

    if (bac < 0) bac = 0;

    return bac;
}

/*CREATE*/
void dodaj(){

    lista = realloc(lista, (n + 1) * sizeof(Korisnik));

    Korisnik k;

    printf("Spol: ");
    scanf(" %c", &k.spol);

    printf("Tezina: ");
    scanf("%d", &k.tezina);

    printf("Pivo: ");
    scanf("%d", &k.pivo);

    printf("Vino: ");
    scanf("%d", &k.vino);

    printf("Zestoko: ");
    scanf("%d", &k.zestoko);

    printf("Start: ");
    scanf("%d", &k.start_sat);

    printf("End: ");
    scanf("%d", &k.end_sat);

    k.bac = izracunBAC(k);

    lista[n++]=k;

    printf("Dodano\n");
}

/*READ*/
void prikazi(){

    for (int i = 0; i < n; i++){
        printf("[%d] %c | BAC: %.2f\n",
            i + 1,
            lista[i].spol,
            lista[i].bac);
    }
}

/*UPDATE*/
void update(){

    int i;
    scanf("%d", &i);
    i--;

    if (i < 0 || i >= n) return;

    scanf("%d", &lista[i].tezina);
    lista[i].bac = izracunBAC(lista[i]);
}

/*DELETE*/
void obrisi() {

    int i;
    scanf("%d", &i);
    i--;

    for (int j = i; j < n - 1; j++)
        lista[j] = lista[j + 1];

    n--;
    lista = realloc(lista, n * sizeof(Korisnik));
}

/*SAVE*/
void spremi() {
    FILE* f = fopen("bac.bin", "wb");
    fwrite(&n, sizeof(int), 1, f);
    fwrite(lista, sizeof(Korisnik), n, f);
    fclose(f);
}

/*LOAD*/
void ucitaj() {
    FILE* f = fopen("bac.bin", "rb");
    if (!f) return;

    fread(&n, sizeof(int), 1, f);

    lista = realloc(lista, n * sizeof(Korisnik));

    fread(lista, sizeof(Korisnik), n, f);

    fclose(f);
}

/*SORT*/
int cmp(const void* a, const void* b) {
    Korisnik* k1 = (Korisnik*)a;
    Korisnik* k2 = (Korisnik*)b;
    return (k2->bac - k1->bac) > 0 ? 1 : -1;
}

void sortiraj() {
    qsort(lista, n, sizeof(Korisnik), cmp);
}

/*SEARCH*/
float key;

int cmpSearch(const void* a, const void* b) {
    return ((Korisnik*)a)->bac - *(float*)b;
}

void pretrazi() {
    scanf("%f", &key);
    bsearch(&key, lista, n, sizeof(Korisnik), cmpSearch);
}