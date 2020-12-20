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
	
	LEDS

*******************************************************************************/



/*** Includes ***/
// Arduino
#include <Arduino.h>
// Includes del proyecto
#include "amebi_led.h"




/*** Constructor ***/
AmebiLed::AmebiLed() {	
}



/*** Destructor ***/
AmebiLed::~AmebiLed() {
}



/*** Al iniciar el objeto ***/
void AmebiLed::Boot() {

	// Pinouts de los LEDS
	for (uint8_t id = 0; id < 4; id ++) pinMode(PIN_LED[id], OUTPUT);

}



/*** Actualizacion del objeto ***/
void AmebiLed::Update() {

}



/*** Cambia el estado de un LED ***/
void AmebiLed::SetLed(uint8_t led_id, bool status) {

	if (led_id == LED_ALL) {
		for (uint8_t id = 0; id < 4; id ++) {
			digitalWrite(PIN_LED[id], !status);
			led_status[id] = status;	
		}
	} else if (led_id < 4) {
		digitalWrite(PIN_LED[led_id], !status);
		led_status[led_id] = status;
	}

}



/*** Ilumina los leds segun el bitmask dado ***/
void AmebiLed::BitmaskLed(uint8_t bitmask) {

	bool status;
	for (uint8_t i = 0; i < 4; i ++) {
		status = ((bitmask >> i) & 0x01) ? true:false;
		SetLed(i, status);
	}

}



/*** Devuelve el estado de un LED ***/
bool AmebiLed::GetLed(uint8_t led_id) {

	if (led_id >= 4) return false;

	return led_status[led_id];

}
