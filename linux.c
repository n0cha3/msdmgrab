#include "linux.h"

int GetMSDMString(char **Output) {
    const char *AcpiPath = "/sys/firmware/acpi/tables";
    const char *MSDM = "/sys/firmware/acpi/tables/MSDM";
    struct stat DirStat;
    int CharCount = 0;
    if (stat(AcpiPath, &DirStat) == 0 && S_ISDIR(DirStat.st_mode)) {
        int MSDMFile = open(MSDM, O_RDONLY);
            if (MSDMFile != -1) {
                struct stat FileStat;
                if (fstat(MSDMFile, &FileStat) == 0 && S_ISREG(FileStat.st_mode)) {
                    *Output = calloc(FileStat.st_size + 1, sizeof(char));
                    read(MSDMFile, *Output, FileStat.st_size);
                    Output[FileStat.st_size] = '\0';
                    close(MSDMFile);
                    CharCount = FileStat.st_size;
                }  
            }

            else return 0;
    }

    return CharCount;
} 