#include <stdio.h>
#include <time.h>

int
NumberRandom(int min, int max)
{
    unsigned int seed = (int)clock();
    //unsigned int seed = (int)time(0) * (int)clock();
    srand(seed);
    return rand() % (max - min + 1) + min;
}

