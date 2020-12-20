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
	
	INPUT

*******************************************************************************/



/*** Includes ***/
// Arduino
#include <Arduino.h>
// Includes del proyecto
#include "amebi_input.h"




/*** Constructor ***/
AmebiInput::AmebiInput() {	
}



/*** Destructor ***/
AmebiInput::~AmebiInput() {
}



/*** Al iniciar el objeto ***/
void AmebiInput::Boot() {

	// Variables de control gestion de los pulsadores
	for (uint8_t id = 0; id < 3; id ++) {
		button[id].held = false;
		button[id].down = false;
		button[id].up = false;
		last[id] = false;
	}

}



/*** Lectura de todas las entradas ***/
void AmebiInput::ReadInputs() {

	// Lee los pulsadores
	ReadButtons();

	// Lee la entrada analogica
	analogic_input = analogRead(0);

}



/*** Actualizacion del objeto ***/
void AmebiInput::Update() {

}



/*** Lectura de los pulsadores ***/
void AmebiInput::ReadButtons() {
	
	for (uint8_t id = 0; id < 3; id ++) {
		if (analogRead(PIN_BUTTON[id]) < 512) {
			button[id].held = true;
		} else {
			button[id].held = false;
		}
		button[id].down = button[id].held & !last[id];
		button[id].up = !button[id].held & last[id];
		last[id] = button[id].held;
	}

}
