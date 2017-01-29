#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Chelsea Hanson: Homework 4 - Problem 3

int main() {
    
    FILE *infile;
    char fileName[100];
    char searchQuery[100];
    int queryLength;
    char ch;
    int i;
    
    
    printf("\nEnter the relative path name of a .txt file: ");
    scanf("%s", fileName);
    infile = fopen(fileName, "r");
    if (infile == NULL) {
        printf("unable to open file \"%s\"", fileName);
        exit(1);
    }
    
    while ( getchar() != '\n' ); // to clear the newline out of the buffer
    
    printf("\nPlease enter a string to search for in this file: ");
    scanf("%[^\n]s", searchQuery);
    
    queryLength = strlen(searchQuery);
    
    while (fscanf(infile, "%c", &ch) != EOF) {
        if (ch == searchQuery[0]) {
            for (i = 1; i < queryLength; i++) {
                fscanf(infile, "%c", &ch);
                if (ch != searchQuery[i]) {
                    break;
                }
                printf("\nSuccess, the string \"%s\" has been found!", searchQuery);
                fclose(infile);
                return 0;
            }
        }
    }
    printf("\nSorry, the string \"%s\" could not be found. \n", searchQuery);
    fclose(infile);
    return 0;
}