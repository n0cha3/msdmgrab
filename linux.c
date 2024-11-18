#include "linux.h"

bool GetMSDMString(char *Output) {
    const char *AcpiPath = "/sys/firmware/acpi/tables";
    const char *MSDM = "test.txt";
    char *Buffer = NULL;
    struct stat DirStat;
    if (stat(AcpiPath, &DirStat) == 0 && S_ISDIR(DirStat.st_mode)) {
        int MSDMFile = open(MSDM, O_RDONLY);
            if (MSDMFile != -1) {
                struct stat FileStat;
                if (fstat(MSDMFile, &FileStat) == 0 && S_ISREG(FileStat.st_mode)) {
                    Buffer = calloc(FileStat.st_size + 1, sizeof(char));
                    read(MSDMFile, Buffer, FileStat.st_size);
                    Buffer[FileStat.st_size] = '\0';
                    Output = Buffer;
                }  
            }

            else return false;
    }

    return true;
} 