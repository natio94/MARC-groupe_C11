//
// Created by nat.io on 14/11/2024.
//

#ifndef UNTITLED1_RANDOM_H
#define UNTITLED1_RANDOM_H
#include <stdlib.h>

/**
 * @brief Function to choose a random element from a list of (weighted) choices
 * @param choice : the list of choices
 * @param nb : the number of choices
 * @param optional : put 0 and the weights of the choices if you want a weighted random choice or nothing if you just want a random choice
 * @return the chosen element
 */
int choices(int choice[],int ,...);

/**
 * @brief Function to generate n movements
 * @param n : the number of movements to generate
 * @return the generated movements
 */
int* generateAllMovements(int n);

/**
 * @brief Function to generate a random movement
 * @param pool : the pool of movements you choose from and where you decrement the chosen movement
 * @return the generated movement
 */
int generateMovement(int pool[]);
#endif //UNTITLED1_RANDOM_H
