#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void affiche_pendu(int nombre_erreurs) {
	/*
	Affiche l'état actuel du pendu en fonction du nombre d'erreurs commises
	*/
	printf(" +---+\n");
	printf(" |   |\n");
	switch (nombre_erreurs) {
	case 0:
		printf("     |\n");
		printf("     |\n");
		printf("     |\n");
		break;
	case 1:
		printf(" O   |\n");
		printf("     |\n");
		printf("     |\n");
		break;
	case 2:
		printf(" O   |\n");
		printf(" |   |\n");
		printf("     |\n");
		break;
	case 3:
		printf(" O   |\n");
		printf(" |\  |\n");
		printf("     |\n");
		break;
	case 4:
		printf(" O   |\n");
		printf("/|\  |\n");
		printf("     |\n");
		break;
	case 5:
		printf(" O   |\n");
		printf("/|\  |\n");
		printf("  \  |\n");
		break;
	case 6:
		printf(" O   |\n");
		printf("/|\  |\n");
		printf("/ \  |\n");
		break;
	}
	printf("     |\n");
	printf("========\n");
}

bool mot_trouve(char mot_a_verif[6], char mot_initial[6]) {
	for (int i = 0; i < 6; i++) {
		if (mot_a_verif[i] != mot_initial[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	char mot_a_trouver[6] = {' ',' ',' ',' ',' ',' '};
	int nombre_erreurs = 0;
	printf("ecrit un mot: ");
	for (int i = 0; i < 6; i++) {
		scanf(" %c", &mot_a_trouver[i]);
	}
	scanf(" %c", &mot_a_trouver);
	system("cls");

	char lettres_trouvees[6] = { '_','_','_','_','_','_' };

	while (nombre_erreurs < 6 && mot_trouve(lettres_trouvees, mot_a_trouver) == false) {

		printf("lettres deja trouvees: ");
		for (int i = 0; i < 6; i++) {
			printf("%c", lettres_trouvees[i]);
		}
		printf("\nnombre d'erreurs : %d", nombre_erreurs);

		char lettre;
		printf("\ndonne une lettre : ");
		scanf(" %c", &lettre);

		bool lettre_dans_un_mot = false;

		for (int i = 0; i < 6; i++) {
			if (mot_a_trouver[i] == lettre) {
				lettres_trouvees[i] = lettre;
				lettre_dans_un_mot = true;
			}
		}
		if (lettre_dans_un_mot == false) {
			nombre_erreurs = nombre_erreurs + 1;
		}

		system("cls");
		affiche_mot(a_afficher);
		affiche_pendu(nombre_erreurs);
		trouve = mot_trouve(a_afficher);
	}

	printf("\n\n");
	if (nombre_erreurs < 6) {
		printf("Bravo !\n");
	}
	else if (mot_trouve(lettres_trouvees, mot_a_trouver) == false) {
		printf("Dommage !\n");
	}
	printf("Mon mot est : ");
	for (int i = 0; i < 6; i++) {
		printf("%c", mot_a_trouver[i]);
	}
	printf("\n\n");

	return 0;
}