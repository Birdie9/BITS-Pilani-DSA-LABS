#include "DriverHash.h"

#include <stdio.h>
#include <stdlib.h>

// the hash function used
#define hash(x) (x) % MAX_HASH

extern void initializeHash(DriverHash dh);

/** insertHash - inserts the license number lic to the hash table
 * */
extern void insertHash(DriverHash dh, License lic);

/** printViolators - this function prints the serious voilators 
 *                   by looking through all hash table entries 
 *                   and printing the license numbers of the drivers who have
 *                   more than 3 violations onto the file "violators.txt".
 * */
extern void printViolators(DriverHash dh);

/** destroyHash - this function destroys all the entries inside hash table.
 *                this is a clean up code.
 * */
extern void destroyHash(DriverHash dh);

