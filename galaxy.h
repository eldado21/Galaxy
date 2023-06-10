#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <unistd.h>
#include "libs/molecules.h"

#ifndef _GALAXY_H_
#define _GALAXY_H_
#define G 6.673e-11

void setupGalaxy(molecule* blackHole, molecule starArray[], int size, vec screenBounds, double bhMass);
void randomizeStarsPositions(molecule starArray[], int size, int min, int max);
void computeVelocity(molecule* m, molecule* bh);
void formatBlackhole(struct gfx_context_t* window, molecule* bh);
void displayGalaxy(molecule* blackHole, molecule starArray[], int size, vec screenSize, double deltaTime);
void computeNewPosition(molecule* m, molecule* bh, double deltaTime);

#endif