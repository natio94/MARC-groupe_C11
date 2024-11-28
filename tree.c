//
// Created by nat.io on 24/10/2024.
//

#include <malloc.h>
#include "tree.h"
#include "node.h"
#include "moves.h"

#define NB_NODES_MAX 10

tTree* createTree() {
    tTree* tree = (tTree*)malloc(sizeof(tTree));
    tree->root = NULL;
    return tree;
}


void removeTree(tTree* tree) {
    removeNode(tree->root);
    free(tree);
}

//
void printTree(tNode* node, int level) {
    if (node == NULL) return;
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("|-- value: %d, move: %s\n", node->value, getMoveAsString(node->move));

    for (int i = 0; i < node->nbNodes; i++) {
        printTree(node->nodes[i], level + 1);
    }
}

