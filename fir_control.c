#include "fir_control.h"
#include <defs.h>

#define reg_fir_control (*(volatile uint32_t*)0x38000000)
#define reg_fir_coeff_addr ((volatile uint32_t*)0x38000040)
#define reg_fir_x (*(volatile uint32_t*)0x38000080)
#define reg_fir_y (*(volatile uint32_t*)0x38000084)


void __attribute__ ( ( section ( ".mprjram" ) ) ) initfir() {
	//initial your fir
	int* ptr = reg_fir_coeff_addr;
	// start 
	reg_fir_control = 0x1;
	// wait until idle = 0
	while((reg_fir_control & 0x4) == 0);
	for (int i = 0; i < N; i++) {
		*(ptr + i) = taps[i];
	}
}

int* __attribute__ ( ( section ( ".mprjram" ) ) ) fir(){
	initfir();
	//write down your fir
	for(int i = 0;i < LEN; i++) {
		// wait until x ready
		while((reg_fir_control & 0x10) == 0);
		reg_fir_x = i;
		while((reg_fir_control & 0x20) == 0);
		outputsignal[i] = reg_fir_y;
	}
	return outputsignal;
}
		
