Voici un modèle de fichier README pour GitHub qui décrit votre projet de manière claire et engageante :

---

# Gestion des Villes - Application en C

Bienvenue dans le projet "Gestion des Villes", une application en C permettant de gérer une liste de villes. Vous pouvez ajouter, supprimer et modifier des informations sur les villes, telles que le code de la ville, le nom, la latitude et la longitude.

## Fonctionnalités

- **Affichage des Villes** : L'application affiche une liste des villes contenue dans un fichier CSV.
- **Ajout d'une Ville** : Vous pouvez ajouter de nouvelles villes en spécifiant un code, un nom, une latitude et une longitude.
- **Suppression d'une Ville** : Supprimez une ville en utilisant son code unique.
- **Modification d'une Ville** : Modifiez les informations d'une ville en fonction de son code.

## Prérequis

- Un compilateur C (comme GCC)
- Un terminal ou une interface de ligne de commande

## Installation

1. Clonez ce projet dans votre répertoire local :
   ```bash
   git clone https://github.com/votre-utilisateur/gestion-des-villes.git
   ```

2. Accédez au répertoire du projet :
   ```bash
   cd gestion-des-villes
   ```

3. Compilez le programme en utilisant GCC :
   ```bash
   gcc -o gestion_villes gestion_villes.c
   ```

4. Exécutez le programme :
   ```bash
   ./gestion_villes
   ```

## Utilisation

Une fois l'application lancée, vous verrez un menu interactif avec les options suivantes :

- **A** : Ajouter une nouvelle ville
- **S** : Supprimer une ville existante
- **M** : Modifier les informations d'une ville
- **Q** : Quitter le programme

### Exemple de menu :
```bash
+-------------+-------------------+------------+------------+
|    CODE     |      VILLE        |  LATITUDE  | LONGITUDE  |
+-------------+-------------------+------------+------------+
| 123         | Paris             | 48.8566    | 2.3522     |
+-------------+-------------------+------------+------------+

Menu:
A) Ajouter une ville
S) Supprimer une ville
M) Modifier une ville
Q) Quitter
```

## Structure du Fichier CSV

Le programme utilise un fichier CSV (`dataville.csv`) pour stocker les informations des villes. Le fichier doit respecter le format suivant :
```
Code,Nom,Latitude,Longitude
```

Exemple :
```
123,Paris,48.8566,2.3522
456,London,51.5074,-0.1278
```

## Contribuer

Si vous souhaitez contribuer à ce projet, vous pouvez fork ce dépôt et soumettre une pull request avec vos améliorations ou corrections. N'oubliez pas de tester vos modifications avant de les soumettre.

## Licence

Ce projet est sous licence MIT - voir le fichier [LICENSE](LICENSE) pour plus de détails.

---
