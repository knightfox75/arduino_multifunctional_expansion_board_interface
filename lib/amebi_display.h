/*******************************************************************************

	Arduino Multifunctional Expansion Board Interface
	Ver 0.2.0
	
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



#ifndef __AMEBI_DISPLAY_H
#define __AMEBI_DISPLAY_H



/*** Includes ***/
// Arduino
#include <Arduino.h>
// Proyecto



/*** Definicion de la clase ***/
class AmebiDisplay {
	
	public:
	
		// Constructor
		AmebiDisplay();
		
		// Destructor
		~AmebiDisplay();

		// Borra el display
		void CleanDisplay();

		// Escribe un caracter en un digito
		void SetDigit(uint8_t digit, int8_t character);

		// Indica que segmentos ha de mostrar un digito
		void SetSegments(uint8_t digit, uint8_t bitmask);

		// Imprime un numero entero decimal (-999 ~ 9999)
		void PrintDecimalNumber(int16_t number, bool fill = false);

		// Imprime un numero entero en formato hexadecimal (0000 ~ FFFF)
		void PrintHexadecimalNumber(uint16_t number);

		// Imprime numero con decimales (-99.9 ~ 999.9)
		void PrintFloatNumber(float number, bool fill = false);

		// Lista de caracteres
		const uint8_t CHAR_0 = 0;
		const uint8_t CHAR_1 = 1;
		const uint8_t CHAR_2 = 2;
		const uint8_t CHAR_3 = 3;
		const uint8_t CHAR_4 = 4;
		const uint8_t CHAR_5 = 5;
		const uint8_t CHAR_6 = 6;
		const uint8_t CHAR_7 = 7;
		const uint8_t CHAR_8 = 8;
		const uint8_t CHAR_9 = 9;
		const uint8_t CHAR_A = 10;
		const uint8_t CHAR_B = 11;
		const uint8_t CHAR_C = 12;
		const uint8_t CHAR_D = 13;
		const uint8_t CHAR_E = 14;
		const uint8_t CHAR_F = 15;
		const uint8_t CHAR_MINUS = 16;
		const uint8_t CHAR_DOT = 17;
		const uint8_t CHAR_BLANK = 18;



	protected:

        // Codigo inicial
        void Boot();
		
		// Ejecuta regularmente
		void Update();
	

	
	private:

		// Definicion de los PINS del marcador digital
		const uint8_t PIN_DISPLAY_LATCH = 4;
		const uint8_t PIN_DISPLAY_CLOCK = 7;
		const uint8_t PIN_DISPLAY_DATA = 8;

		// Seleccion del digito del marcador digital
		const uint8_t DISPLAY_DIGIT[4] = {
			0xF8,		// Derecha
			0xF4,
			0xF2,
			0xF1		// Izquierda
		};

		/*
		----------
			0
		----------
		| |    | |
		|5|    |1|
		| |    | |
		----------
			6
		----------
		| |    | |
		|4|    |2|
		| |    | |
		----------|-|
			3     |7|
		----------|-|
		*/
		const uint8_t DISPLAY_CHAR[20] = {
			((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5)),				// 0
			((1 << 1) | (1 << 2)),															// 1
			((1 << 0) | (1 << 1) | (1 << 6) | (1 << 4) | (1 << 3)),							// 2
			((1 << 0) | (1 << 1) | (1 << 6) | (1 << 2) | (1 << 3)),							// 3
			((1 << 5) | (1 << 1) | (1 << 6) | (1 << 2)),									// 4
			((1 << 0) | (1 << 5) | (1 << 6) | (1 << 2) | (1 << 3)),							// 5
			((1 << 0) | (1 << 5) | (1 << 6) | (1 << 4) | (1 << 2) | (1 << 3)),				// 6
			((1 << 0) | (1 << 1) | (1 << 2)),												// 7
			((1 << 0) | (1 << 5) | (1 << 1) | (1 << 6) | (1 << 4) | (1 << 2) | (1 << 3)),	// 8
			((1 << 0) | (1 << 5) | (1 << 1) | (1 << 6) | (1 << 2) | (1 << 3)),				// 9
			((1 << 0) | (1 << 5) | (1 << 1) | (1 << 6) | (1 << 4) | (1 << 2)),				// A
			((1 << 5) | (1 << 6) | (1 << 4) | (1 << 2) | (1 << 3)),							// b
			((1 << 0) | (1 << 5) | (1 << 4) | (1 << 3)),									// C
			((1 << 1) | (1 << 6) | (1 << 4) | (1 << 2) | (1 << 3)),							// d
			((1 << 0) | (1 << 5) | (1 << 6) | (1 << 4) | (1 << 3)),							// E
			((1 << 0) | (1 << 5) | (1 << 6) | (1 << 4)),									// F
			(1 << 6),																		// -
			(1 << 7),																		// .
			0x00																			// [BLANK]
		};

		// Contenido de cada digito
		uint8_t display_data[4];

		// Actualiza la informacion del display
		void DisplayRefresh();
		
};



#endif
