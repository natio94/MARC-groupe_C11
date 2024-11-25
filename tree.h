//
// Created by nat.io on 24/10/2024.
//

#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H
#include "stdio.h"
#include <malloc.h>
#include "node.h"

tTree* createTree();

void removeTree(tTree*);

void printTree(tNode* node, int level);

void addRootNode(tTree*, int, int);

#endif //UNTITLED1_TREE_H
