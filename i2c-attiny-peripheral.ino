#include <Wire.h>

// Use port/pin references (as recommened for ATTinyCore 1.4.0+)
#define ADC	PIN_PB4
#define OUT PIN_PB1

volatile word readValue = 0;

void setup() {
	Wire.begin(0x15);
	Wire.onRequest(wireRequest);
	pinMode(1, OUTPUT);
}

void loop() {
	readValue = analogRead(ADC);
	analogWrite(OUT, map(readValue,0,1023,0,255));
}

void wireRequest() {
	byte data[] = {highByte(readValue), lowByte(readValue)};
	Wire.write(data,2);
}

