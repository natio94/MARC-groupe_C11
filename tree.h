//
// Created by nat.io on 24/10/2024.
//

#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H
#include "stdio.h"
#define TAILLE_ARBRE 9

/**
 * @brief La structure d'un noeud
 */
typedef struct sNode{
    struct sNode* nodes[TAILLE_ARBRE];
    int value;
    int nbNodes;
}tNode;

/**
 * @brief La structure d'un arbre
 */
typedef struct sTree{
    tNode* root;
}tTree;

/**
 * @brief Fonction pour creer un noeud
 * @param value : la valeur du noeud
 * @return le noeud cree
 */
tNode* createNode(int);

/**
 * @brief Fonction pour creer un arbre
 * @return l'arbre cree
 */
tTree* createTree();

/**
 * @brief Fonction pour ajouter un noeud a un arbre
 * @param tree : l'arbre
 * @param value : la valeur du noeud a ajouter
 * @return none
 */
void addNode(tNode*, int );

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

/**
 * @brief Fonction pour supprimer un arbre
 * @param tree : l'arbre a supprimer
 * @return none
 */
void removeTree(tTree*);

#endif //UNTITLED1_TREE_H
