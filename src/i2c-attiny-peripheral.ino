#include <Arduino.h>
#include <Wire.h>

// Use port/pin references (as recommened for ATTinyCore 1.4.0+)
#define ADC_PIN	PIN_PB4
#define OUT_PIN PIN_PB1

// The address of this device on the I2C bus
const int address = 0x15;

volatile word readValue = 0;
// PWM value 
volatile word writeValue = 0;

void setup() {
	Wire.begin(address);
	Wire.onRequest(wireRequest);
	Wire.onReceive(wireReceive);
	pinMode(OUT_PIN, OUTPUT);
}

void loop() {
	readValue = analogRead(ADC_PIN);
	analogWrite(OUT_PIN, writeValue);
}

// Send two bytes on the I2C interface
void wireRequest() {
	byte data[] = {highByte(readValue), lowByte(readValue)};
	Wire.write(data,2);
}

// Read a byte from the I2C bus and store it to be written to
// a PWM pin
void wireReceive(int numberOfBytesIn) {
	while(Wire.available()) {
		byte c = Wire.read();
		writeValue = word(c);
	}
}
