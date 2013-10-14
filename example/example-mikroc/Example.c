#include <stdint.h>

// variables imported by gcc
uint8_t readbuff[64], writebuff[64];

// functions exported by gcc
void    (*const reset_handler)(void)                  = 0xdeadbeef;
uint8_t (*const do_calculation)(uint8_t a, uint8_t b) = 0xdeadbeef;
void    (*const message_usbhid)(uint8_t)              = 0xdeadbeef;

void USB1Interrupt() iv IVT_INT_OTG_FS {
	USB_Interrupt_Proc();
}

void main() {
	uint8_t res;
	
	if(0) {
		// functions imported by gcc
		asm {
			BL _HID_Read;
			BL _HID_Write;
		};
	}
	
	NVIC_IntEnable(IVT_INT_OTG_FS);
	HID_Enable(readbuff, writebuff);
	
	// you need to call reset_handler before using stuff from gcc
	reset_handler();
	
	res = do_calculation(67, 71);
	
	while(1) {
		message_usbhid(res);
	}
}
