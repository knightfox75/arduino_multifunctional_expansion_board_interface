/*******************************************************************************

	Arduino Multifunctional Expansion Board Interface
	Ver 0.1.0
	
	Proyecto iniciado el 16-12-2020
	
	(cc) 2020 por Cesar Rincon
	
	nightfoxandco.com
	contact@nightfoxandco.com

	Arduino Multifunctional Expansion Board Interface
    se distribuye bajo la licencia CREATIVE COMMONS
	"Attribution-NonCommercial 4.0 International"
	https://creativecommons.org/licenses/by-nc/4.0/
	
	DISPLAY

*******************************************************************************/



/*** Includes ***/
// Arduino
#include <Arduino.h>
// Includes del proyecto
#include "amebi_display.h"




/*** Constructor ***/
AmebiDisplay::AmebiDisplay() {	
}



/*** Destructor ***/
AmebiDisplay::~AmebiDisplay() {
}



/*** Al iniciar el objeto ***/
void AmebiDisplay::Boot() {

	// Pinout del display
	pinMode(PIN_DISPLAY_LATCH, OUTPUT);
	pinMode(PIN_DISPLAY_CLOCK, OUTPUT);
	pinMode(PIN_DISPLAY_DATA, OUTPUT);

}



/*** Actualizacion del objeto ***/
void AmebiDisplay::Update() {

	// Refresco del marcador
	DisplayRefresh();

}



/*** Limpia el contenido del display ***/
void AmebiDisplay::CleanDisplay() {

	for (uint8_t id = 0; id < 4; id ++) display_data[id] = CHAR_BLANK;

}



/*** Escribe un caracter en un digito ***/
void AmebiDisplay::SetDigit(uint8_t digit, int8_t character) {

	if ((digit >= 4) || (character > CHAR_BLANK)) return;

	display_data[digit] = ~DISPLAY_CHAR[character];

}



/*** Indica que segmentos se han de iluminar en un digito mediante la mascara de bits ***/
void AmebiDisplay::SetSegments(uint8_t digit, uint8_t bitmask) {

	if (digit >= 4) return;

	display_data[digit] = ~bitmask;	

}



/*** Imprime un numero entero decimal (-999 ~ 9999) ***/
void AmebiDisplay::PrintDecimalNumber(int16_t number, bool fill) {

	if ((number < -999) || (number > 9999)) return;

	// Prepara los digitos
	uint8_t digit[4];
	// Guarda si es negativo
	bool negative = (number < 0) ? true:false;
	// Conviertelo a positivo (valor absoluto)
	uint16_t num = abs(number);

	// Unidades
	digit[0] = (num % 10);
	digit[1] = ((num / 10) % 10);
	digit[2] = ((num / 100) % 10);
	digit[3] = (num / 1000);

	// Formato
	for (uint8_t i = 0; i < 4; i ++) {
		if (digit[i] == 0) {
			if (!fill) {
				if (negative) {
					digit[i] = CHAR_MINUS;
					negative = false;
				} else {
					if (i > 0) digit[i] = CHAR_BLANK;
				} 
			} else if ((i == 3) && negative) {
				digit[i] = CHAR_MINUS;
			} 
		}
	}

	// Manda el resultado al display
	for (uint8_t i = 0; i < 4; i ++) SetDigit(i, digit[i]);

}



/*** Imprime un numero entero en formato hexadecimal (0000 ~ FFFF) ***/
void AmebiDisplay::PrintHexadecimalNumber(uint16_t number) {

	if (number > 0xFFFF) return;

	// Extrae los valores de cada digito hexadecimal
	for (uint8_t i = 0; i < 4; i ++) {
		SetDigit(i, ((number >> (i << 2)) & 0x0F));
	}

}



/*** Imprime numero con decimales (-99.9 ~ 999.9) ***/
void AmebiDisplay::PrintFloatNumber(float number, bool fill) {

	if ((number < -99.9) || (number > 999.9)) return;

	// Prepara los digitos
	uint8_t digit[4];
	// Guarda si es negativo
	bool negative = (number < 0) ? true:false;
	// Conviertelo a positivo (valor absoluto)
	uint16_t num = abs(number) * 10;

	// Unidades
	digit[0] = (num % 10);
	digit[1] = ((num / 10) % 10);
	digit[2] = ((num / 100) % 10);
	digit[3] = (num / 1000);

	// Formato
	for (uint8_t i = 0; i < 4; i ++) {
		if (digit[i] == 0) {
			if (!fill) {
				if (negative) {
					digit[i] = CHAR_MINUS;
					negative = false;
				} else {
					if (i > 1) digit[i] = CHAR_BLANK;
				} 
			} else if ((i == 3) && negative) {
				digit[i] = CHAR_MINUS;
			} 
		}
	}

	// Manda el resultado al display
	for (uint8_t i = 0; i < 4; i ++) SetDigit(i, digit[i]);

	// Añade el punto decimal al segundo digito
	display_data[1] = ~(~display_data[1] | DISPLAY_CHAR[CHAR_DOT]);

}



/*** Actualiza la informacion mostrada por el display ***/
void AmebiDisplay::DisplayRefresh() {

	for (uint8_t id = 0; id < 4; id ++) {

		digitalWrite(PIN_DISPLAY_LATCH, 0);
		shiftOut(PIN_DISPLAY_DATA, PIN_DISPLAY_CLOCK, MSBFIRST, display_data[id]);
		shiftOut(PIN_DISPLAY_DATA, PIN_DISPLAY_CLOCK, MSBFIRST, DISPLAY_DIGIT[id]);
		digitalWrite(PIN_DISPLAY_LATCH, 1);

	}

}
