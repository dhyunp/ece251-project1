//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB3_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
// $[Generated Includes]
// [Generated Includes]$
//-----------------------------------------------------------------------------
// NoDipZone - Daniel Park, Christopher E
// ----------------------------------------------------------------------------
// No more mechanical DIP switches in the ALU circuit.
// Sets input value and desired operation using pushbuttons on the EFM8 Busy Bee
//-----------------------------------------------------------------------------
// PB1 (Left button) Increments
// PB0 (Right button) Selects
//
// Number output:
// P0_B4 	MSB
// P0_B5
// P0_B6
// P0_B7 	LSB
//
// Operation output:
// P1_B0	MSB
// P1_B1	LSB
//
// P1_B0	P1_B1	Operation
// 0		0		Add
// 0		1		Zeros/Ones
// 1		0		And
// 1		1		Or
//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------

void Delay();

int main(void) {
	// Call hardware initialization routine
	enter_DefaultMode_from_RESET();
	XBR2 |= 0x40;					//enables output to pins

	P0_B4 = 0;
	P0_B5 = 0;
	P0_B6 = 0;
	P0_B7 = 0;
	P1_B0 = 0;
	P1_B1 = 0;
	P1_B2 = 0;

	while (1) {
		int stage = 0;
		int number = 0;
		int operation = 0;
		int i;

		while (stage == 0) {			//selecting number
			//P1_B4 = 0; //g
			//P1_B5 = 0; //b
			P1_B6 = 0; //r
			if (P0_B3 == 0) {		//pushbutton 1, increments number
				number++;
				if (number > 15) {
					number = 0;
				}
			} else if (P0_B2 == 0) {	//pushbutton 0, sets number
				stage++;
			}
		}

		Delay();
		Delay();

		while (stage == 1) {			//converts number to binary
			switch (number) {
			case 0:
				P0_B4 = 0;		//MSB
				P0_B5 = 0;
				P0_B6 = 0;
				P0_B7 = 0;		//LSB
				stage++;
				break;
			case 1:
				P0_B4 = 0;
				P0_B5 = 0;
				P0_B6 = 0;
				P0_B7 = 1;
				stage++;
				break;
			case 2:
				P0_B4 = 0;
				P0_B5 = 0;
				P0_B6 = 1;
				P0_B7 = 0;
				stage++;
				break;
			case 3:
				P0_B4 = 0;
				P0_B5 = 0;
				P0_B6 = 1;
				P0_B7 = 1;
				stage++;
				break;
			case 4:
				P0_B4 = 0;
				P0_B5 = 1;
				P0_B6 = 0;
				P0_B7 = 0;
				stage++;
				break;
			case 5:
				P0_B4 = 0;
				P0_B5 = 1;
				P0_B6 = 0;
				P0_B7 = 1;
				stage++;
				break;
			case 6:
				P0_B4 = 0;
				P0_B5 = 1;
				P0_B6 = 1;
				P0_B7 = 0;
				stage++;
				break;
			case 7:
				P0_B4 = 0;
				P0_B5 = 1;
				P0_B6 = 1;
				P0_B7 = 1;
				stage++;
				break;
			case 8:
				P0_B4 = 1;
				P0_B5 = 0;
				P0_B6 = 0;
				P0_B7 = 0;
				stage++;
				break;
			case 9:
				P0_B4 = 1;
				P0_B5 = 0;
				P0_B6 = 0;
				P0_B7 = 1;
				stage++;
				break;
			case 10:
				P0_B4 = 1;
				P0_B5 = 0;
				P0_B6 = 1;
				P0_B7 = 0;
				stage++;
				break;
			case 11:
				P0_B4 = 1;
				P0_B5 = 0;
				P0_B6 = 1;
				P0_B7 = 1;
				stage++;
				break;
			case 12:
				P0_B4 = 1;
				P0_B5 = 1;
				P0_B6 = 0;
				P0_B7 = 0;
				stage++;
				break;
			case 13:
				P0_B4 = 1;
				P0_B5 = 1;
				P0_B6 = 0;
				P0_B7 = 1;
				stage++;
				break;
			case 14:
				P0_B4 = 1;
				P0_B5 = 1;
				P0_B6 = 1;
				P0_B7 = 0;
				stage++;
				break;
			case 15:
				P0_B4 = 1;
				P0_B5 = 1;
				P0_B6 = 1;
				P0_B7 = 1;
				stage++;
				break;
			}
		}

		Delay();
		Delay();

		while (stage == 2) {			//selecting operation
			P1_B5 = 0; //b
			P1_B6 = 1; //r
			if (P0_B3 == 0) {
				operation++;
				if (operation > 3) {
					operation = 0;
				}
			}
			if (P0_B2 == 0) {
				stage++;
			}
		}

		Delay();
		Delay();

		while (stage == 3) {				//converts operation to binary
			switch (operation) {
			case 0:
				P1_B0 = 0;	//MSB
				P1_B1 = 0;	//LSB
				stage++;
				break;
			case 1:
				P1_B0 = 0;
				P1_B1 = 1;
				stage++;
				break;
			case 2:
				P1_B0 = 1;
				P1_B1 = 0;
				stage++;
				break;
			case 3:
				P1_B0 = 1;
				P1_B1 = 1;
				stage++;
				break;
			}
		}

		Delay();
		Delay();

		while (stage == 4) {
			P1_B4 = 0; //g
			P1_B5 = 1; //b
			//	P1_B6 = 0; //r
			if (P0_B3 == 0) {
				P1_B2 = 1;
				for (i = 0; i < 10000; i++) {
				}
				P1_B2 = 0;
			}
		}

		Delay();
		Delay();

		while (stage == 5) {
			if (P0_B2 == 0 && P0_B3 == 0) {
				stage++;
			}
		}
	} //run forever
}

void Delay() {
	int x;
	for (x = 0; x < 20000; x++) {
	}
}
// $[Generated Run-time code]
// [Generated Run-time code]$

