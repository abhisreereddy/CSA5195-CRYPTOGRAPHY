#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ALPHABET_SIZE 26
void monoalphabeticSubstitution(char *plaintext, char *ciphertext, char *input) {
    while (*input) {
        if (isalpha(*input)) {
            char current_char = tolower(*input);
            int index = current_char - 'a';
            *plaintext = current_char;
            *ciphertext = ciphertext[index];
        } else {
            *plaintext = *input;
            *ciphertext = *input;
        }
        input++;
        plaintext++;
        ciphertext++;
    }
    *plaintext = '\0';
    *ciphertext = '\0';
}
int main() {
    char substitutionKey[ALPHABET_SIZE] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    char inputText[] = "Hello, World!";
    char ciphertext[100];
    char plaintext[100];
    monoalphabeticSubstitution(plaintext, ciphertext, inputText);
    printf("Original Text: %s\n", inputText);
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}

