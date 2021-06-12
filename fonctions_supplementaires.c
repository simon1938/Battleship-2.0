//
// Created by simon on 19/05/2021.
//

#include "fonctions_supplementaires.h"
#include <stdio.h>
#include "grille.h"
#include <stdlib.h>
#include <time.h>
#include"grille.h"
#include "bateaux.h"
#include<string.h>
#include<ctype.h>
#include <strings.h>

/** fonction qui affiche le menus du jeu et demande a l'utilisateur de choisir le niveau de difficulté
 * @return b le choix de level
 */
char debut_partie_choixlevel() {
    char a, b, c;
// affiche le menus de depart
    printf("\nBienvenue dans la bataille navale !\n\n");
    printf("Menu : \n");
    printf("    Demarrer une nouvelle partie (D)\n");
    printf("    Charger une partie existante (C)\n");
    printf("    Quitter (Q)\n");
    printf("Faites votre choix : \n");
    scanf("%c", &a);
    a = toupper(a);

    // on choisit d'utiliser un toupper pour que l'utilisateur puisse rentrer des charactere minuscules

    while (a != 'D' && a != 'C' && a != 'Q') {
//on repete tant que le mode de jeu n'est pas valide
        
        printf("\nErreur,la lettre entree ne correspond a aucun menus!\n");
        printf("Choississez la lettre de la partie souhaitee :\n");
        scanf(" %c", &a);
        a = toupper(a);
    }




//choix de la difficultée
    //on ne choisit la difficulte que si on demare une nouvelle partie, en effet, il ne sert a rein de le choisir si on quitte le jeu
    // et on peut pas choisir une nouvelle difficulte losrque que l'on charge une partie deja existante
    
        switch (a) {
                
            case 'Q' :
                return a;
                break;
                
            case 'C' :
                return a;
                break;
                
            case 'D' :
                
                fflush(stdin);
                
                printf("Choississez le niveau de difficulte :\n");
                printf("Facile (F)\n");
                printf("Moyen (M)\n");
                printf("Difficile (D)\n");
                
                //encore une fois on choisit de prendre un touppper
                
                gets(&b);
                b = toupper(b);

                
                // on repete la boucle tant que le niveau de difficulte n'est pas valide
                while (b != 'F' && b != 'M' && b != 'D') {
                    
                    fflush(stdin);
                    
                    printf("Erreur,la lettre entree ne correspond a aucun menus!\n");
                    printf("Veuillez choisir un niveau de difficulte : F, M ou D\n");
                    gets(&b);
                    b = toupper(b);

                }
                break;
        }
        return b;
    }




/**
 * fonction qui affiche le menus du jeu et permet retrourner le mode de jeu choisi par l'utilisateur
 * @return a le choix du mode
 */
char debut_partie_choixmode(){
    char a ;
            printf("\n");
            fflush(stdin);
            printf("Choissisez un mode de jeu :\n");
            printf("    Classique (C)\n");
            printf("    Blind (B)\n");
            printf("    Active (A)\n");
            scanf(" %c", &a);
            a = toupper(a);

            while (a != 'C' && a != 'B' && a != 'A') {
                printf("\n");
                printf("Erreur,la lettre entree ne correspond a aucun menus!\n");
                printf("choisissez un mode de jeu valide :");
                scanf(" %c", &a);
                a=toupper(a);
            }

    return a;


            }

char demande(){


    char rep;
    int valide=1;
//la bloucle se termine lorsque valide ne change pas de valeur, un mauvais choix d'action modifie la valeur de valide et l'ammene a 0
    
    do {
        printf("que voulez vous faire  ?\n Sauvegarder et quitter : S\n Jouer : J\n ");
        fflush(stdin);
        scanf("%c", &rep);
        
        // Encore une fois un toupper
        rep= toupper(rep);

        if(rep=='J' || rep=='S'){
            return rep;
        } else{
            printf("Erreur : option choisie non valide !");
            valide=0;
        }

    } while (valide==0);




}

void afficher_bateaux_battleship(){


    printf(" _           _   _   _           _     _       \n"
           "| |         | | | | | |         | |   (_)      \n"
           "| |__   __ _| |_| |_| | ___  ___| |__  _ _ __  \n"
           "| '_ \\ / _` | __| __| |/ _ \\/ __| '_ \\| | '_ \\ \n"
           "| |_) | (_| | |_| |_| |  __/\\__ \\ | | | | |_) |\n"
           "|_.__/ \\__,_|\\__|\\__|_|\\___||___/_| |_|_| .__/ \n"
           "                                        | |    \n"
           "                                        |_|    ");


    printf("# #  ( )\n"
           "                                  ___#_#___|__\n"
           "                              _  |____________|  _\n"
           "                       _=====| | |            | | |==== _\n"
           "                 =====| |.---------------------------. | |====\n"
           "   <--------------------'   .  .  .  .  .  .  .  .   '--------------/\n"
           "     \\                                                             /\n"
           "      \\_______________________________________________WWS_________/\n"
           "  wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n"
           "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n"
           "   wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww ");
}