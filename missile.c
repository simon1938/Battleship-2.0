//
// Created by simon on 25/05/2021.
//

#include "missile.h"
#include <stdio.h>
#include "grille.h"
#include <stdlib.h>
#include <time.h>
#include"grille.h"
#include"fonctions_supplementaires.h"
#include "bateaux.h"
#include "inventaire.h"
#include<ctype.h>
/**
 * demande quel type de missile l'utilisateur veut tirer et met a jour l'inventaire en conséquence de plus et renvoye le type de missiles choisi
 * @param NB_missile
 * @return type missile (le choix du type de missille)
 */
char choix_type_missile(inventaire *NB_missile, char tableau[10][10], char grille[10][10], boat *Bateaux2,boat *Bateaux3_1,boat *Bateaux3,boat *Bateaux4,boat *Bateaux5, int visible) {
   // la fontion qui demande le choix du missile et appelera les differents codes de chaque missile
   // elle ne s'arretera pas tant qu'il reste des missiles

    char type_missile;
    int valide;




    int ligne, colonne;
    int nbimpact=0;
   
   // on a prefere afficher le nombre d'exemplaires de chaque missile pour eviter que l'utilsateur essaye d'un tirer un et de recommencer 
   // à essayer de le tirer en pensant que c'est le nom du missile rentré qui pose probleme
   // Cela lui permet aussi d'eviter d'essayer de tirer un missile pour se rendre compte qu'il n'a plus aucun exemplaire de celui ci

    printf("quel type de missile voulez vous choisir\nC : classique - %d exemplaires \nB: bombe - %d exemplaires \nA: artillerie - %d exemplaires \nT: tactique - %d exemplaires \n", NB_missile->simple, NB_missile->bombe, NB_missile->artillerie, NB_missile->tactique);


   
   
   // boucle qui ne s'arretera pas tant que le missile choisi n'est pas valide
   // on a decide d'intrduire une variable nomée "valide" qui prend la valeur 1 lorsque que le choix de missile n'est pas valide
   // la boucle se termine quand valide a la valeur 0
   
    do {
        valide=0;
        fflush(stdin);
        scanf("%c", &type_missile);
        type_missile=(type_missile);

       //Pour eviter les problemes, on ne diminue le nombre de missile que si celui ci est strictement supérieur à 0
       
        if (type_missile == 'C' && NB_missile->simple != 0) {
            NB_missile->simple = NB_missile->simple - 1;
            return type_missile;


        } else if (type_missile == 'B' && NB_missile->bombe != 0) {
            NB_missile->bombe = NB_missile->bombe - 1;
            return type_missile;


        } else if (type_missile == 'A' && NB_missile->artillerie != 0) {
            NB_missile->artillerie = NB_missile->artillerie - 1;
            return type_missile;




        } else if (type_missile == 'T' && NB_missile->tactique != 0) {
            NB_missile->tactique = NB_missile->tactique - 1;
            return type_missile;


        } else {
           
           // le message d'erreur s'affiche si le nom ne correspond pas ou si le nombre de missile et égal à 0
           
            printf("\nvous n'avez pas bien saisi le nom du missile ou bien vous avez épuisé votre stock de celui ci veuillez redonner un choix valide de missile\n  classique:C   %d exemplaires \nbombe:B  %d  exemplaires \nartillerie:A   %d  exemplaires \ntactique:T   %d   exemplaires ", NB_missile->simple, NB_missile->bombe, NB_missile->artillerie, NB_missile->tactique);
            valide=1;
        }
    } while (valide==1);

    return type_missile;

}





