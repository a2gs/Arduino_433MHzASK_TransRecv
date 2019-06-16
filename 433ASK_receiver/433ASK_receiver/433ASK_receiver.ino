#include <RH_ASK.h>
#include <SPI.h>

/*
 * Using lib: http://www.airspayce.com/mikem/arduino/RadioHead/
 * http://www.airspayce.com/mikem/arduino/RadioHead/classRH__ASK.html
 * 
 * PIN11  - Data
 * A[1-4] - LED OUTPUT
 */

RH_ASK driver;

void setup()
{
	Serial.begin(9600);
		if (!driver.init()) Serial.println("init failed");

	pinMode(A1, OUTPUT);
	pinMode(A2, OUTPUT);
	pinMode(A3, OUTPUT);
	pinMode(A4, OUTPUT);

	digitalWrite(A1, LOW);
	digitalWrite(A2, LOW);
	digitalWrite(A3, LOW);
	digitalWrite(A4, LOW);
}

void loop()
{
	uint8_t buf[1];
	uint8_t buflen = sizeof(buf);
	if(driver.recv(buf, &buflen)){
		Serial.print("Recv: ");
		Serial.println((char*)buf);         
	}

	if     (buf[0] == '1') digitalWrite(A1, HIGH);
	else if(buf[0] == '2') digitalWrite(A2, HIGH);
	else if(buf[0] == '3') digitalWrite(A3, HIGH);
	else if(buf[0] == '4') digitalWrite(A4, HIGH);
	else if(buf[0] == '0'){
		digitalWrite(A1, LOW);
		digitalWrite(A2, LOW);
		digitalWrite(A3, LOW);
		digitalWrite(A4, LOW);
	}
}
