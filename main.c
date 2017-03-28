#include <SI_EFM8BB3_Register_Enums.h>         


int delay = 10000;

void CheckButton(){
	if (P0_B2 == 0) {
		delay = delay - 1500;
	}else if (P0_B3 == 0){
		delay = delay + 1500;
	}
}

void Delay(delay){
	int i;
	for(i = 0; i < delay; i++){}
}

int main (void)
{
	XBR2 |= 0x40;
	while (1) {
		CheckButton();
		P1_B4 = 1;
		Delay(delay);
		P1_B4 = 0;
		Delay(delay);
		};
// Spin forever
}
