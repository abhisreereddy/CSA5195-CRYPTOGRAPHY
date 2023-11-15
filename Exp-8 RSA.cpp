#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;  
}
void generateKeys(int p, int q, int *n, int *e, int *d) {
    *n = p * q;
    int phi = (p - 1) * (q - 1);
    do {
        *e = rand() % (phi - 2) + 2;  
    } while (gcd(*e, phi) != 1);
    *d = modInverse(*e, phi);
}
int modExp(int base, int exponent, int mod) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}
int encrypt(int message, int e, int n) {
    return modExp(message, e, n);
}
int decrypt(int ciphertext, int d, int n) {
    return modExp(ciphertext, d, n);
}
int main() {
    int p = 61;  
    int q = 53;  
    int n, e, d;  
    generateKeys(p, q, &n, &e, &d);
    int message = 42;
    int ciphertext = encrypt(message, e, n);
    printf("Encrypted Message: %d\n", ciphertext);
    int decryptedMessage = decrypt(ciphertext, d, n);
    printf("Decrypted Message: %d\n", decryptedMessage);
    return 0;
}

