/*
 * Keypad.h
 *
 * Created: 13-12-2019 14:03:02
 *  Author: robe1819
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

void init();								//Funktion der initialiser Pull-up

int ColumnScan();							//Funktion der styre C1-C4 via 4 portbit.

int ReadRows();								//Funktion der læse R1-R4 og returner den specifik row.

char DecodeKeyboard(int column, int row);	//Funktion der decoder mine knapper på bestemt koloner og rækker.

#endif /* KEYPAD_H_ */