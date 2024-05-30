#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "levenshtein.h"

// Function that finds the minimum of three values
int Min(int a, int b, int c) {
    if (a < b && a < c) return a;
    if (b < a && b < c) return b;
    return c;
}

// Function to compute the Levenshtein distance
int levenshteinDistance(char str1[], char str2[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int matrix[len1+1][len2+1];

    // Fill the first row and column of the matrix
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Fill the rest of the matrix based on the minimum cost of operations
    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = 1 + Min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]);
            }
        }

    // Return the final value in the matrix
    return matrix[len1][len2];
}

// Function to generate a random string of given length
void generateRandomString(char *str, int length) {
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % (sizeof(charset) - 1);
        str[i] = charset[randomIndex];
    }
    str[length] = '\0';  // Closes the string
}
