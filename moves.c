 //
 // Created by flasque on 19/10/2024.
 //


 #include "moves.h"


 /* prototypes of local functions */
 /* local functions are used only in this file, as helper functions */

 /**
  * @brief Function to rotate the robot according to a move and its actual orientation
  * @param ori : the actual orientation of the robot
  * @param move : the move to do
  * @return the new orientation of the robot
  */
 t_orientation rotate(t_orientation, t_move );

 /**
  * @brief function to translate the robot according to a move and its actual position
  * @param loc : the actual localisation of the robot
  * @param move : the move to do
  * @return the new localisation of the robot
  */
 t_localisation translate(t_localisation , t_move);

 t_move intToMove(int move){
        switch (move)
        {
            case 0:
                return F_10;
            case 1:
                return F_20;
            case 2:
                return F_30;
            case 3:
                return B_10;
            case 4:
                return T_LEFT;
            case 5:
                return T_RIGHT;
            case 6:
                return U_TURN;

        }
    }

    int moveToInt(t_move move){
        switch (move)
        {
            case F_10:
                return 0;
            case F_20:
                return 1;
            case F_30:
                return 2;
            case B_10:
                return 3;
            case T_LEFT:
                return 4;
            case T_RIGHT:
                return 5;
            case U_TURN:
                return 6;
        }
 }

 /* definition of local functions */

 t_orientation rotate(t_orientation ori, t_move move)
 {
     int rst=0;
     switch (move)
     {
         case T_LEFT:
             rst=3;
             break;
         case T_RIGHT:
             rst=1;
             break;
         case U_TURN:
             rst=2;
             break;
         default: // should not happen
             rst=0;
             break;
     }
     return (ori+rst)%4;
 }

 t_localisation translate(t_localisation loc, t_move move)
 {
     /** rules for coordinates:
      *  - x grows to the right with step of +1
      *  - y grows to the bottom with step of +1
      *  - the origin (x=0, y=0) is at the top left corner
      */
     t_position res=loc.pos;
     switch (move) {
         case F_10:
             switch (loc.ori) {
                 case NORTH:
                     res.y = loc.pos.y - 1;
                     break;
                 case EAST:
                     res.x = loc.pos.x + 1;
                     break;
                 case SOUTH:
                     res.y = loc.pos.y + 1;
                     break;
                 case WEST:
                     res.x = loc.pos.x - 1;
                     break;
                 default:
                     break;
             }
             break;
         case F_20:
             switch (loc.ori) {
                 case NORTH:
                     res.y = loc.pos.y - 2;
                     break;
                 case EAST:
                     res.x = loc.pos.x + 2;
                     break;
                 case SOUTH:
                     res.y = loc.pos.y + 2;
                     break;
                 case WEST:
                     res.x = loc.pos.x - 2;
                     break;
                 default:
                     break;
             }
             break;
         case F_30:
             switch (loc.ori) {
                 case NORTH:
                     res.y = loc.pos.y - 3;
                     break;
                 case EAST:
                     res.x = loc.pos.x + 3;
                     break;
                 case SOUTH:
                     res.y = loc.pos.y + 3;
                     break;
                 case WEST:
                     res.x = loc.pos.x - 3;
                     break;
                 default:
                     break;
             }
             break;
         case B_10:
             switch (loc.ori) {
                 case NORTH:
                     res.y = loc.pos.y + 1;
                     break;
                 case EAST:
                     res.x = loc.pos.x - 1;
                     break;
                 case SOUTH:
                     res.y = loc.pos.y - 1;
                     break;
                 case WEST:
                     res.x = loc.pos.x + 1;
                     break;
                 default:
                     break;
             }
             break;
         default:
             break;
     }
         return loc_init(res.x, res.y, loc.ori);

 }

 /* definitions of exported functions */

 char *getMoveAsString(t_move move)
 {
     return _moves[move];
 }

 t_localisation move(t_localisation loc, t_move move)
 {
     t_localisation new_loc=loc;
     if ((move >=T_LEFT) && (move <= U_TURN))
     {
         new_loc.ori = rotate(loc.ori, move);
     }
     else
     {
         new_loc = translate(loc, move);
     }

     return new_loc;
 }

 void updateLocalisation(t_localisation *p_loc, t_move m)
 {
     *p_loc = move(*p_loc, m);
     return;
 }

 void phaseUpdateLocalisation(t_localisation *p_loc, t_move *m)
 {
     for (int i=0; i<5; i++) {
         updateLocalisation(p_loc, m[i]);
     }
     return;
 }

 t_move *getRandomMoves(int N)
 {
     int nbmoves[]={22,15,7,7,21,21,7};
     int total_moves=100;
     t_move *moves = (t_move *)malloc(N * sizeof(t_move));
     for (int i = 0; i < N; i++)
     {
         int r = rand() % total_moves;
         int type=0;
         while (r >= nbmoves[type])
         {
             r -= nbmoves[type];
             type++;
         }
         nbmoves[type]--;
         total_moves--;
         moves[i] = (t_move )type;
     }
     return moves;
 }
 int isMovingOnCrevasse(t_localisation loc, t_map map, t_move nextMove){
     t_localisation new_loc = move(loc, nextMove);
     if (!isValidLocalisation(new_loc.pos, map.x_max, map.y_max))
     {
         printf("Invalid position\n");
         return 1;
     }
     int crevasse=isCrevasse(new_loc.pos, map);
     if (nextMove== F_20){
         crevasse=crevasse || isCrevasse(move(loc, F_10).pos, map);
     }
     else if (nextMove== F_30){
         crevasse=crevasse || isCrevasse(move(loc, F_10).pos, map) || isCrevasse(move(loc, F_20).pos, map);
     }
     return crevasse;
 }

 int testArriveeSurBaseStation(t_position robot_pos, t_map map)
 {
     if (map.soils[robot_pos.x][robot_pos.y] == BASE_STATION){
         printf("fini");
     }
     return (map.soils[robot_pos.x][robot_pos.y] == BASE_STATION);
 }

