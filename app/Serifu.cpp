// Shift_JISで保存すること
#include "Serifu.h"

void Serifu::greeting(MessageUtil* mu) {
	mu->say1("ｺﾝﾆﾁﾊ!",3);
	mu->clear(1);
	mu->say1("ｺﾞｷｹﾞﾝ",1);
	mu->say2(" ｲｶｶﾞ?",3);
	mu->clear(1);
}