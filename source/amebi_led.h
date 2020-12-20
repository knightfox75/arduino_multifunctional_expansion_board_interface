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
	
	LEDS

*******************************************************************************/



#ifndef __AMEBI_LED_H
#define __AMEBI_LED_H



/*** Includes ***/
// Arduino
#include <Arduino.h>
// Proyecto



/*** Definicion de la clase ***/
class AmebiLed {
	
	public:
	
		// Constructor
		AmebiLed();
		
		// Destructor
		~AmebiLed();

		// Cambia el estado de un led
		void SetLed(uint8_t led_id, bool status);

		// Ilumina los leds segun el bitmask dado
		void BitmaskLed(uint8_t bitmask);

		// Devuelve el estado de un led
		bool GetLed(uint8_t led_id);

		// ID's de los LEDS
		const int8_t LED_D1 = 0;
		const int8_t LED_D2 = 1;
		const int8_t LED_D3 = 2;
		const int8_t LED_D4 = 3;
		const int8_t LED_ALL = 4;



	protected:

		// Codigo inicial
        void Boot();
		
		// Ejecuta regularmente
		void Update();
		
	
	
	private:

		// Definicion de los PINS de los LEDS
		const uint8_t PIN_LED[4] = {13, 12, 11, 10};
		
		// Estado de los LEDS
		bool led_status[4];

		
};



#endif
