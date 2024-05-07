/**
 * File: read-files.c
 * Author: Victor Kolis
 * Date: 05/06/2024
 * Description: Implements functions that take terminal arguments
 *                          in order to list files in a given dir
 *                          e.g.: (such as) ls in bash scripting
 *                          ./read-files ~, lists files in home
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
