#include <stdio.h>
#include <string.h>

void bitStuffing(char *input, char *output) {
    int count = 0, j = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        output[j++] = input[i];
        if (input[i] == '1') {
            count++;
        } else {
            count = 0;
        }

        if (count == 5) {
            output[j++] = '0'; // Stuff a '0' after five consecutive '1's
            count = 0; // Reset count
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

void bitUnstuffing(char *input, char *output) {
    int count = 0, j = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        output[j++] = input[i];
        if (input[i] == '1') {
            count++;
        } else {
            count = 0;
        }

        if (count == 5 && input[i + 1] == '0') {
            i++; // Skip the stuffed '0'
            count = 0; // Reset count
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

int main() {
    char input[100];
    char stuffed[120]; // For bit-stuffed output
    char unstuffed[100]; // For un-stuffed output

    printf("Enter a binary string: ");
    scanf("%s", input);

    bitStuffing(input, stuffed);
    printf("Bit Stuffed Output: %s\n", stuffed);

    bitUnstuffing(stuffed, unstuffed);
    printf("Un-stuffed Output: %s\n", unstuffed);

    return 0;
}
