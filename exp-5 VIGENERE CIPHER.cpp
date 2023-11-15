#include <stdio.h>
#include <string.h>
void vigenereEncrypt(char *text, char *key) {
    int textLength = strlen(text);
    int keyLength = strlen(key);

    for (int i = 0; i < textLength; i++) {
        char currentChar = text[i];
        char keyChar = key[i % keyLength]; 
        char encryptedChar;

        if (currentChar >= 'A' && currentChar <= 'Z') {
            encryptedChar = 'A' + ((currentChar - 'A' + keyChar - 'A') % 26);
        } else if (currentChar >= 'a' && currentChar <= 'z') {
            encryptedChar = 'a' + ((currentChar - 'a' + keyChar - 'A') % 26);
        } else {
            encryptedChar = currentChar; 
        }

        text[i] = encryptedChar;
    }
}

void vigenereDecrypt(char *text, char *key) {
    int textLength = strlen(text);
    int keyLength = strlen(key);

    for (int i = 0; i < textLength; i++) {
        char currentChar = text[i];
        char keyChar = key[i % keyLength]; 
        char decryptedChar;

        if (currentChar >= 'A' && currentChar <= 'Z') {
            decryptedChar = 'A' + ((currentChar - keyChar + 26) % 26);
        } else if (currentChar >= 'a' && currentChar <= 'z') {
            decryptedChar = 'a' + ((currentChar - keyChar + 26) % 26);
        } else {
            decryptedChar = currentChar; 
        }

        text[i] = decryptedChar;
    }
}

int main() {
    char plaintext[100];
    char key[100];

    printf("Enter the plaintext: ");
    gets(plaintext);

    printf("Enter the key: ");
    gets(key);

    vigenereEncrypt(plaintext, key);
    printf("Encrypted Text: %s\n", plaintext);

    vigenereDecrypt(plaintext, key);
    printf("Decrypted Text: %s\n", plaintext);

    return 0;
}

