#ifndef IMPORTS_H
#define IMPORTS_H

// Add here the functions and variables which you want to import
// from mikroC. The addresses are automatically updated by
// mikrostm-link. Do not forget to declare the pointers as const.

static char (*const HID_Read)(void) = (void*)0x3e31;
static char (*const HID_Write)(char *writebuff, char len) = (void*)0x3dd1;

static unsigned char *const readbuff = (void*)0x200000d4;
static unsigned char *const writebuff = (void*)0x20000114;

#endif
