#include <Wire.h>

word readValue = 0;

void setup() {
	Wire.begin(0x15);
	Wire.onRequest(wireRequest);
	pinMode(1, OUTPUT);
}

void loop() {
	readValue = analogRead(A2);
	analogWrite(1, map(readValue,0,1023,0,255));
}

void wireRequest() {
	byte data[] = {highByte(readValue), lowByte(readValue)};
	Wire.write(data,2);
}

