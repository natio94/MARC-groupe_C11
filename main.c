#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "node.h"
#include "random.h"
#include "loc.h"
#include "moves.h"
#include "map.h"

t_move *bestMove();

void test(tNode* node, int level) {
    if (node == NULL) return;

    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    printf("|-- value: %d, move: %s\n", node->value, getMoveAsString(node->move));

    for (int i = 0; i < node->nbNodes; i++) {
        test(node->nodes[i], level + 1);
    }
}

int main() {

//    tNode* root = createNode(0, 9, 0,-1);
    //t_move tab[F_10];




    t_localisation local = {0, 0, SOUTH};
    t_map map = createMapFromFile("..\\maps\\example1.map");

    displayMap(map);
    printf("\n");
    displayCosts(map);
    //t_move* move = bestMove(local, map);
//    t_move moves[]={F_20, F_20, T_LEFT, T_RIGHT, F_20};
//    printf("%d", totalmoves( moves, 5, local, map));
//    printf("x %d y %d\n", finalLocal(moves, 5, local).pos.x, finalLocal(moves, 5, local).pos.y);
//    printf("%d",map.costs[finalLocal(moves, 5, local).pos.y][finalLocal(moves, 5, local).pos.x]);
    //t_move tab[] = {F_10, F_20, F_30, B_10, T_LEFT, T_RIGHT, U_TURN};
//    avancer de 10, tourner gauche, avancer de 20, tourner droite, demis tour,
//    t_move moves[] = {F_20, F_20, B_10, T_LEFT, T_RIGHT, F_10, F_30, U_TURN, B_10};
//    createMoveNode(root, map, moves, 9, local);
    //printTree(root, 0);
//    printf("\na%d\n",findMinLeafValue(root));
//    t_stack stack =createStack(5);
//    minNodes(root, &stack);
//    for (int i = 0; i < stack.nbElts; i++) {
//        printf("%s\n", getMoveAsString(stack.values[i]));
//    }


    play(0, 0, SOUTH, "..\\maps\\example1.map");








    return 0;

}

