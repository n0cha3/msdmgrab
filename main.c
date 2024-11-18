#include "main.h"

void FormatString(char *MSDMString) {

}

int main(void) {
    char *KeyString = NULL;
    GetMSDMString(KeyString);
    if (KeyString != NULL) {
        puts(KeyString);
        puts("test");
    }
    return EXIT_SUCCESS;
}