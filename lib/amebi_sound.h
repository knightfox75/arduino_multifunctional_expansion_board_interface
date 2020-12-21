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



#ifndef __AMEBI_SOUND_H
#define __AMEBI_SOUND_H



/*** Includes ***/
// Arduino
#include <Arduino.h>
// Proyecto



/*** Definicion de la clase ***/
class AmebiSound {
	
	public:
	
		// Constructor
		AmebiSound();
		
		// Destructor
		~AmebiSound();

		// Cambia el estado del Buzzer
		void SetBuzzer(bool enable);

		// Devuelve el estado del Buzzer
		bool GetBuzzer();

		// Emite un tono
		void PlayTone(int32_t duration);

		// Emite un pitido corto (BEEP)
		void Beep();



	protected:

		// Codigo inicial
        void Boot();
		
		// Ejecuta regularmente
		void Update();
		
	
	
	private:

		// Configuracion
		const int32_t beep_duration = 100;		// Duracion del tono "BEEP"

		// Definicion del PIN del BUZZER
		const uint8_t PIN_BUZZER = 3;

		// Control del estado del Buzzer
		bool status;		// Estado
		int32_t timer;		// Control del tiempo de actividad
		
};



#endif
