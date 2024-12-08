#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define NOT_UEFI -3

typedef struct LicenseTable {
	uint32_t Signature;
	uint32_t Length;
	uint8_t Revision;
	uint8_t Checksum;
	char OEMID[6];
	char OEMTableID[8];
	uint32_t OEMRevision;
	uint32_t CreatorID;
	uint32_t CreatorRevision;
	char* SoftrwareLicensingStructure;
} LicenseTable;

#ifdef __linux__ 

#include "linux.h"

#elif _WIN32
#include "win32.h"
#else

#endif
