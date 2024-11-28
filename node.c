//
// Created by nat.io on 14/11/2024.
//

#include "node.h"

tNode* createNode(int value, int nbNode, int depth,int move) {
    tNode* node = (tNode*)malloc(sizeof(tNode));
    node->value = value;
    node->nbNodes = 0;
    node->depth = depth;
    node->move = move;
    for (int i = 0; i < nbNode; i++) {
        node->nodes[i] = NULL;
    }
    return node;
}

void addNode(tNode* node, int value, int nbNode,int move) {
    if (node->nbNodes < NB_NODES_MAX) {
        tNode* newNode = createNode(value, nbNode, node->depth + 1, move);
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
int findMinLeafValue(tNode* node) {
    if (node == NULL) {
        return INT_MAX; // Return a large value if the node is NULL
    }

    if (isLeaf(node)) {
        return node->value; // Return the value if the node is a leaf
    }

    int minValue = INT_MAX;
    for (int i = 0; i < node->nbNodes; i++) {
        int childMinValue = findMinLeafValue(node->nodes[i]);
        if (childMinValue < minValue) {
            minValue = childMinValue;
        }
    }

    return minValue;
}