#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Convert a single hex character to its decimal value
int hex_char_to_int(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    if ('a' <= c && c <= 'f') return c - 'a' + 10;
    if ('A' <= c && c <= 'F') return c - 'A' + 10;
    return -1;
}

// Convert a hex string to ASCII
void hex_to_ascii(const char *hex, char *output) {
    size_t len = strlen(hex);
    for (size_t i = 0; i < len; i += 2) {
        int high = hex_char_to_int(hex[i]);
        int low = hex_char_to_int(hex[i + 1]);
        if (high == -1 || low == -1) {
            fprintf(stderr, "Invalid hex character.\n");
            exit(1);
        }
        output[i / 2] = (char)((high << 4) | low);
    }
    output[len / 2] = '\0'; // Null-terminate the result
}

int main() {
    const char *hex_input = "72bca9b68fc16ac7beeb8f849dca1d8a783e8acf9679bf9269f7bf";
    char output[1024]; 

    hex_to_ascii(hex_input, output);

    printf("Decoded: %s\n", output);
    return 0;
}
