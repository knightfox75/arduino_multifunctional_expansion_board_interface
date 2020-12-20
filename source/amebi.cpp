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
	
	Nucleo de Ejecucion

*******************************************************************************/



/*** Includes ***/
// Arduino
#include <Arduino.h>
// Includes del proyecto
#include "amebi.h"
#include "amebi_input.h"
#include "amebi_led.h"
#include "amebi_display.h"



/*** Constructor ***/
Amebi::Amebi() {	
}



/*** Destructor ***/
Amebi::~Amebi() {
}



/*** Procesos iniciales de la libreria ***/
void Amebi::Boot() {

	// Metodos heredados
	AmebiInput::Boot();
	AmebiLed::Boot();
	AmebiDisplay::Boot();

	// Valores iniciales
	Reset();
	
}



/*** Valores iniciales de la libreria ***/
void Amebi::Reset() {

	// Estados de los leds
	AmebiLed::SetLed(LED_ALL, false);
	// Borra el display
	AmebiDisplay::CleanDisplay();

}



/*** Actualizacion de las E/S ***/
void Amebi::Update() {

	// Contenido del display
	AmebiDisplay::Update();

}
