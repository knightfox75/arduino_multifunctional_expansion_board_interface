/*******************************************************************************

	Arduino Multifunctional Expansion Board Interface Example
	Counter in Decimal, Hexadecimal & Binary formats
	Ver 1.0.0

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

	// If timer is not researched the limit, exit
	if (millis() < runtime_timer) return;

	// New timestamp
	runtime_timer = millis() + runtime_latency;

	// Read the inputs from the shield
	amebi.ReadInputs();

	// UP / DOWN
	bool up = false, down = false;

	// AUTO mode? (BUTTON A1)
	if (amebi.button[0].down) _auto = !_auto;

	// AUTO mode enabled
	if (_auto) {
		if (millis() > timer) {
			up = true;
			timer = millis() + timer_delay;
		}
	} else {	// Manual mode
		up = amebi.button[2].down;		// (BUTTON A3)
		down = amebi.button[1].down;	// (BUTTON A2)
	}

	// Update the counter
	if (up) {
		counter ++;
		if (counter > 0x0F) counter = 0x00;
	}
	if (down) {
		counter --;
		if (counter < 0x00) counter = 0x0F;
	}

	// Decimal counter print
	amebi.PrintDecimalNumber(counter);
	// Hexadecimal counter print
	amebi.SetDigit(3, counter);
	// Binary counter print
	amebi.BitmaskLed(counter);	

}