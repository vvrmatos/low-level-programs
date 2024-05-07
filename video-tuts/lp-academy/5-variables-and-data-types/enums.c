#include <stdio.h>
#include <stdlib.h>

int main() {

    enum gender {male, female}; // The standard enumeration starts at {0...n}. So male == 0, female == 1.
    enum gender myGender; //
    myGender = female;

    printf("%d", myGender);

    return EXIT_SUCCESS;
}
