#include "galaxy.h"

int main(int argc, char* argv[]){
    int size = 10000;

    printf("%d\n", argc);
    if (argc == 2) {
        // status stores user input value or 0 if atoi error
        int status = atoi(argv[1]);

        if (status != 0 && status < 50000) {
            size = status;
            printf("Using user input: %d entities\n", size);
        }
    }
    
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