#define F_CPU 16E6
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "stdio_setup.h"
#include <avr/interrupt.h>
#include "Keypad/Keypad.h"

int column;
int row;

int main(void)
{
	UartInit();
	init();

	while(1) {
		column = ColumnScan();
		row = ReadRows();
		printf("%c", DecodeKeyboard(column, row));
	}
}