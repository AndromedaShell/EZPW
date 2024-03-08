#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 

#define c_color "\x1b[38;5;177m"

char bigStrongChars() {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+=~";
    const size_t charset_length = sizeof(charset) - 1;
    return charset[rand() % charset_length];
}

void cuteSecurePW(char *password, int length) {
    int i;
    for (i = 0; i < length; ++i) {
        password[i] = bigStrongChars();
    }
    password[length] = '\0';
}

int main() {
    srand(time(NULL));
    
    printf(c_color "[+] How long do you want your password to be ?: ");
    int length;
    scanf("%d", &length);

    char password[length + 1];
    cuteSecurePW(password, length);

    printf("\n[-] Done, here is your password: %s\n", password);
    return 0;
}
