#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Initialize random seed
    srand(time(NULL));


    // Generate and print 5 random numbers
    for (int i = 0; i < 5; i++) {
        printf("%d\n", rand());
    }

    return 0;

}
