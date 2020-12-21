/*******************************************************************************

	Arduino Multifunctional Expansion Board Interface
	Ver 0.3.0
	
	Proyecto iniciado el 16-12-2020
	
	(cc) 2020 por Cesar Rincon
	
	nightfoxandco.com
	contact@nightfoxandco.com

	Arduino Multifunctional Expansion Board Interface
    se distribuye bajo la licencia CREATIVE COMMONS
	"Attribution-NonCommercial 4.0 International"
	https://creativecommons.org/licenses/by-nc/4.0/
	
	SONIDO

*******************************************************************************/



/*** Includes ***/
// Arduino
#include <Arduino.h>
// Includes del proyecto
#include "amebi_sound.h"




/*** Constructor ***/
AmebiSound::AmebiSound() {	
}



/*** Destructor ***/
AmebiSound::~AmebiSound() {
}



/*** Al iniciar el objeto ***/
void AmebiSound::Boot() {

	// Prepara el PIN del BUZZER
	pinMode(PIN_BUZZER, OUTPUT);

	// Propiedades
	status = false;
	timer = -1;

}



/*** Actualizacion del objeto ***/
void AmebiSound::Update() {

	if (status) {
		if (timer != -1) {
			if (millis() >= timer) {
				status = false;
				timer = -1;
			}
		}
	}

	digitalWrite(PIN_BUZZER, !status);

}


/*** Cambia el estado del buzzer ***/
void AmebiSound::SetBuzzer(bool enable) {

	status = enable;
	if (!status) timer = -1;

}



/*** Devuelve el estado del Buzzer ***/
bool AmebiSound::GetBuzzer() {

	return status;

}



/*** Emite un tono ***/
void AmebiSound::PlayTone(int32_t duration) {

	if (duration < 0) return;

	timer = millis() + duration;
	status = true;

}



/*** Emite un pitido corto (BEEP) ***/
void AmebiSound::Beep() {

	PlayTone(beep_duration);

}