void verif(char tableau[10][10], char grille[10][10], int* ligne, int* colonne) {

    // Verif est la fonction qui permettera de rentrer les coordonnees du point d'impact "central" des missiles et qui s'assurera
    // que celui ci est valide

    int codeerreur=0;

    int colonne1;
    int ligne1;

   // tant que les coordonées selectionnées ne sont pas valables, la boucle continuera
   
    do {
        if (codeerreur == 1) {
            printf("erreur, les coordonnes rentrees ne sont pas valide\n");
        }
        codeerreur = 0;
        printf("veuillez rentrer les coordonnes souhaitees : \n");
       
       // on fait un fflsuh pour s'assurer de ne pas rencontrer de problemes avec les scanfs
       
        fflush(stdin);
        scanf("%d", &colonne1);
        scanf("%d", &ligne1);

        if (colonne1 < 0 || colonne1 > 9 || ligne1 < 0 || ligne1 > 9) {
            codeerreur = 1;
        }

    } while (codeerreur == 1);

   // la fonction sortira donc les valeurs des lignes et des colonnes une fois que celles-ci seront valables
   
    *ligne=ligne1;
    *colonne=colonne1;


}

void impact(char tableau[10][10], char grille[10][10], int ligne, int colonne, int * nbimpact, boat *Bateaux2,boat *Bateaux3_1,boat *Bateaux3,boat *Bateaux4,boat *Bateaux5) {

// Impact est la fonction qui gere comment un missile impactera la grille et les points de vie d'un bateau




    if (grille[colonne][ligne] != '_' && tableau[colonne][ligne] != 'X' && tableau[colonne][ligne] != 'O') {
        tableau[colonne][ligne] = 'X';
       // on modifie la valeur de la variable nbimpact pour que la fonction affichage appelee apres chaque tir puisse afficher le nombre de missile touchés, cette valeur sera
       // remise a 0 apres coup
        ++*nbimpact;




        fflush(stdin);

       //la fonction impact n'as un effet que si la case en question possede un bateau et si les points de vie de celui ci ne sont pas nuls
       //si les points de vie sont nul alors la case contenant le bateau sera consideree comme touchee
       
        if (grille[colonne][ligne] == '5' && Bateaux5->vie!=0 ) {
     Bateaux5->vie=Bateaux5->vie-1;
 
     if(Bateaux5->vie==0){
     Bateaux5->vie--;

        if(Bateaux5->vie==0){
           
           // Passer la taille du bateau a 0 permet a la fonction affichage de se rendre compte que le bateau a ete touche
           // cette valeur sera retournee a sa valeur d'origine apres coup
           
         Bateaux5->taille=0;
        }
     }


        } else if (grille[colonne][ligne] == '4' && Bateaux4->vie != 0) {
            Bateaux4->vie--;
            if (Bateaux4->vie == 0) {
                Bateaux4->taille=0;

            }

        } else if (grille[colonne][ligne] == '2' && Bateaux2->vie != 0) {
            Bateaux2->vie--;
            if (Bateaux2->vie == 0) {
                Bateaux2->taille=0;

            }
        } else if(grille[colonne][ligne] =='3' && Bateaux3->vie!=0){
            Bateaux3->vie--;
            if(Bateaux3->vie==0){
                Bateaux3->taille=0;

            }
        } else if(grille[colonne][ligne] =='1' && Bateaux3_1->vie!=0 ){
            Bateaux3_1->vie--;
            if(Bateaux3_1->vie==0){
                Bateaux3_1->taille=0;

            }
        }

    
// si la case en question n'as ni de bateaux et n'as pas déjà été touchée auparavant, alors elle prend la valeur 'O'
       
    } else if (tableau[colonne][ligne] != 'X' && tableau[colonne][ligne] != 'O') {
        tableau[colonne][ligne] = 'O';

    }






}


void bombe(char tableau[10][10], char grille[10][10], int ligne, int colonne, int* min1, int* min2, int* max1, int* max2){



// Les lignes suivantes vont restreindre la zone d'action de la fonction ipmpact afin qu'elle n'essaye pas d'atteindre des cases en dehors de la grille

    if (colonne==0){
        *min1 = 0;
    } else {
        *min1= colonne -1;
    }

    if (ligne==0){
        *min2=0;
    } else {
        *min2=ligne-1;
    }

    if (colonne==9){
        *max1=9;
    } else{
        *max1=colonne+1;
    }

    if (ligne==9){
        *max2=9;
    } else{
        *max2=ligne+1;
    }

    //on applique impact à toute les cases du perimetre (toutes les cases situee a un bloc du point d'impact renseigne au debut




}


