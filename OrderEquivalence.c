#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Chelsea Hanson: Homework 1 - Problem 6
//This was done as the first example of how to do this problem where it just tests greater than or less than.

int main() {
    
    char input[100];
    int in_length;
    int nums[32];
    int y = 0;
    int currentInt = 0;
    int count = 0;
    
    printf("\nEnter numbers separated by a space to see if they are order equivalent: \n\n");

    // gets user input including whitespace
    scanf("% [^\n]s", input);
    in_length = strlen(input);
    
    // turns character array into array of integers
    while ( y < in_length) {
        if ( input[y] == ' ') {
            y++;
            continue;
        }
        while (isdigit(input[y])) {
            currentInt *= 10;
            currentInt += (int)(input[y++] - 48);
        }
        nums[count++] = currentInt;
        currentInt = 0;
        y++;
    }
    
    // tests for order equivalence only when appropriate
	if (count == 0) {
		printf ("No input string given to check order equivalence on.");
	}
    else if (count < 3) {
        printf ("There are not enough values to compare.");
    }
	else  if (count % 2 != 0) {
		printf ("Cannot check for order equivalence on an odd number of values.");
	}
	else {
        int i, j;
	    for (i = 0, j = (count) / 2; j < count - 1; i++, j++) {
            // as soon as one increases while the other decreases, we know it's not order equivalent
			if ((nums[i] < nums[i + 1] && nums[j] > nums[j + 1])
				    || (nums[i] > nums[i + 1] && nums[j] < nums[j + 1])) {
				printf("The split is not order equivalent.");
				return 0;
			}
		}
		printf ("The split is order equivalent.");
	}

	return 0;
}