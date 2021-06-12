#include <stdio.h>
#include "grille.h"
#include <stdlib.h>
#include <time.h>
#include"grille.h"
#include"fonctions_supplementaires.h"
#include "bateaux.h"
#include "inventaire.h"
#include"missile.h"
#include "sauvegarde.h"
int main() {

    int colonne;
    int ligne;
int nbimpact=0;

    int min1, min2;
    int max1, max2;

    char grille[10][10]={0};
    char tableau[10][10];
    char level;
    char mode = 0;


    int visible=0;
    inventaire NB_missile;
    boat Bateaux2;
    boat Bateaux3;
    boat Bateaux3_1;
    boat Bateaux4;
    boat Bateaux5;

    char action;

    int choix_enregister_ou_charger;

    int completion=0;
int invvide=0;
    char type_missile ;
    char difficulte = 0;
    int active=0;


// faire une fonction affichage pour chaque fin de programme





    //affiche menu princial+choix sur modes//
    level=debut_partie_choixlevel();


    if(level=='Q'){
        printf("fin du programme\n");
        return 0;

    } else if(level=='F' || level=='M'|| level=='D'){


        // initialise les deux grille avec des ______
        initgrille(grille, tableau);


        //genere les bateaux dans la grille

        genere_bateau(grille,&Bateaux2,&Bateaux3_1,&Bateaux3,&Bateaux4,&Bateaux5);
        /*
        printf("voici un petit test\n");
        deplacement_bateaux(grille,&Bateaux2,&Bateaux3_1,&Bateaux3,&Bateaux4,&Bateaux5);
        affiche_grille(grille);
*/
        mode=debut_partie_choixmode();


        //initialise le nb de munitions en fonction de ce qu'a choisit l'utilisateur

        munitions(level, &NB_missile );

    } else if(level=='C'){

        charger(grille,tableau,&NB_missile,&Bateaux5,&Bateaux4,&Bateaux3,&Bateaux3_1,&Bateaux2, &mode);

    }

    // modifie les valeurs des variables activant les effets des différents mode de jeu
    if (mode=='B'){
       visible=1;
    }


    if (mode=='A'){
        active=1;
    }


    //affiche la grille vierge et les regles en début de partie
    grilleutilisateur(tableau);
    regles();


    //affiche grille avec les bateaux, pratique pour vérifier que le code marche
    affiche_grille(grille);




    do {

        //demande l'action à faire et la retourne pour que la varialbe action prenne le charactere retourné par la fonction
        action=demande();
        if(action=='J'){

            //demande type de missile et le retourne, type_missile prend le charactere retourné par la fonction

            type_missile=choix_type_missile(&NB_missile, tableau, grille, &Bateaux2, &Bateaux3_1, &Bateaux3, &Bateaux4, &Bateaux5, visible);

            //verifie que les coordonnees rentrees sont comprises entre 0 et 9, modifie directement la valeur de ligne et colonne

            verif(tableau, grille, &ligne, &colonne);


            if (type_missile == 'C' && NB_missile.simple != 0) {

            //fonction de missile classqiue

                impact(tableau, grille, ligne, colonne, &nbimpact, &Bateaux2, &Bateaux3_1, &Bateaux3, &Bateaux4, &Bateaux5);

            //affiche les deux grilles et le nombre de bateau touchés ainsi que le message d'annonce si
            //un bateau à été coulé

                affichecoup(tableau, grille, visible, &nbimpact, &Bateaux2, &Bateaux3_1, &Bateaux3, &Bateaux4, &Bateaux5);



            } else if (type_missile == 'B' && NB_missile.bombe != 0) {

            //fonction de missile bombe

                bombe(tableau, grille, ligne, colonne, &nbimpact, &Bateaux2, &Bateaux3_1, &Bateaux3, &Bateaux4, &Bateaux5);


                affichecoup(tableau, grille, visible, &nbimpact, &Bateaux2, &Bateaux3_1, &Bateaux3, &Bateaux4, &Bateaux5);






            } else if (type_missile == 'A' && NB_missile.artillerie != 0) {

            //fonction de missile artillerie

                impact_artillerie(tableau, grille, ligne, colonne, &nbimpact, &Bateaux2, &Bateaux3_1, &Bateaux3, &Bateaux4, &Bateaux5);

                affichecoup(tableau, grille, visible, &nbimpact, &Bateaux2, &Bateaux3_1, &Bateaux3, &Bateaux4, &Bateaux5);



            } else if (type_missile == 'T' && NB_missile.tactique != 0) {

            // fonction de missile tactique

                impacttact(tableau, grille, ligne, colonne, &nbimpact, &Bateaux2, &Bateaux3_1, &Bateaux3, &Bateaux4, &Bateaux5);

                affichecoup(tableau, grille, visible, &nbimpact, &Bateaux2, &Bateaux3_1, &Bateaux3, &Bateaux4, &Bateaux5);

            }

           if(active==1){
                        deplacement_bateaux(grille,&Bateaux2,&Bateaux3_1,&Bateaux3,&Bateaux4,&Bateaux5);
                       }
            //on met les fonctions affiche grille (contenant les positions des bateaux) en commentaire afin de pouvoir
            //rapidement les remttre en place lorsque l'on veut s'assurer du bon fonctionnement du programme
            //affiche_grille(grille);


            // vérifie si les conditions pour une victoire ou une défaite sont remplies

            condition(&completion, &invvide, NB_missile, Bateaux2,Bateaux3_1,Bateaux3,Bateaux4,Bateaux5 );



        } else {


            enregistrer(tableau,grille,&NB_missile,&Bateaux5,&Bateaux4,&Bateaux3,&Bateaux3_1,&Bateaux2, &mode);
           // affiche_grille(grille);
            printf("\n");
            printf("Fin du programme");
            return 0;
        }


    } while (invvide==0 && completion==0);



    return 0;
}
