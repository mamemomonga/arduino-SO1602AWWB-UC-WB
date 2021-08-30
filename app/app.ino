#include "SO1602AWWB.h"
#include <Wire.h>

SO1602AWWB oled;

uint16_t uptime;

void setup() {
	pinMode(LED_BUILTIN, OUTPUT);

	// i2c初期化
	Wire.begin();

	// OLED初期化 SA0=LOW
	oled.begin(false);

	// ディスプレイ: ON カーソル: ON 点滅: ON
	oled.display(true,true,true);

	digitalWrite(LED_BUILTIN, HIGH);
	oled.print("HELLO WORLD!"); // 文字を表示
	oled.setCursor(0,1); // 2行目0列
	oled.print(" It's SO1602AWWB"); // 文字を表示

	delay(5000);
	digitalWrite(LED_BUILTIN, LOW);

	// ディスプレイ: ON カーソル: ON 点滅: ON
	oled.display(true,false,false);
	oled.clear(); // 画面削除
	oled.home(); // ホームに移動
	oled.contrast(128); // 明るさは半分

	oled.print("Uptime:"); // 文字を表示

	uptime=0;
}

void loop() {

	uint32_t sec = (millis()/1000);
	if(sec > uptime) {
		digitalWrite(LED_BUILTIN, HIGH);
		oled.setCursor(8,1); // カーソルを2行目8桁目に移動
		oled.print(String(sec)); // 数字を表示
		digitalWrite(LED_BUILTIN, LOW);
		uptime = sec;
	}
}
