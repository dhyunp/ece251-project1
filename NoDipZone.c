
//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB3_Register_Enums.h>                // SFR declarations

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

int main (void)
{
	XBR2 |= 0x40;					//enables output to pins
	while (1) {
		int stage = 0;
		int number = 0;
		int operation = 0;

		while (stage == 0)			//selecting number
			if (P0_B3 == 0){		//pushbutton 1, increments number
				number++;
				if (number > 15){
					number = 0;
				}
			}
			else if (P0_B2 == 0){	//pushbutton 0, sets number
				stage++;
			}

		while (stage == 1){			//converts number to binary
			switch (number){
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

		while (stage == 2){			//selecting operation
			if (P0_B3 == 0){
				operation++;
				if (operation > 3){
					operation = 0;
				}
			}
			else if (P0_B2 == 0){
				stage++;
			}
		}

		while (stage == 3){				//converts operation to binary
			switch (operation){
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

		while (stage == 4){
			if (P0_B2 == 0 && P0_B3 == 0){
				stage ++;
			}
			else{
				stage = 4;
			}
		}
	}
}
