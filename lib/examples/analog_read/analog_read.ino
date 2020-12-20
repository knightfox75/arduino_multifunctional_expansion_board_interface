/*******************************************************************************

	Arduino Multifunctional Expansion Board Interface Example
	Analogic input reading
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

	// Print the analogic value on the display
	amebi.PrintDecimalNumber(amebi.analogic_input);

	// Print the analogic value in binary format (1/64 reduction)
	amebi.BitmaskLed((amebi.analogic_input >> 6));	

}