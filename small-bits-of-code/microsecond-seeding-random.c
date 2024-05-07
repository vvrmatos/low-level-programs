/**
 * File: microsecond-seeding-random.c
 * Author: Victor Kolis
 * Date: 05/06/2024
 * Description: Implements time.h and sys/time.h that differs from the Unix-epoch
 *                                      approach. And offers a better seeding
 *                                      timing, differing from the previous one
 *                                      not having to wait a certain time to use another
 *                                      seed to get new pseudo-random random values.
 * 
 * License: The unlicensed
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h> // Include for gettimeofday() on Unix-like systems

int main() {
    struct timeval tv;
    gettimeofday(&tv, NULL);

    unsigned long time_in_micros = 1000000 * tv.tv_sec + tv.tv_usec;
    srand(time_in_micros);

    for (int i = 0; i < 5; i++) {
        printf("%d\n", rand());
    }

    return 0;
}
