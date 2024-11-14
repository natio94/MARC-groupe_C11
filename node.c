//
// Created by nat.io on 14/11/2024.
//

#include "node.h"
tNode* createNode(int value,int nbNode,int depth){
    tNode* node;
    node = (tNode*)malloc(sizeof(tNode));
    node->value = value;
    node->nbNodes = nbNode;
    for (int i = 0; i < nbNode; i++)
    {
        node->nodes[i] = NULL;
    }
    return node;
}
void addNode(tNode* tree, int value,int nbNode){
    if (tree->nbNodes < NB_NODES_MAX) {
        tNode* newTree = createNode(value,nbNode,tree->depth+1);
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