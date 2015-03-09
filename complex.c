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

    printf("Hello!\n");
    printf("Please enter your first string: ");
    get_input(string1);

    printf("Please enter your second string: ");
    get_input(string2);

    count = compare(string1, string2);
    printf("Result: %i\n", count);

    return EXIT_SUCCESS;
}

int compare(char * string1, char * string2) {
    int i;
    int size1 = (unsigned) strlen(string1) - 1; // For newline
    int size2 = (unsigned) strlen(string2) - 1; // For newline
    int count = 0;
    int hash[NUM_ASCII] = {0};

    for(i = 0; i < size1; i++) {
        hash[string1[i]]++;
    };

    for(i = 0; i < size2; i++) {
        count += hash[string2[i]];
    }

    return count;
}

void get_input(char * buffer) {

    if(fgets(buffer, BUF_SIZE, stdin) == NULL) {
        printf("Error reading stdin into buffer");
        exit(EXIT_SUCCESS);
    }
}
