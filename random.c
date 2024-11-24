//
// Created by nat.io on 14/11/2024.
//
#include "random.h"
#include <stdarg.h>
#include <time.h>
#include "stdio.h"


const char *MOVEMENT[] = {"+10", "+20", "+30", "-10", "left", "right", "U-turn"};

int choices(int choice[], int nb, ...) {
    va_list ap;
    va_start(ap, nb);
    int weighted = va_arg(ap, int);
    int *weights = va_arg(ap, int*);
    //srand(0);
    srand(time(NULL));
    if (!weighted) {
        printf("weighted\n");
        int sum = 0;
        for (int i = 0; i < nb; i++) {
            sum += weights[i];
        }
        int proba[sum];
        int pos = 0;
        for (int i = 0; i <nb; i++) {
            for (int j=0; j < weights[i]; j++) {
                //printf("pos %d ", pos);
                //printf("i %d ", i);
                proba[pos] = choice[i];
                pos++;
            }

        }
        int random_index = rand() % sum;
        va_end(ap);
        return proba[random_index];
    }
    int random_index = rand() % nb;

    return choice[random_index];
}

int generateMovement(int pool[]) {
    int length=7;
    int moves[]= {0,1,2,3,4,5,6};
    int moveChoosed = choices(moves, length, 0, pool);
    pool[moveChoosed]--;
    return moveChoosed;
}

int* generateAllMovements(int n) {
    int pool[] = {22, 15, 7, 7, 21, 21, 7};
    int *moves = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        moves[i] = generateMovement(&pool);
    }

    return moves;
}