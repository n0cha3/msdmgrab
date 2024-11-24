#include "main.h"

/*void FormatString(char *MSDMString) {

}*/

int main(void) {
    char *KeyString = NULL;
    if (KeyString != NULL) {
        puts(KeyString);
        free(KeyString);
    }
    return EXIT_SUCCESS;
}