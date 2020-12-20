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



#ifndef __AMEBI_INPUT_H
#define __AMEBI_INPUT_H



/*** Includes ***/
// Arduino
#include <Arduino.h>
// Proyecto



/*** Definicion de la clase ***/
class AmebiInput {
	
	public:
	
		// Constructor
		AmebiInput();
		
		// Destructor
		~AmebiInput();

		// Estructura de los pulsadores
		struct {
			bool held;
			bool down;
			bool up;
		} button[3];
		const uint8_t BUTTON_1 = 0;
		const uint8_t BUTTON_2 = 1;
		const uint8_t BUTTON_3 = 2;

		// Valor de la entrada analogica
		int16_t analogic_input;

		// Efectua la lectura de las entradas
		void ReadInputs();


	protected:

		// Codigo inicial
        void Boot();
		
		// Ejecuta regularmente
		void Update();
		
	
	
	private:

		// Definicion de los puertos de lectura de los pulsadores
		const uint8_t PIN_BUTTON[3] = {1, 2, 3};
		// Estado "last" de los pulsadores
		bool last[3];
		// Lectura de los botones
		void ReadButtons();



		
};



#endif
