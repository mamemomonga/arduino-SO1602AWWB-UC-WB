#ifndef _SO1602AWWB_H_
#define _SO1602AWWB_H_

#include <Arduino.h>

class SO1602AWWB {
	public:
		SO1602AWWB();
		void begin(bool);
		void contrast(uint8_t);
		void write(char);
		void print(String);
		void home();
		void clear();
		void setCursor(uint8_t col, uint8_t row);
		void display(bool display, bool cursor, bool blink);
	private:
		bool sa0;
		void send_cmd(uint8_t);
		void send_data(uint8_t);
;
};

#endif