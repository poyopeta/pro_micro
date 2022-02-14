#include <SoftwareSerial.h>

int count = 0;

void setup() {
	Serial.begin(9600);
	pinMode(2, INPUT_PULLUP);
}

void loop() {
	if (digitalRead(2) == LOW) {
		Serial.println("hi from Pro Micro!");
		delay(500);
		count++;
	}
}
