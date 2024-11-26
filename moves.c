 //
 // Created by flasque on 19/10/2024.
 //


 #include "moves.h"
#include "tree.h"


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
         printf("penis");
     }
     return (map.soils[robot_pos.x][robot_pos.y] == BASE_STATION);
 }

int rentamove(t_localisation local, t_map map) {
        return map.costs[local.pos.x][local.pos.y];
     }


int totalmoves(t_move* tab, int size, t_localisation local, t_map map) {
     t_localisation fake_local = local;
     for (int i = 0; i < size; i++) {
         fake_local = translate(fake_local, tab[i]);
     }
     return rentamove(fake_local, map);
 }

t_move* newtab(t_move* tab, int size, int nope) {
     t_move* newtab=malloc((size-1)*sizeof(t_move));
     for (int i = 0; i < size-1; i++) {
         if (i!=nope) {
             newtab[i] = tab[i];
         }
     }
     return newtab;
 }


void totalchoice(tNode* node, t_move* tab, t_move* chemin, int size, int firstsize, t_localisation local, t_map map, t_max* max) {
             if (size >= 5) {
             for (int i = 0; i < size-1; i++) {
                 node->move = tab[i];
                 addNode(node, totalmoves(tab, size, local, map), size-1);
                 chemin[size-firstsize] = tab[i];
             totalchoice(node->nodes[i], newtab(tab, size, i), chemin, size-1, size, local, map, max);
         }
     }
     else {
     if (max->value>=totalmoves(tab,size,local,map)) {
         max->chemin = chemin;
     }
     }
 }

 t_move *bestMove(t_localisation local, t_map map){
     tTree* tree = createTree();
     t_position robot_pos = local.pos;
     tree->root=createNode(map.costs[robot_pos.x][robot_pos.y],9,0);
     int *movesPoolInt=generateAllMovements(9);
     t_move *movesPool=malloc(9*sizeof(t_move));
        for (int i = 0; i < 9; i++) {
            movesPool[i]=intToMove(movesPoolInt[i]);
        }
     t_move *chemin=malloc(5*sizeof(t_move));
     t_max* max= malloc(sizeof(t_max));
     max->value=1000*map.x_max*map.y_max;
     max->chemin=malloc(5*sizeof(t_move));
     totalchoice(tree->root,movesPool,chemin ,9,9,local,map,max);
     return max->chemin;
 }


 void play(int x, int y, t_orientation ori, char *filename) {
     t_localisation robotLocation = loc_init(x, y, ori);
     t_map map = createMapFromFile(filename);
     t_position robotPos = robotLocation.pos;
     while (isValidLocalisation(robotPos, map.x_max, map.y_max) && !testArriveeSurBaseStation(robotPos, map) && !isCrevasse(robotPos, map)) {
        t_move* best= bestMove(robotLocation, map);
         for (int i = 0; i < 5; ++i) {
                updateLocalisation(&robotLocation, best[i]);
                robotPos = robotLocation.pos;
                if (!isValidLocalisation(robotPos, map.x_max, map.y_max) || testArriveeSurBaseStation(robotPos, map) || isCrevasse(robotPos, map)) {
                    break;
                }

         }

     }
 }
