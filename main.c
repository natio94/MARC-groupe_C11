#include <stdio.h>
#include <stdlib.h>
#include "tree.h"  // Inclure le fichier d'en-tête pour la définition des structures

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "random.h"
#include "loc.h"
#include "moves.h"

int main() {

    tNode* root = createNode(0, 5, 0);

    for (int i = 0; i < 5; i++) {
        addNode(root, i + 1, 4);
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            addNode(root->nodes[i], (i * 4 + j) + 1, 3);

    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.soils[i][j]);
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                addNode(root->nodes[i]->nodes[j], (i * 4 * 3 + j * 3 + k) + 1, 2);
            }
        }
    }

    printTree(root, 0);
    displayMap(map);




    return 0;
}