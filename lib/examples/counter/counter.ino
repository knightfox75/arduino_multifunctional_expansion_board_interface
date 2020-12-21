/*******************************************************************************

	Arduino Multifunctional Expansion Board Interface Example
	Counter in Decimal, Hexadecimal & Binary formats
	Ver 1.1.0

	(cc) 2020 por Cesar Rincon
	
	nightfoxandco.com
	contact@nightfoxandco.com

    This example is under CREATIVE COMMONS licence
	"Attribution-NonCommercial 4.0 International"
	https://creativecommons.org/licenses/by-nc/4.0/

*******************************************************************************/



/*** Includes ***/
// Arduino
#include <Arduino.h>
/*** Includes del proyecto ***/
#include <amebi.h>


/*** Methods & properties declaration ***/

// Create the library object
Amebi amebi;

// Some properties for the logic
uint32_t timer;
const uint32_t timer_delay = 200;
int8_t counter;
bool _auto;

// Program's logic
void Logic();				// Function for the logic
uint32_t runtime_timer;		// Runtime speed counter
const uint32_t runtime_latency = (1000 / 60);


/*** At the Start ***/
void setup() {

	// Starts the library
	amebi.Boot();

	// Runtime counter
	runtime_timer = 0;

	// Timer for the auto mode
	timer = millis() + timer_delay;
	counter = 0;
	_auto = false;

	// Default display values
	amebi.PrintDecimalNumber(counter);
	amebi.BitmaskLed(counter);
	amebi.SetDigit(3, counter);

}



/*** Main Loop ***/
void loop() {

	// Do de program's logic
	Logic();

	// Update the library status
	amebi.Update();

}



/*** Program Logic ***/
void Logic() {

	// Control del runtime
	if (millis() < runtime_timer) return;
	runtime_timer = millis() + runtime_latency;

	// Lee las entradas
	amebi.ReadInputs();

	// Accion UP / DOWN
	bool up = false, down = false;

	// Modo auto si/no (BOTON A1)
	if (amebi.button[0].down) {
		_auto = !_auto;
		amebi.Beep();
	}

	// Si estas en modo automatico
	if (_auto) {
		if (millis() > timer) {
			up = true;
			timer = millis() + timer_delay;
		}
	} else {	// Modo manual
		if (amebi.button[2].down) {		// (BOTON A2)
			up = true;
			amebi.Beep();
		}
		if (amebi.button[1].down) {		// (BOTON A3)
			down = true;
			amebi.Beep();
		}
	}

	// Actualiza los marcadores
	if (up) {
		counter ++;
		if (counter > 0x0F) counter = 0x00;
	}
	if (down) {
		counter --;
		if (counter < 0x00) counter = 0x0F;
	}

	// Contador decimal
	amebi.PrintDecimalNumber(counter);
	// Contador hexadecimal
	amebi.SetDigit(3, counter);
	// Contador binario
	amebi.BitmaskLed(counter);	

}