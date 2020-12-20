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
	
	Nucleo de Ejecucion

*******************************************************************************/



#ifndef __AMEBI_H
#define __AMEBI_H



/*** Includes ***/
// Arduino
#include <Arduino.h>
// Proyecto
#include "amebi_input.h"
#include "amebi_led.h"
#include "amebi_display.h"




/*** Definicion de la clase ***/
class Amebi: public AmebiInput, public AmebiLed, public AmebiDisplay {
	
	public:
	
		// Constructor
		Amebi();
		
		// Destructor
		~Amebi();

        // Codigo inicial
        void Boot();

		// Valores por defecto de todos los dispositivos
		void Reset();

		// Actualizacion de las E/S
		void Update();


		
	private:

	
};



#endif
