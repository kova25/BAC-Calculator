#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {

	char spol;
	int tezina;

	int vrstaPiva;
	int brojPiva;

	int brojCasaVina;

	int brojZestokihPica;

	float pocetakPijenja;
	float krajPijenja;

	float bac;

} Korisnik;

int main() {

	int izbor = 0;

	do {

		printf("\nBAC CALCULATOR\n");
		printf("1. Unos podataka\n");
		printf("0. Izlaz\n");
		printf("Odabir: ");

		scanf("%d", &izbor);

		switch (izbor) {

		case 1: {

			Korisnik korisnik;

			printf("\nUnesite spol(M/Z): ");
			scanf(" %c", &korisnik.spol);

			printf("Unesite tezinu(kg): ");
			scanf("%d", &korisnik.tezina);

			printf("\nPIVO\n");

			printf("1. Pivo 0.5L\n");
			printf("2. Pivo 0.33L\n");
			printf("Odaberite vrstu piva: ");
			scanf("%d", &korisnik.vrstaPiva);

			printf("Broj popijenih piva: ");
			scanf("%d", &korisnik.brojPiva);

			printf("\nVINO\n");

			printf("Broj casa vina: ");
			scanf("%d", &korisnik.brojCasaVina);

			printf("\nZESTOKA PICA\n");

			printf("Broj zestokih pica: ");
			scanf("%d", &korisnik.brojZestokihPica);

			printf("\nVrijeme pocetka pijenja (npr. 20.5): ");
			scanf("%f", &korisnik.pocetakPijenja);

			printf("Vrijeme zadnjeg pica (npr. 23.0): ");
			scanf("%f", &korisnik.krajPijenja);

			float ukupnoAlkohola = 0.0f;

			if (korisnik.vrstaPiva == 1) {

				ukupnoAlkohola += korisnik.brojPiva * 500 * 0.05f * 0.789f;

			}
			else if (korisnik.vrstaPiva == 2) {

				ukupnoAlkohola += korisnik.brojPiva * 330 * 0.05f * 0.789f;

			}

			ukupnoAlkohola += korisnik.brojCasaVina * 150 * 0.12f * 0.789f;

			ukupnoAlkohola += korisnik.brojZestokihPica * 30 * 0.40f * 0.789f;

			if (korisnik.spol == 'M' || korisnik.spol == 'm') {

				korisnik.bac = ukupnoAlkohola / (korisnik.tezina * 0.68f);

			}
			else {

				korisnik.bac = ukupnoAlkohola / (korisnik.tezina * 0.55f);

			}

			float protekloVrijeme = korisnik.krajPijenja - korisnik.pocetakPijenja;

			korisnik.bac -= protekloVrijeme * 0.15f;

			if (korisnik.bac < 0) {

				korisnik.bac = 0;

			}

			printf("\nPodaci uspjesno uneseni!\n");

			printf("\nUNESENI PODACI\n");

			printf("Spol: %c\n", korisnik.spol);
			printf("Tezina: %d kg\n", korisnik.tezina);

			if (korisnik.vrstaPiva == 1) {

				printf("Pivo 0.5L: %d\n", korisnik.brojPiva);

			}
			else if (korisnik.vrstaPiva == 2) {

				printf("Pivo 0.33L: %d\n", korisnik.brojPiva);

			}

			printf("Case vina: %d\n", korisnik.brojCasaVina);

			printf("Zestoka pica: %d\n", korisnik.brojZestokihPica);

			printf("Pocetak pijenja: %.1f\n", korisnik.pocetakPijenja);

			printf("Vrijeme zadnjeg pica: %.1f\n", korisnik.krajPijenja);

			printf("\nProcijenjeni BAC: %.2f promila\n", korisnik.bac);

			float vrijemeDoNule = korisnik.bac / 0.15f;

			printf("Vrijeme do 0.0 promila: %.1f sati\n", vrijemeDoNule);

			break;
		}

		case 0:
			printf("\nIzlaz iz programa...\n");
			break;

		default:
			printf("\nPogresan unos!\n");
		}

	} while (izbor != 0);

	return 0;
}