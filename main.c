/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char code[10];
    char nom[50];
    float latitude;
    float longitude;
} structcsv;



void lire(){
    FILE *fichier = fopen("dataville.csv", "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }

    char ligne[MAX_LINE_LENGTH];
    structcsv villes;

    fgets(ligne, MAX_LINE_LENGTH, fichier);

    printf("+-------------+-------------------+------------+------------+\n");
    printf("|    CODE     |      VILLE        |  LATITUDE  | LONGITUDE  |\n");
    printf("+-------------+-------------------+------------+------------+\n");

    while (fgets(ligne, MAX_LINE_LENGTH, fichier)) {
        sscanf(ligne, "%[^,],%[^,],%f,%f", villes.code, villes.nom, &villes.latitude, &villes.longitude);

        printf("| %-11s | %-17s | %-10.4f | %-10.4f |\n", villes.code, villes.nom, villes.latitude, villes.longitude);
    }

    printf("+-------------+-------------------+------------+------------+\n");

    fclose(fichier);
}

int main() {
    lire();
    return 0;
}
