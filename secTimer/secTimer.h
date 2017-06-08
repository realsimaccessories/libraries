/*
	secTimer.h - A simple timer to get the running of time computing single seconds

	Written by Leonardo Miliani <leonardo AT leonardomiliani DOT com>

	History:
	
	v. 1.0.0: added compatibility with Arduino IDE >= 1.6.7 - first stable release
	(for a complete history of the previous versions, see the README file)

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public
	License as published by the Free Software Foundation; either
	version 3.0 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/


#ifndef secTIMER_H
#define secTIMER_H


//library version
#define secTIMER_VERSION 100


//this library is compatible both with Arduino <=0023 and Arduino >=100
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


//check if the micro is supported
#if defined (__AVR_ATmega48__) || defined (__AVR_ATmega88__) || defined (__AVR_ATmega168__) || defined (__AVR_ATmega328__) || defined (__AVR_ATmega48P__) || defined (__AVR_ATmega88P__) || defined (__AVR_ATmega168P__) || defined (__AVR_ATmega328P__)
#define ATMEGAx8
#elif defined (__AVR_ATtiny25__) || defined (__AVR_ATtiny45__) || defined (__AVR_ATtiny85__)
#define ATTINYx5
#elif defined (__AVR_ATmega8__) || defined (__AVR_ATmega8A__)
#define ATMEGA8
#elif defined (__AVR_ATtiny24__) || defined (__AVR_ATtiny44__) || defined (__AVR_ATtiny84__)
#define ATTINYx4
#elif defined (__AVR_ATmega640__) || defined (__AVR_ATmega1280__) || defined (__AVR_ATmega1281__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega2561__)
#define ATMEGAx0
#elif defined (__AVR_ATmega344__) || defined (__AVR_ATmega344P__) || defined (__AVR_ATmega644__) || defined (__AVR_ATmega644P__) || defined (__AVR_ATmega644PA__) || defined (__AVR_ATmega1284P__)
#define ATMEGAx4
#elif defined (__AVR_ATtiny2313__) || defined (__AVR_ATtiny4313__)
#define ATTINYx313
#elif defined (__AVR_ATmega32U4__)
#define ATMEGAxU
#if (F_CPU!=16000000UL)
#error Sorry, Atmega32U4 is supported only at 16 MHz
#endif
#else
#error Sorry, microcontroller not supported!
#endif


//check if the frequency is supported
#if ((F_CPU != 1000000UL) && (F_CPU != 4000000UL) && (F_CPU != 8000000UL) && (F_CPU != 16000000UL))
#error Clock frequency not supported
#endif


class secTimer {
	public:
		//public methods
		secTimer();
		void startTimer();
		void stopTimer();
		unsigned long readTimer();

	private:
		//private methods
		void setTimer();
		//private variables
		boolean _isRunning;
};

#endif
