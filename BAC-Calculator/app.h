#ifndef APP_H
#define APP_H

typedef struct {
    char spol;
    int tezina;
    int pivo;
    int vino;
    int zestoko;
    int start_sat;
    int end_sat;

    float bac;
} Korisnik;


float izracunBAC(Korisnik k);

void dodaj();
void prikazi();
void update();
void obrisi();
void spremi();
void ucitaj();
void sortiraj();
void pretrazi();

#endif