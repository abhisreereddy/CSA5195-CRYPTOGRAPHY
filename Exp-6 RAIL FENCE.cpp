#include <stdio.h>
#include <string.h>
void encryptRailFence(char *text, int rails);
void decryptRailFence(char *text, int rails);
int main() {
    char text[100];
    int rails;
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter the number of rails: ");
    scanf("%d", &rails);
    getchar();
    encryptRailFence(text, rails);
    printf("Encrypted text: %s\n", text);
    decryptRailFence(text, rails);
    printf("Decrypted text: %s\n", text);
    return 0;
}
void encryptRailFence(char *text, int rails) {
    int len = strlen(text);
    char encryptedText[len];
    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = i; j < len; j += rails) {
            encryptedText[index++] = text[j];
        }
    }
    encryptedText[index] = '\0';
    strcpy(text, encryptedText);
}
void decryptRailFence(char *text, int rails) {
    int len = strlen(text);
    char decryptedText[len];
    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = i; j < len; j += rails) {
            decryptedText[j] = text[index++];
        }
    }
    decryptedText[len] = '\0';
    strcpy(text, decryptedText);
}

