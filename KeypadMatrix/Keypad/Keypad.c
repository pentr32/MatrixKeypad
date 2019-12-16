/*
 * Keypad.c
 *
 * Created: 13-12-2019 14:04:27
 *  Author: robe1819
 */ 

#define F_CPU 16E6
#include <avr/io.h>
#include <util/delay.h>
#include "Keypad.h"

#pragma region Defines
#define _delay500 _delay_ms(40);
#define _delay10 _delay_ms(3);

//Output port
#define C1 PK3	//Channel 0
#define C2 PK2	//Channel 1
#define C3 PK1	//Channel 2
#define C4 PK0	//Channel 3

//Input Pin
#define R1 PK4
#define R2 PK5
#define R3 PK6
#define R4 PK7
#pragma endregion

//Funktion der initialiser Pull-up
void init()
{
	DDRK |= (1<<C4) | (1<<C3) | (1<<C2) | (1<<C1);				//Output
	
	PORTK |= (1<<DDK4) | (1<<DDK5) | (1<<DDK6) | (1<<DDK7);		//Enable Pull-up
}

//Funktion der styre C1-C4 via 4 portbit.
int ColumnScan()
{
	static int columnCount = 1;
	PORTK |= (1<<C4) | (1<<C3) | (1<<C2) | (1<<C1);		//Sætter bit til logik 1. dvs. man sætter 1 på alle koloner.
	
	switch(columnCount)
	{
		case 1:
		PORTK &= ~(1<<C1);		//Sæt bit logik 0. PK3
		columnCount++;
		_delay500;
		return 1;
		break;

		case 2:
		PORTK &= ~(1<<C2);		//Sæt bit logik 0. PK2
		columnCount++;
		_delay500;
		return 2;
		break;
		
		case 3:
		PORTK &= ~(1<<C3);		//Sæt bit logik 0. PK1
		columnCount++;
		_delay500;
		return 3;
		break;
		
		case 4:
		PORTK &= ~(1<<C4);		//Sæt bit logik 0. PK0
		columnCount = 1;
		_delay500;
		return 4;
		break;
	}
}

//Funktion der læse R1-R4 og returner den specifik row.
int ReadRows()
{
	if(~PINK & (1<<R1))		//PK4
	{
		_delay10;
		return 1;
	}
	
	if(~PINK & (1<<R2))		//PK5
	{
		_delay10;
		return 2;
	}
	
	if(~PINK & (1<<R3))		//PK6
	{
		_delay10;
		return 3;
	}
	
	if(~PINK & (1<<R4))		//PK7
	{
		_delay10;
		return 4;
	}
}

//Funktion der decoder mine knapper på bestemt koloner og rækker.
char DecodeKeyboard(int column, int row)
{
	char knap[16] = {
		'1', '2', '3', 'A',
		'4', '5', '6', 'B',
		'7', '8', '9', 'C',
		'*', '0', '#', 'D'
	};
	
	switch(column)
	{
		//column1
		#pragma region
		case 1:
		if(row == 1) return knap[0];		//knap: 1
		
		if(row == 2) return knap[4];		//knap: 4
		
		if(row == 3) return knap[8];		//knap: 7
		
		if(row == 4) return knap[12];		//knap: *
		break;
		#pragma endregion
		
		
		//column2
		#pragma region
		case 2:
		if(row == 1) return knap[1];		//knap: 2
		
		if(row == 2) return knap[5];		//knap: 5
		
		if(row == 3) return knap[9];		//knap:	8
		
		if(row == 4) return knap[13];		//knap: 0
		break;
		#pragma endregion
		
		
		//column3
		#pragma region
		case 3:
		if(row == 1) return knap[2];		//knap: 3
		
		if(row == 2) return knap[6];		//knap: 6
		
		if(row == 3) return knap[10];		//knap: 9
		
		if(row == 4) return knap[14];		//knap: #
		break;
		#pragma endregion
		
		
		//column4
		#pragma region
		case 4:
		if(row == 1) return knap[3];		//knap: A
		
		if(row == 2) return knap[7];		//knap: B
		
		if(row == 3) return knap[11];		//knap: C
		
		if(row == 4) return knap[15];		//knap: D
		break;
		#pragma endregion
	}
}