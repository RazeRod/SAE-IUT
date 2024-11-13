#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_VILLES 100

typedef struct {
    char code[10];
    char nom[50];
    float latitude;
    float longitude;
} structcsv;

// Prototypes des fonctions
void afficher_villes(FILE *fichier);
void ajouter_ville(FILE *fichier);
void supprimer_ville(FILE *fichier);
void modifier_ville(FILE *fichier);

int main() {
    FILE *fichier = fopen("dataville.csv", "r+");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    // Affichage par défaut des villes

    char choix;
    while (1) {
        // Afficher le menu
        afficher_villes(fichier);
        printf("\nMenu:\n");
        printf("A) Ajouter une ville\n");
        printf("S) Supprimer une ville\n");
        printf("M) Modifier une ville\n");
        printf("Q) Quitter\n");
        printf("Choisissez une option: ");
        scanf("%c", &choix);
        getchar(); // Vider le buffer de l'entrée

        if (choix == 'A' || choix == 'a') {
            ajouter_ville(fichier);
        } else if (choix == 'S' || choix == 's') {
            supprimer_ville(fichier);
        } else if (choix == 'M' || choix == 'm') {
            modifier_ville(fichier);
        } else if (choix == 'Q' || choix == 'q') {
            break; // Quitter le programme
        } else {
            printf("Option invalide.\n");
        }
    }

    fclose(fichier);
    return 0;
}

void afficher_villes(FILE *fichier) {
    char ligne[MAX_LINE_LENGTH];
    fseek(fichier, 0, SEEK_SET);  // Remise du curseur au début du fichier

    // Lire et ignorer la première ligne (l'en-tête)
    fgets(ligne, MAX_LINE_LENGTH, fichier);

    printf("+-------------+-------------------+------------+------------+\n");
    printf("|    CODE     |      VILLE        |  LATITUDE  | LONGITUDE  |\n");
    printf("+-------------+-------------------+------------+------------+\n");

    // Lire et afficher chaque ligne du fichier
    while (fgets(ligne, MAX_LINE_LENGTH, fichier)) {
        structcsv ville;
        sscanf(ligne, "%[^,],%[^,],%f,%f", ville.code, ville.nom, &ville.latitude, &ville.longitude);
        printf("| %-11s | %-17s | %-10.4f | %-10.4f |\n", ville.code, ville.nom, ville.latitude, ville.longitude);
    }

    printf("+-------------+-------------------+------------+------------+\n");
}


void ajouter_ville(FILE *fichier) {
    structcsv nouvelle_ville;

    // Demander à l'utilisateur de saisir les données de la nouvelle ville
    printf("Entrez le code de la ville: ");
    fgets(nouvelle_ville.code, sizeof(nouvelle_ville.code), stdin);
    nouvelle_ville.code[strcspn(nouvelle_ville.code, "\n")] = '\0'; // Enlever le saut de ligne

    printf("Entrez le nom de la ville: ");
    fgets(nouvelle_ville.nom, sizeof(nouvelle_ville.nom), stdin);
    nouvelle_ville.nom[strcspn(nouvelle_ville.nom, "\n")] = '\0'; // Enlever le saut de ligne

    printf("Entrez la latitude: ");
    scanf("%f", &nouvelle_ville.latitude);

    printf("Entrez la longitude: ");
    scanf("%f", &nouvelle_ville.longitude);
    getchar(); // Vider le buffer

    // Réouvrir le fichier en mode append pour ajouter la ville
    FILE *fichier_temp = fopen("dataville.csv", "a");
    if (fichier_temp == NULL) {
        printf("Erreur lors de l'ouverture du fichier pour ajout.\n");
        return;
    }

    fprintf(fichier_temp, "%s,%s,%.4f,%.4f\n", nouvelle_ville.code, nouvelle_ville.nom, nouvelle_ville.latitude, nouvelle_ville.longitude);
    fclose(fichier_temp);
    printf("Ville ajoutée avec succès.\n");
}

void supprimer_ville(FILE *fichier) {
    char code[10];
    FILE *fichier_temp = fopen("dataville_temp.csv", "w");

    if (fichier_temp == NULL) {
        printf("Erreur lors de l'ouverture du fichier temporaire.\n");
        return;
    }

    printf("Entrez le code de la ville à supprimer: ");
    fgets(code, sizeof(code), stdin);
    code[strcspn(code, "\n")] = '\0'; // Enlever le saut de ligne

    char ligne[MAX_LINE_LENGTH];
    fseek(fichier, 0, SEEK_SET);  // Remise du curseur au début du fichier

    // Copier toutes les lignes sauf celle à supprimer dans le fichier temporaire
    while (fgets(ligne, MAX_LINE_LENGTH, fichier)) {
        structcsv ville;
        sscanf(ligne, "%[^,],%[^,],%f,%f", ville.code, ville.nom, &ville.latitude, &ville.longitude);
        
        // Si le code ne correspond pas à celui que l'on veut supprimer, on écrit dans le fichier temporaire
        if (strcmp(ville.code, code) != 0) {
            fprintf(fichier_temp, "%s,%s,%.4f,%.4f\n", ville.code, ville.nom, ville.latitude, ville.longitude);
        }
    }

    fclose(fichier_temp);
    fclose(fichier);
    // Supprimer l'ancien fichier et renommer le fichier temporaire
    remove("dataville.csv");
    rename("dataville_temp.csv", "dataville.csv");
    printf("Ville supprimée avec succès.\n");
}

void modifier_ville(FILE *fichier) {
    char code[10];
    FILE *fichier_temp = fopen("dataville_temp.csv", "w");

    if (fichier_temp == NULL) {
        printf("Erreur lors de l'ouverture du fichier temporaire.\n");
        return;
    }

    printf("Entrez le code de la ville à modifier: ");
    fgets(code, sizeof(code), stdin);
    code[strcspn(code, "\n")] = '\0'; // Enlever le saut de ligne

    char ligne[MAX_LINE_LENGTH];
    fseek(fichier, 0, SEEK_SET);  // Remise du curseur au début du fichier

    int trouve = 0;
    // Lire chaque ligne, modifier la ville si nécessaire, et la réécrire
    while (fgets(ligne, MAX_LINE_LENGTH, fichier)) {
        structcsv ville;
        sscanf(ligne, "%[^,],%[^,],%f,%f", ville.code, ville.nom, &ville.latitude, &ville.longitude);
        
        if (strcmp(ville.code, code) == 0) {
            // Ville trouvée, demander les nouvelles informations
            trouve = 1;
            printf("Entrez le nouveau nom de la ville: ");
            fgets(ville.nom, sizeof(ville.nom), stdin);
            ville.nom[strcspn(ville.nom, "\n")] = '\0';

            printf("Entrez la nouvelle latitude: ");
            scanf("%f", &ville.latitude);

            printf("Entrez la nouvelle longitude: ");
            scanf("%f", &ville.longitude);
            getchar(); // Vider le buffer
        }

        fprintf(fichier_temp, "%s,%s,%.4f,%.4f\n", ville.code, ville.nom, ville.latitude, ville.longitude);
    }

    if (trouve) {
        printf("Ville modifiée avec succès.\n");
    } else {
        printf("Code de ville introuvable.\n");
    }

    fclose(fichier_temp);
    fclose(fichier);
    // Supprimer l'ancien fichier et renommer le fichier temporaire
    remove("dataville.csv");
    rename("dataville_temp.csv", "dataville.csv");
}
&