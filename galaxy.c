#include "galaxy.h"

void setupGalaxy(molecule* blackHole, molecule starArray[], int size, vec screenBounds, double bhMass){
    molecule_init(blackHole, screenBounds.x / 2, screenBounds.y / 2);
    blackHole->mass = bhMass;
    for (int i = 0; i < size; i++){
        molecule tmp;
        molecule_init(&tmp, screenBounds.x, screenBounds.y);
        starArray[i] = tmp;
    }
}

void randomizeStarsPositions(molecule starArray[], int size, int min, int max){
    for(int i = 0; i < size; i++){
        starArray[i].position.x = get_random(min, max);
        starArray[i].position.y = get_random(min, max);
    }
}

void computeVelocity(molecule* m, molecule* bh){
    vec distanceS1S2 = vec_sub(bh->position, m->position);
    double normDistanceS1S2 = normalize(distanceS1S2);
    double v = sqrt((G * bh->mass) / normDistanceS1S2);//sqrt = pow 1/2
    vec vu; // vecteur unitaire
    vec_init(&vu, -distanceS1S2.y / normDistanceS1S2, distanceS1S2.x / normDistanceS1S2);
    vu = mult(vu, v);
    m->velocity = vu;
}

void computeNewPosition(molecule* m, molecule* bh, double deltaTime){
    //a(ti) = -G(ms1 * ms2 / ||dists1-s2||) * s1 - s2
    vec distanceS1S2 = vec_sub(m->position, bh->position);
    double normDistanceS1S2 = normalize(distanceS1S2);
    vec fg = mult(distanceS1S2, -G * ((m->mass * bh->mass) / pow(normDistanceS1S2, 3)));
    vec a = div_with_scalar(fg, m->mass);


    if (m->lastPosition.x == -1 && m->lastPosition.y == -1){
        //pos(t1) = pos(t0) + v(t0) * dt + a(t0) * dt²
        m->lastPosition = m->position;
        computeVelocity(m, bh);
        m->position = vec_add(vec_add(m->position, mult(m->velocity, deltaTime)),mult(a,pow(deltaTime,2)));
    }else{
        //pos(ti + 1) = pos(ti)*2 - pos(ti-1) + a(ti) * dt²
        vec tmp = m->position;
        m->position = vec_add(vec_sub(mult(m->position, 2), m->lastPosition), mult(a, pow(deltaTime,2)));
        m->lastPosition = tmp;
    }
}

void formatBlackhole(struct gfx_context_t* window, molecule* blackHole){
    gfx_putpixel(window, blackHole->position.x, blackHole->position.y, MAKE_COLOR(255, 0, 0));
    gfx_putpixel(window, blackHole->position.x + 1, blackHole->position.y, MAKE_COLOR(255, 0, 0));
    gfx_putpixel(window, blackHole->position.x - 1, blackHole->position.y, MAKE_COLOR(255, 0, 0));
    gfx_putpixel(window, blackHole->position.x, blackHole->position.y + 1, MAKE_COLOR(255, 0, 0));
    gfx_putpixel(window, blackHole->position.x, blackHole->position.y - 1, MAKE_COLOR(255, 0, 0));
}

void displayGalaxy(molecule* blackHole, molecule starArray[], int size, vec screenSize, double deltaTime){
	struct gfx_context_t *ctxt = gfx_create("Galaxy", screenSize.x, screenSize.y);
    vec_init(&blackHole->position, (screenSize.x / 2) - 1, (screenSize.y / 2) - 1);

    while (gfx_keypressed() != SDLK_ESCAPE) {
        for (int i = 0; i < size; i++){
            formatBlackhole(ctxt, blackHole);

            computeNewPosition(&starArray[i], blackHole, deltaTime);
            //scale to screen size
            starArray->position.x = starArray->position.x * (screenSize.x / 10) + screenSize.x / 2; 
            starArray->position.y = starArray->position.y * (screenSize.y / 10) + screenSize.y / 2;
            
            if ((starArray[i].position.x > 0 && starArray[i].position.x < screenSize.x) && (starArray[i].position.y > 0 && starArray[i].position.y < screenSize.y)){
                gfx_putpixel(ctxt, starArray[i].position.x  , starArray[i].position.y , starArray[i].intensity);
            }
        }
        gfx_present(ctxt);
        gfx_clear(ctxt, MAKE_COLOR(0, 0, 0));
	}
    gfx_destroy(ctxt);
}