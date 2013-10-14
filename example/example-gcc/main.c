#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "main.h"
#include "imports.h"

static const int HIDsize = 64;

static void HID_bWrite(void) {
	// Calls to mikroC functions need to be enclosed
	// with these pushs and pops because of the
	// different calling convention.
	asm("push {r4, r5, r6, r7, r8, r9, r10, r11}");
	while(!HID_Write((char*)writebuff, HIDsize));
	asm("pop {r4, r5, r6, r7, r8, r9, r10, r11}");
}

uint8_t do_calculation(uint8_t a, uint8_t b) {
	return a + b;
}

void message_usbhid(uint8_t a) {
	memset(writebuff, 0, HIDsize);
	snprintf((char*)writebuff, HIDsize, "integer: %d\n", a);
	HID_bWrite();
}
