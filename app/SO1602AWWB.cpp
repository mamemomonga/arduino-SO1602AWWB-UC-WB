#include "SO1602AWWB.h"
#include <Wire.h>

// アドレス設定: SA0=LOW
#define SO_ADDR_SA0L  0x3C
// アドレス設定: SA0=HIGH
#define SO_ADDR_SA0H  0x3D

SO1602AWWB::SO1602AWWB() {
	sa0=0;
}

void SO1602AWWB::begin(bool _sa0) {
	sa0 = _sa0;
	delay(100);
	clear();
	home();
	display(true,false,false);
	clear();
	contrast(0xFF);
}

void SO1602AWWB::send_cmd(uint8_t cmd) {
	Wire.beginTransmission(sa0 ? SO_ADDR_SA0H : SO_ADDR_SA0L);
	Wire.write(0x00);
	Wire.write(cmd);
	Wire.endTransmission();	
	delay(40);
}

void SO1602AWWB::send_data(uint8_t data) {
	Wire.beginTransmission(sa0 ? SO_ADDR_SA0H : SO_ADDR_SA0L);
	Wire.write(0x40);
	Wire.write(data);
	Wire.endTransmission();	
	delay(1);
}

void SO1602AWWB::contrast(uint8_t cont) {
	send_cmd(0x2a); // Function RE=0: RE=1
	send_cmd(0x79); // OLED Characterization: SD=1
	send_cmd(0x81); // Set Contrast Control
	send_cmd(cont); // Contrast
	send_cmd(0x78); // OLED Characterization: SD=0
	send_cmd(0x28); // Function: 2C=高文字 28=ノーマル
}

void SO1602AWWB::write(char c) {
	send_data(c);
}

void SO1602AWWB::print(String s) {
	char buf[32];
	uint8_t len=s.length();
	s.toCharArray(buf,32);
	for(uint8_t i=0;i<len;i++) {
		write(buf[i]);
	}
}

void SO1602AWWB::home() {
	send_cmd(0x02);
	delay(2);
}
void SO1602AWWB::clear() {
	send_cmd(0x01);
	delay(20);
}

void SO1602AWWB::setCursor(uint8_t col, uint8_t row) {
 	send_cmd(0x80 | ((row * 0x20) + col));
	delay(2);
 }

void SO1602AWWB::display(bool display, bool cursor, bool blink) {
	send_cmd(
		(1<<3)
		| ((display ? 1 : 0 ) << 2)
		| ((cursor ? 1: 0) << 1)
		| ((blink ? 1: 0) << 0)
	);
	delay(2);
}