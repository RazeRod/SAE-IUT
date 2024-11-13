#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char code[10];
    char nom[50];
    float latitude;
    float longitude;
} structcsv;

int main() {
    FILE *fichier = fopen("dataville.csv", "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    char ligne[MAX_LINE_LENGTH];
    structcsv villes;

    // Lire et ignorer la première ligne d'en-tête
    fgets(ligne, MAX_LINE_LENGTH, fichier);

    // Affichage avec bordures ASCII
    printf("+-------------+-------------------+------------+------------+\n");
    printf("|    CODE     |      VILLE        |  LATITUDE  | LONGITUDE  |\n");
    printf("+-------------+-------------------+------------+------------+\n");

    while (fgets(ligne, MAX_LINE_LENGTH, fichier)) {
        // Lire les données dans la structure `villes`
        sscanf(ligne, "%[^,],%[^,],%f,%f", villes.code, villes.nom, &villes.latitude, &villes.longitude);

        // Afficher les données sous forme de tableau avec alignement
        printf("| %-11s | %-17s | %-10.4f | %-10.4f |\n", villes.code, villes.nom, villes.latitude, villes.longitude);
    }

    printf("+-------------+-------------------+------------+------------+\n");

    fclose(fichier);
    return 0;
}
