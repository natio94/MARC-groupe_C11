//
// Created by nat.io on 24/10/2024.
//

#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H
#include "stdio.h"
#define TAILLE_ARBRE 9
typedef struct sNode{
    struct sNode* nodes[TAILLE_ARBRE];
    int value;
    int nbNodes;
}tNode;

typedef struct sTree{
    tNode* root;
}tTree;

tNode* createNode(int);

tTree* createTree(int);

#endif //UNTITLED1_TREE_H
