#ifndef LEVENSHTEIN_H_INCLUDED
#define LEVENSHTEIN_H_INCLUDED

// Function that finds the minimum of three values
int Min(int a, int b, int c);

// Function to compute the Levenshtein distance
int levenshteinDistance(char str1[], char str2[]);

// Function to generate a random string of given length
void generateRandomString(char *str, int length);

#endif // LEVENSHTEIN_H_INCLUDED
