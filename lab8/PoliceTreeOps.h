#include "PoliceTree.h"

#include <stdio.h>
#include <stdlib.h>
/** insertByPoliceId - this function inserts an entry <id, amount> into the police tree 
 * 					   ordered by police id.
 *                     If the PoliceId id is alread found in the tree, then this function
 *                     updates the total amount to be stored against him. it rturns the 
 *                     updated tree.
 *
 * */
extern PoliceTree insertByPoliceId(PoliceTree root, PoliceId id, int amount);


/**  reorderByFineAmount - this function reorders the BST on the basis ofg fine amount
 *                          and returns the root node of updated tree.
 * */
extern PoliceTree reorderByFineAmount(PoliceTree root);


/**  printBonusPolicemen - this function prints the policemen who have earned more than 90% of
 *                         of maximum fine amount on to a file called "bonus.txt".
 * */
extern void printBonusPolicemen(PoliceTree root);

/** destroyPoliceTree - this function is a clean up function that destroys all the nodes
 *                      in the police tree.
 * */
extern void destroyPoliceTree (PoliceTree root);

// for debuggging
extern void printPoliceTree (PoliceTree root);