int rentamove(t_localisation local, t_map map) {
    //displayCosts(map);
    //printf("\n");
        if (!isValidLocalisation(local.pos, map.x_max, map.y_max))
        {
            return 1000*map.x_max*map.y_max;
        }
        return map.costs[local.pos.y][local.pos.x];
     }
void displayMove(t_move* move, int size){
    for (int i = 0; i <size; i++) {
        printf("%s\n", getMoveAsString(move[i]));
    }  }

int totalmoves(t_move* tab, int size, t_localisation local, t_map map) {
     return rentamove(finalLocal(tab,size,local), map);
 }

 t_localisation finalLocal(t_move* tab, int size, t_localisation local){
        t_localisation fake_local = local;
     for (int i = 0; i < size; i++) {
         fake_local = translate(fake_local, tab[i]);
     }
        return fake_local;
 }


 t_move* newtab(t_move* array, int size, int index) {
     if (index < 0 || index >= size) {
         return array; // Index out of bounds, return the original array
     }

     t_move* newArray = (t_move*)malloc((size - 1) * sizeof(t_move));
     if (newArray == NULL) {
         return array; // Memory allocation failed, return the original array
     }

     for (int i = 0, j = 0; i < size; i++) {
         if (i != index) {
             newArray[j++] = array[i];
         }
     }

     //free(array); // Free the old array
     return newArray;
 }


 void createMoveNode(tNode* node,t_map map,t_move* tab, int size, t_localisation local){

     int total = totalmoves(tab, size, local, map);
     if (size >= 5) {
         if (total<1000) {
             for (int i = 0; i < size-1; i++) {t_move* newTab = newtab(tab, size, i);
                 t_move move=tab[i];
                 addNode(node, node->value + rentamove(translate(local,move), map), size - 1, moveToInt(move));
                 createMoveNode(node->nodes[i], map, newTab, size - 1, translate(local,move));
                 free(newTab);
             }
         }
     }
 }




 tNode* minNodes(tNode* node, t_stack *stack) {
    if (node == NULL || node->nbNodes == 0) {
        return node;
    }
    tNode* minNode = node->nodes[0];
    for (int i = 0; i < node->nbNodes; i++) {
        if (node->nodes[i]->value < minNode->value) {
            minNode = node->nodes[i];
        }
    }
     printf("%d\n",minNode->value);
    push(stack, minNode->move);
    return minNodes(minNode, stack);
}

tTree createMoveTree(t_map map, t_localisation local){
    tTree tree;
    tree.root = createNode(0, 9, 0,-1);
    t_move* moves = generateAllMovements(9);
    createMoveNode(tree.root, map, moves, 9, local);
    return tree;
 }

    t_move * bestPath(tTree tree){
        t_stack stack =createStack(5);
        minNodes(tree.root, &stack);
        t_move* best = (t_move*)malloc(5*sizeof(t_move));
        for (int i = 0; i < stack.nbElts; i++) {
            best[i] = pop(&stack);
        }
        return best;
    }









// void play(int x, int y, t_orientation ori, char *filename) {
//
//
// }

 void play(int x, int y, t_orientation ori, char *filename) {
     // Initialisation de la localisation et de la carte
     t_localisation local = loc_init(x, y, ori);
     t_map map = createMapFromFile(filename);

     // Affichage initial de la carte et des coûts
     printf("Initial Map:\n");
     displayMap(map);
     printf("\nCosts:\n");
     displayCosts(map);

     // Création de l'arbre des mouvements
     tTree moveTree = createMoveTree(map, local);

     // Récupération du chemin optimal
     t_move *bestMoves = bestPath(moveTree);

     // Affichage des mouvements choisis
     printf("\nOptimal moves:\n");
     //displayMove(bestMoves, 5);

     // Mise à jour de la localisation du robot
     printf("\nRobot movement:\n");
     for (int i = 0; i < 5; i++) {
         printf("Executing move: %s\n", getMoveAsString(bestMoves[i]));
         updateLocalisation(&local, bestMoves[i]);
         printf("New position: x=%d, y=%d, orientation=%d\n",
                local.pos.x, local.pos.y, local.ori);

         if (!isValidLocalisation(local.pos, map.x_max, map.y_max)) {
             printf("Invalid position. Stopping.\n");
             break;
         }

         // Vérification des crevasses et des limites
         if (isMovingOnCrevasse(local, map, bestMoves[i])) {
             printf("Danger! Moving into a crevasse. Stopping.\n");
             break;
         }

         // Vérification de la station de base
         if (testArriveeSurBaseStation(local.pos, map)) {
             printf("Success! Robot has reached the base station.\n");
             break;
         }
     }

     // Libération de la mémoire
     free(bestMoves);


     printf("\nPlay session complete.\n");
 }

