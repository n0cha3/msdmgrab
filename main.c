#include "main.h"

LicenseTable FillStruct(char* MSDMString) {
    LicenseTable MSDM;
    memcpy(&MSDM, MSDMString, 36);
    MSDM.SoftrwareLicensingStructure = calloc(MSDM.Length, sizeof(char));
    return MSDM;
}

bool CheckSLIC(LicenseTable* MSDM) {
    if (MSDM->Signature == 'SLIC') return true;
    else return false;
}

int main(void) {
    char *KeyString = NULL;
    GetMSDMString(NULL);
    if (KeyString != NULL) {
        puts(KeyString);
        free(KeyString);
    }
    return EXIT_SUCCESS;
}