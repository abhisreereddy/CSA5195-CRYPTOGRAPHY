#include <stdio.h>
#include <math.h>
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
int main() {
    int p = 23; 
    int g = 5;   
    int privateA = 6;
    int publicA = modExp(g, privateA, p);
    int privateB = 15;
    int publicB = modExp(g, privateB, p);
    int secretA = modExp(publicB, privateA, p);
    int secretB = modExp(publicA, privateB, p);
    printf("Prime (p): %d\n", p);
    printf("Primitive Root (g): %d\n", g);
    printf("\nAlice's Private Key (privateA): %d\n", privateA);
    printf("Alice's Public Key (publicA): %d\n", publicA);
    printf("\nBob's Private Key (privateB): %d\n", privateB);
    printf("Bob's Public Key (publicB): %d\n", publicB);
    printf("\nShared Secret (Alice): %d\n", secretA);
    printf("Shared Secret (Bob): %d\n", secretB);
    return 0;
}

