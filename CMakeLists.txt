cmake_minimum_required(VERSION 3.19)
project(Projetbataillenavale C)

set(CMAKE_C_STANDARD 99)

add_executable(Projetbataillenavale main.c grille.c grille.h bateaux.c bateaux.h fonctions_supplementaires.c fonctions_supplementaires.h inventaire.c inventaire.h missile.c missile.h sauvegarde.c sauvegarde.h)