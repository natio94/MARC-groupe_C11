//
// Created by nat.io on 14/11/2024.
//

#include "random.h"
#include <stdarg.h>
#include <time.h>
#include "stdio.h"
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
        for (int i = 0; i <=nb; i++) {
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
    printf("not weighted\n");
    int random_index = rand() % nb;

    return choice[random_index];
}