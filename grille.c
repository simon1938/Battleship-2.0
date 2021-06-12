//
// Created by simon on 19/05/2021.
//

#include "grille.h"
#include <stdio.h>
#include "bateaux.h"
#include <strings.h>
#include <ctype.h>
/**
 * affiche la grille de départ sans les indications bateaux
 * @param grille
 */


// on a choisi de faire deux grille
// Une pour l'utilsateur ou on affichera les cases touchees apelee ...
// Une autre pour le programme où seront renseignées les postitions des bateaux (les cases sans bateaux recevront le charactere '-')


void initgrille(char grille[10][10], char tableau[10][10]) {


    int i, j;

    //fait en sorte que toutes les cases des deux tableaux prennent le charactere '-'
    
    for (i=0;i<10;i++){
        for (j=0;j<10;j++){
            grille[i][j]='_';
            tableau[i][j]='_';
        }
    }

}

void regles(){

    //affiche les regles et le nombre de bateaux en debut de partie

    printf("Le but est de coule les bateaux dissimules dans la grille\n");
    printf("Notre adversaire possede 5 bateaux:\n");
    printf(" - un de taille 5\n - un de taille 4\n - deux de taille 3\n - un de taille 2\n");

}

/**
 * affiche la grille avec les bateaux essentielement pour nous pour connaitre l'emplacement des bateaux pour faire test missile plus rapide.
 * @param grille
 */
void affiche_grille(char grille[10][10]){

    int i, j;

    printf("    0    1   2   3   4   5   6   7   8   9\n");
    for (i=0;i<10;i++){

        printf("   -----------------------------------------");
        printf("\n");
        printf("%d  ", i);
        for (j=0;j<10;j++){

            printf("| %c ", grille[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("  -----------------------------------------\n");
    printf("     0   1   2   3   4   5   6   7   8   9\n");

    printf("\n");


}

void grilleutilisateur(char grille[10][10]){

// affiche la grille a l'utilisateur pour qu'il voie les cases qu'il a touché
  
    int i, j;

    printf("utilisateur : \n");

    printf("    0    1   2   3   4   5   6   7   8   9\n");
    for (i=0;i<10;i++){

        printf("   -----------------------------------------");
        printf("\n");
        printf("%d  ", i);
        for (j=0;j<10;j++){;
            printf("| %c ", grille[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("  -----------------------------------------\n");
    printf("     0   1   2   3   4   5   6   7   8   9\n");




}

void affichecoup(char tableau[10][10], char grille[10][10], int visible, int nbimpact, boat* Bateaux2,boat* Bateaux3_1,boat* Bateaux3,boat* Bateaux4,boat* Bateaux5){

    
    //c'est cette variable qui gere l'affichage des grilles apres chaque coup ainsi que le nombre de bateaux touchés et les bateaux coulés 
    // dans le cas de l'artillerie qui passe deux fois sur la meme case, la case sur laquelle on repasse deux fois ne modifie la valeur de nbimpact qu'une seule fois
    
    if(visible==0){
        grilleutilisateur(tableau);
        affiche_grille(grille);
    }

    printf("vous avez touche des bateaux %d fois\n", nbimpact);


    if(Bateaux2->taille==0){
        printf("Yohoho Bateau de taille 2 coule\n");
        Bateaux2->taille=2;
    }

    if (Bateaux3->taille==0){
        printf("Bateau de taille 3 coule\n");
        Bateaux3->taille=3;
    }

    if(Bateaux3_1->taille==0){
        printf("Bateau de taille 3 coule\n");
        Bateaux3_1->taille=3;
    }

    if (Bateaux4->taille==0){
        printf("Bateau de taille 4 coule\n");
        Bateaux4->taille=4;
    }

    if (Bateaux5->taille==0){
        printf("Bateau de taille 5 coule\n");
        Bateaux5->taille=5;
    }
}

