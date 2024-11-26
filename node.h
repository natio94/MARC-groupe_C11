//
// Created by nat.io on 14/11/2024.
//

#ifndef UNTITLED1_NODE_H
#define UNTITLED1_NODE_H
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "loc.h"


#define NB_NODES_MAX 9
typedef struct sNode{
    struct sNode* nodes[NB_NODES_MAX];
    int depth;
    int value;
    int nbNodes;
    int move;
}tNode;



typedef struct {
 tNode* root;
} tTree;



/**
 * @brief Fonction pour creer un noeud
 * @param value : la valeur du noeud
 * @return le noeud cree
 */
tNode* createNode(int,int,int);

/**
 * @brief Fonction pour ajouter un noeud a un arbre
 * @param tree : l'arbre
 * @param value : la valeur du noeud a ajouter
 * @return none
 */
void addNode(tNode*, int,int);

/**
 * @brief Fonction pour verifier si un noeud est une feuille
 * @param node : le noeud a verifier
 * @return 1 si le noeud est une feuille, 0 sinon
 */
int isLeaf(tNode*);

/**
 * @brief Fonction pour supprimer un noeud
 * @param node : le noeud a supprimer
 * @return none
 */
void removeNode(tNode*);

#endif //UNTITLED1_NODE_H
