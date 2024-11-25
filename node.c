//
// Created by nat.io on 14/11/2024.
//

#include "node.h"

tNode* createNode(int value, int nbNode, int depth) {
    tNode* node = (tNode*)malloc(sizeof(tNode));
    node->value = value;
    node->nbNodes = 0;
    for (int i = 0; i < nbNode; i++) {
        node->nodes[i] = NULL;
    }
    return node;
}

void addNode(tNode* node, int value, int nbNode) {
    if (node->nbNodes < NB_NODES_MAX) {
        tNode* newNode = createNode(value, nbNode, node->nbNodes + 1);
        node->nodes[node->nbNodes] = newNode;
        node->nbNodes++;
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