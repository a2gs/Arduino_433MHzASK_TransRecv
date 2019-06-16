#include <RH_ASK.h>
#include <SPI.h>

/*
 * Using lib: http://www.airspayce.com/mikem/arduino/RadioHead/
 * http://www.airspayce.com/mikem/arduino/RadioHead/classRH__ASK.html
 * 
 * PIN12  - Data
 * A[1-4] - Pushbutton INPUT
 */

RH_ASK driver;

void setup()
{
	Serial.begin(9600);

	if (!driver.init())
		Serial.println("init failed");

	pinMode(A1, INPUT);
	pinMode(A2, INPUT);
	pinMode(A3, INPUT);
	pinMode(A4, INPUT);
}

void loop()
{
	char *msg = NULL;

	if      (digitalRead(A1) == HIGH) msg = "1";
	else if (digitalRead(A2) == HIGH) msg = "2";
	else if (digitalRead(A3) == HIGH) msg = "3";
	else if (digitalRead(A4) == HIGH) msg = "4";
	else                              msg = "0";

	driver.send((uint8_t *)msg, strlen(msg));
	driver.waitPacketSent();
	
	Serial.println(msg);
	
	delay(100);
}
