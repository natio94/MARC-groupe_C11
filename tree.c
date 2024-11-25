//
// Created by nat.io on 24/10/2024.
//

#include <malloc.h>
#include "tree.h"
#include "node.h"

#define NB_NODES_MAX 10

tTree* createTree() {
    tTree* tree = (tTree*)malloc(sizeof(tTree));
    tree->root = NULL;
    return tree;
}

void addRootNode(tTree* tree, int value, int nbNode) {
    if (tree->root == NULL) {
        tree->root = createNode(value, nbNode, 0);
    } else {
        printf("La racine existe déjà.\n");
    }
}

void removeTree(tTree* tree) {
    removeNode(tree->root);
    free(tree);
}

void printTree(tNode* node, int level) {
    if (node == NULL) return;
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    if (level > 0) {
        printf("- ");
    }
    printf("Valeur du noeud: %d\n", node->value);
    for (int i = 0; i < node->nbNodes; i++) {
        printTree(node->nodes[i], level + 1);
    }
}