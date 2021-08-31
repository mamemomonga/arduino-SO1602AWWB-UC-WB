#include <Wire.h>

#include "SO1602AWWB.h"
#include "MessageUtil.h"
#include "Serifu.h"

SO1602AWWB oled;
MessageUtil message_util(&oled);

void setup() {
	pinMode(LED_BUILTIN, OUTPUT);

	// i2c初期化
	Wire.begin();

	// OLED初期化 SA0=LOW
	oled.begin(false);

	// ディスプレイ: ON カーソル: ON 点滅: ON
	oled.display(true,true,true);
	oled.contrast(0xFF); // 明るさは最大

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

}

void loop() {

	digitalWrite(LED_BUILTIN, HIGH);
	// カタカナのメッセージを表示
	Serifu::greeting(&message_util);
	digitalWrite(LED_BUILTIN, LOW);

	oled.clear();
	oled.home();
	oled.print("Uptime:");

	oled.setCursor(8,1); // カーソルを2行目8桁目に移動
	uint16_t sec=millis()/1000;
	oled.print(String(sec)); // 数字を表示
	delay(3000);
}
