#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "levenshtein.h"

int main() {
    srand(time(0));  // Seed the random number generator

    // Generate two random strings of random length(between 1 and 500)
    int length1 = rand() % 500 + 1;
    int length2 = rand() % 500 + 1;
    char str1[length1 + 1];
    char str2[length2 + 1];
    generateRandomString(str1, length1);
    generateRandomString(str2, length2);


    int distance = levenshteinDistance(str1, str2);



    printf("Random String 1: %s\n", str1);
    printf("Length of String 1: %d\n", length1);
    printf("Random String 2: %s\n", str2);
    printf("Length of String 2: %d\n", length2);
    printf("Minimum number of operations required: %d\n", distance);

    return 0;
}