void impacttact(char tableau[10][10], char grille[10][10], int ligne, int colonne, int * nbimpact, boat *Bateaux2,boat *Bateaux3_1,boat *Bateaux3,boat *Bateaux4,boat *Bateaux5){

   // cette fonction gere le comportement du missile tactique

int ligne1, colonne1;
// Impact est la fonction qui gere comment un missile impactera la grille et les points de vie d'un bateau

char bateau;
*nbimpact=0;

    if (grille[colonne][ligne] != '_' && tableau[colonne][ligne] != 'X' && tableau[colonne][ligne] != 'O') {
        tableau[colonne][ligne] = 'X';
       
       // le missile tactique ne compte que pour un seul impact
       
        *nbimpact=1;
        bateau=grille[colonne][ligne];
        printf("%c", bateau);

       //le missile reprend le principe du missile tactique mais contrairement à celui ci ne change le tableau que si les cases rencontrées ont la meme valeur que la case de depart
       // a condition que la case de depart contienne un bateau
       
       // applique impact sur toute la colonne
       
        for (int i = 0; i < 10; ++i) {
            if(grille[i][ligne]==bateau && tableau[i][ligne] != 'X' && tableau[i][ligne] != 'O'){
                tableau[i][ligne] = 'X';
            }
        }

        //applique impact sur toutes la ligne

        for (int i = 0; i < 10; ++i) {
            if(grille[colonne][i]==bateau && tableau[colonne][i] != 'X' && tableau[colonne][i] != 'O'){
                tableau[colonne][i] = 'X';
            }
        }


// j'ai essayé de faire des essais en faisant des soustractions ou avec un switch pour changer directement la valeur, apres le premier changment cela n'est plus possible
// on peut modifier chaque point de vie une fois suelement
        fflush(stdin);

        if (grille[colonne][ligne] == '5' && Bateaux5->vie != 0) {
            
           // le missile tactique coulant automatiquement un bateau, on a choisi de faire en sorte que les point de vie du bateau choisi atteignent directement 0
           
            Bateaux5->vie=0;
            if(Bateaux5->vie==0){
                Bateaux5->taille=0;
                printf("Bateau de taille 5 coule");
            }


        } else if (grille[colonne][ligne] == '4' && Bateaux4->vie != 0) {
            Bateaux4->vie=0;
            if (Bateaux4->vie == 0) {
                Bateaux4->taille=0;
                printf("Bateau de taille 4 coule");
            }

        } else if (grille[colonne][ligne] == '2' && Bateaux2->vie != 0) {
            Bateaux2->vie=0;
            if (Bateaux2->vie == 0) {
                Bateaux2->taille=0;
                printf("Bateau de taille 2 coule");
            }
           
        } else if(grille[colonne][ligne] =='3' && Bateaux3->vie!=0){
            Bateaux3->vie=0;
            if(Bateaux3->vie==0){
                Bateaux3->taille=0;
                printf("Bateau de taille 3 coule");
            }
           
        } else if(grille[colonne][ligne] =='1' && Bateaux3_1->vie!=0 ){
            Bateaux3_1->vie=0;
            if(Bateaux3_1->vie==0){
                Bateaux3_1->taille=0;
                printf("Bateau de taille 3 coule");
            }
        }

       // comme pour impact classique, si la case touchee au depart ne contenait pas de bateaux et n'avait pas été touchée on affiche 'O'

    } else if (tableau[colonne][ligne] != 'X' && tableau[colonne][ligne] != 'O') {
        tableau[colonne][ligne] = 'O';

    }




}






