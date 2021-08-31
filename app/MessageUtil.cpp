#include "MessageUtil.h"

MessageUtil::MessageUtil(SO1602AWWB* ol) {
	oled = ol;
}

void MessageUtil::say1(String s, uint8_t wait) {
	oled->clear();
	oled->home();
	oled->print(s);
	for(uint8_t i=0;i<wait;i++) {
		delay(1000);
	}
}
void MessageUtil::say2(String s, uint8_t wait) {
	oled->setCursor(0,1);
	oled->print(s);
	for(uint8_t i=0;i<wait;i++) {
		delay(1000);
	}
}
void MessageUtil::clear(uint8_t wait) {
	oled->clear();
	for(uint8_t i=0;i<wait;i++) {
		delay(1000);
	}
}
