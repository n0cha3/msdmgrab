#include "win32.h"

int GetMSDMString(char** Output) {
    UNREFERENCED_PARAMETER(Output);
    FIRMWARE_TYPE FType = 0;
    GetFirmwareType(&FType);
    PCHAR FwBuffer = NULL;
        if (FType == FirmwareTypeUefi) {
            DWORD TableSize = GetSystemFirmwareTable('ACPI', 'PCAF', NULL, 0);
            if (TableSize != 0) {
                FwBuffer = calloc(TableSize, sizeof(char) + 1);
                FwBuffer[TableSize] = '\0';
                if (GetSystemFirmwareTable('ACPI', 'PCAF', FwBuffer, TableSize)) {
                    MessageBoxA(NULL, FwBuffer, "table output", MB_OK);
                }  //atm i use the pcaf table to test output since vmware doesnt have a slic table
            }
        }
        else return NOT_UEFI;

    return 0;
}