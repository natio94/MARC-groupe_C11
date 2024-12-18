//
// Created by flasque on 19/10/2024.
//

#ifndef UNTITLED1_MOVES_H
#define UNTITLED1_MOVES_H


#include <stdio.h>
#include <stdlib.h>
#include "loc.h"
#include "node.h"
#include "random.h"
#include "tree.h"
#include "stack.h"

/**
 * @brief Enum for the possible moves of the robot
 */
typedef enum e_move
{
    F_10, // Forward 10 m
    F_20, // Forward 20 m
    F_30, // Forward 30 m
    B_10, // Backward 10 m
    T_LEFT, // Turn left (+90°)
    T_RIGHT, // Turn right (-90°)
    U_TURN
} t_move;



/**
 * @brief Array of strings for the possible moves of the robot
 */
static char _moves[8][8] = {"F 10m", "F 20m", "F 30m", "B 10m", "T left", "T right", "U-turn"};



typedef struct s_max
{
 int value;
 t_move* chemin;
} t_max;

/**
 * @brief function to get a t_move as a string
 * @param move : the move to convert
 * @return the string corresponding to the move
 */
char *getMoveAsString(t_move move);

/**
 * @brief function to update the localisation of the robot according to a move
 * @param loc : the localisation of the robot
 * @param move : the move to do
 * @return the new localisation of the robot
 */
t_localisation move(t_localisation, t_move);

/**
 * @brief wrapper function to update a single location
 * @param p_loc : the pointer to the localisation of the robot
 * @param move : the move to do
 * @return none
 */
void updateLocalisation(t_localisation *, t_move);


void phaseUpdateLocalisation(t_localisation *p_loc, t_move *m);

/**
 * @brief function to check if the robot is moving on a crevasse
 * @param loc : the localisation of the robot
 * @param map : the map
 * @param move : the move to do
 * @return 1 if the robot is moving on a crevasse, 0 otherwise
 */
int isMovingOnCrevasse(t_localisation loc, t_map map, t_move move);



/**
 * @brief function to calculate the cose of a localisation
 * @param loc : the localisation used
 * @param map : the map
 * @return
 */
int rentamove(t_localisation, t_map);



/**
 * @brief function to get the best moves for the robot
 * @param loc : the localisation of the robot
 * @param map : the map
 * @return
 */
t_move *bestMove(t_localisation, t_map);

/**
 * @brief function to launch the game
 * @param x : the x position of the robot
 * @param y : the y position of the robot
 * @param ori : the orientation of the robot
 * @param map : the map
 * @return none
 */
void play(int, int, t_orientation, char*);

int totalmoves(t_move*, int, t_localisation, t_map);

void createMoveNode(tNode*, t_map,t_move*, int, t_localisation);

t_localisation finalLocal(t_move* tab, int size, t_localisation local);

t_move * bestPath(tTree tree);
tNode * minNodes(tNode* node, t_stack* stack);

tTree createMoveTree(t_map map, t_localisation local);

void displayMove(t_move* move, int size);
#endif //UNTITLED1_MOVES_H
