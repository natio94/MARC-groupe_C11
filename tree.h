//
// Created by nat.io on 24/10/2024.
//

#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H
#include "stdio.h"
#include <malloc.h>
#include "node.h"




/**
 * @brief La structure d'un arbre
 */
typedef struct sTree{
    tNode* root;
}tTree;



/**
 * @brief Fonction pour creer un arbre
 * @return l'arbre cree
 */
tTree* createTree();





/**
 * @brief Fonction pour supprimer un arbre
 * @param tree : l'arbre a supprimer
 * @return none
 */
void removeTree(tTree*);

#endif //UNTITLED1_TREE_H
