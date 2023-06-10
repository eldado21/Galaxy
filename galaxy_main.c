#include "galaxy.h"

int main(){
    int size = 4000;
    vec screenBounds;
    int xyBound = 600;
    molecule bh;
    molecule arr[size];

    vec_init(&screenBounds, xyBound, xyBound);
    setupGalaxy(&bh, arr, size, screenBounds, 10000);
    randomizeStarsPositions(arr, size, xyBound/2 - 150, xyBound/2 + 150);
    displayGalaxy(&bh, arr, size, screenBounds, 1000);

    return EXIT_SUCCESS;
}