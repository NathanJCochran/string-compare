#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 4096
#define NUM_ASCII 128

void get_input(char * buffer);
int compare(char * string1, char * string2);

int main(int argc, char * argv[]) {
    char string1[BUF_SIZE];
    char string2[BUF_SIZE];
    int count;

    // If command line args were given, use those as the strings:
    if(argc != 3) {
        printf("Hello!\n");
        printf("Please enter your first string: ");
        get_input(string1);

        printf("Please enter your second string: ");
        get_input(string2);

        count = compare(string1, string2);
    }
    // Else, prompt the user for strings:
    else {
        count = compare(argv[1], argv[2]);
    }

    printf("Result: %i\n", count);

    return EXIT_SUCCESS;
}

/*
 *  This is the actual compare method.
 *  It takes two strings, and returns the number
 *  of matching characters between them.
 */
int compare(char * string1, char * string2) {
    int i;
    int count = 0;
    int hash[NUM_ASCII] = {0};

    // Iterate through each character in the first string.
    // Increment a counter in a hash for each character:
    for(i = 0; string1[i] != '\0'; i++) {
        hash[(int) string1[i]]++;
    };

    // Iterate through the second string, summing
    // up the counters in the hash for each character:
    for(i = 0; string2[i] != '\0'; i++) {
        count += hash[(int) string2[i]];
    }

    return count;
}

/*
 * This method simply gets some input from stdin
 * and stores it in the given buffer.  Removes
 * the trailing newline.
 */
void get_input(char * buffer) {
    unsigned len;

    if(fgets(buffer, BUF_SIZE, stdin) == NULL) {
        printf("Error reading stdin into buffer");
        exit(EXIT_SUCCESS);
    }

    len = (unsigned) strlen(buffer);
    buffer[len - 1] = '\0'; // For newline
}
