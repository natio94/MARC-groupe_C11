//
// Created by nat.io on 24/10/2024.
//

#include <malloc.h>
#include "tree.h"

tNode* createNode(int value){
    tNode* node;
    node = (tNode*)malloc(sizeof(tNode));
    node->value = value;
    node->nbNodes = 0;
    for (int i = 0; i < 9; i++)
    {
        node->nodes[i] = NULL;
    }
    return node;
}

tTree* createTree(int value){
    tTree* tree= (tTree*)malloc(sizeof(tTree));
    tree->root = createNode(value);
    return tree;
}

void addNode(tNode* tree, int value){
    if (tree->nbNodes < TAILLE_ARBRE) {
        tNode* newTree = createNode(value);
        tree->nodes[tree->nbNodes] = newTree;
        tree->nbNodes++;
    }
}

int isLeaf(tNode* node){
    return node->nbNodes==0;
}

void removeNode(tNode* node){
    if (node==NULL){
        return;
    }
    for(int i=0; i<node->nbNodes; i++){
        removeNode(node->nodes[i]);
    }
}

void removeTree(tTree* tree){
    removeNode(tree->root);
}