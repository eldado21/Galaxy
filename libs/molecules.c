#include "molecules.h"

int get_random(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

void molecule_init(molecule *m, int posMin, int posMax){
    if (posMin < 0 || posMax < 0){
        posMin = 0;
        posMax = 0;
    }
    int whiteIntensity = rand() % 256;
    m->intensity = MAKE_COLOR(whiteIntensity,whiteIntensity,whiteIntensity);
    m->mass = get_random(0, 10);
    vec_init(&m->velocity, get_random(-2, 2), get_random(-2, 2));
    vec_init(&m->position, get_random(posMin, posMax), get_random(posMin, posMax));
    vec_init(&m->lastPosition, -1, -1);
}

void molecule_print(const molecule m){
    printf("Masse : %lf\n", m.mass);
    printf("Position : [%lf:%lf]\n", m.position.x, m.position.y);
}

/**starArray[i].position w(norme, 3))
 * mult_in_place(&distance, scalaire);
 */ 
vec molecule_calculate_gravitation(molecule* m1, const molecule* m2){
    vec rij;
    vec_init(&rij, 0, 0);
    const double G = 6.67E-11;


    double masses = m1->mass * m2->mass;
    rij = vec_sub(m1->position, m2->position);
    double distance = normalize(rij);
    double scalaire = (G * -1) * (masses / pow(distance,3));
    mult_in_place(&rij, scalaire);
    
    return rij;
}

//not finished yet
vec getForceRes(/*molecule *list, int size, */double k, vec vitesse){
    return mult(vitesse, -k);
}
