#ifndef _MESSAGE_UTIL_H_
#define _MESSAGE_UTIL_H_

#include <Arduino.h>
#include "SO1602AWWB.h"

class MessageUtil {
	public:
		MessageUtil(SO1602AWWB*);
		void say1(String s, uint8_t wait);
		void say2(String s, uint8_t wait);
		void clear(uint8_t wait);
	private:
		SO1602AWWB* oled;
};

#endif