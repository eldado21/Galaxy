#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "vector.h"
#include "gfx.h"

#ifndef _FROTTEMENT_H_
#define _FROTTEMENT_H_

typedef struct _molecule{
    double mass;
    int intensity;
    vec position;
    vec velocity;
    vec lastPosition;
} molecule;

int get_random(int min, int max);
void molecule_init(molecule *m, int posMin, int posMax);
void molecule_print(const molecule m);
vec molecule_calculate_gravitation(molecule* m1, const molecule* m2); // result+=molecule_calculate_gravitation(m1, list_molecule[i]);
vec getForceRes(double k, vec vitesse);

#endif