#include <stdio.h>
#include <stdlib.h>
#include "tree.h"  // Inclure le fichier d'en-tête pour la définition des structures

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "random.h"
// #include "loc.h"
// #include "moves.h"

int main() {

    tNode* root = createNode(0, 5, 0);

    for (int i = 0; i < 9; i++) {
        addNode(root, i + 1, 8);
        for (int j = 0; j < 8; j++) {
            addNode(root->nodes[i], (i * 8 + j) + 1, 7);
            for (int k = 0; k < 7 ; k++){
                addNode(root->nodes[i]->nodes[j], (i * 7 + j) + 1, 6);
                for (int l = 0; l < 6 ; l++){
                    addNode(root->nodes[i]->nodes[j]->nodes[k], (i * 6 + j) + 1, 5);
                    for (int m = 0; m < 5 ; m++){
                        addNode(root->nodes[i]->nodes[j]->nodes[k]->nodes[l], (i * 5 + j) + 1, 4);
                        for (int n = 0; n < 4 ; n++){
                            addNode(root->nodes[i]->nodes[j]->nodes[k]->nodes[l]->nodes[m], (i * 4 + j) + 1, 1);
                        }
                    }
                }
            }
        }
    }



            // printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
            // for (int i = 0; i < map.y_max; i++)
            // {
            //     for (int j = 0; j < map.x_max; j++)
            //     {
            //         printf("%d ", map.soils[i][j]);
            //     }
            // }

    //         for (int i = 0; i < 5; i++) {
    //             for (int j = 0; j < 4; j++) {
    //                 for (int k = 0; k < 3; k++) {
    //                     addNode(root->nodes[i]->nodes[j], (i * 4 * 3 + j * 3 + k) + 1, 2);
    //                 }
    //             }
    //         }
    //     }
    // }
    printTree(root, 0);

    return 0;

}