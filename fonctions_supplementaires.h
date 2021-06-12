//
// Created by simon on 19/05/2021.
//
#include"bateaux.h"
#include "inventaire.h"
#ifndef PROJETBATAILLENAVALE_FONCTIONS_SUPPLEMENTAIRES_H
#define PROJETBATAILLENAVALE_FONCTIONS_SUPPLEMENTAIRES_H


    char debut_partie_choixlevel();

    char debut_partie_choixmode();

    int verifi_poitionboat(char grille[10][10],int taille);

char choixdiff();

char demande();

void condition(int* completion, int * invvide, inventaire NB_missile, boat Bateaux2, boat Bateaux3_1, boat Bateaux3, boat Bateaux4, boat Bateaux5);

#endif //PROJETBATAILLENAVALE_FONCTIONS_SUPPLEMENTAIRES_H
