//
// Created by nat.io on 24/10/2024.
//


#include "tree.h"



tTree* createTree(){
    tTree* tree= (tTree*)malloc(sizeof(tTree));
    tree->root = NULL;
    return tree;
}





void removeTree(tTree* tree){
    removeNode(tree->root);
}