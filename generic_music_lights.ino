/* Arduino project to use the GPIO Pins */
/* Relay connected to pins will switch on/off the lights connected to them */
#define PIN01 0
#define PIN02 1
#define PIN03 2
#define PIN04 3
#define PIN05 4
#define PIN06 5
#define PIN07 6
#define PIN08 7
#define PIN09 8
#define PIN10 9
#define PIN11 10
#define PIN12 11
#define PIN13 12
#define LED 13
/* Delays to switch on/off lights based on music played, timing seconds from previous state starting from zero */
/* Music #1 */
/*
#define DELAY01 70
#define DELAY02 61
#define DELAY03 28
#define DELAY04 87
#define DELAY05 36
#define DELAY06 17
#define DELAY07 45
#define DELAY08 18
#define DELAY09 47
#define DELAY10 32
#define DELAY11 29
#define DELAY12 119
*/
/* Music #2 */
#define DELAY01 52
#define DELAY02 50
#define DELAY03 18
#define DELAY04 43
#define DELAY05 19
#define DELAY06 30
#define DELAY07 31
#define DELAY08 17
#define DELAY09 37
#define DELAY10 20
#define DELAY11 21
#define DELAY12 108

void setup()
{
  for(int i=0;i<14;i++){
    pinMode(i, OUTPUT);
  }
}

void rotateall()
{
  for(int PIN=1;PIN<13;PIN++){
    digitalWrite(PIN, HIGH);
    delay(1000);
    digitalWrite(PIN, LOW);
  }
}

void lightLED()
{
    digitalWrite(LED, HIGH);
    //delay(500);
    digitalWrite(LED, LOW);
}

void activate(int pin, int dly)
{
    digitalWrite(pin, HIGH);
    lightLED();
    for(int i=0;i<11;i++){
    	delay(dly*100);
    }
    digitalWrite(pin, LOW);
    lightLED();
}

void lowerall()
{
  for(int PIN=0;PIN<13;PIN++){
    //digitalWrite(PIN, HIGH);
    //delay(1000);
    digitalWrite(PIN, LOW);
  }
}

void loop()
{
/*
  for(int PIN=8;PIN<14;PIN++){
    digitalWrite(PIN, HIGH);
    delay(1000);
    digitalWrite(PIN, LOW);
    delay(1000);
  }
*/
	//lowerall();
	//delay(1000);
	//rotateall();
	activate(PIN02,DELAY01);
	activate(PIN03,DELAY02);
	activate(PIN04,DELAY03);
	activate(PIN05,DELAY04);
	activate(PIN06,DELAY05);
	activate(PIN07,DELAY06);
	activate(PIN08,DELAY07);
	activate(PIN09,DELAY08);
	activate(PIN10,DELAY09);
	activate(PIN11,DELAY10);
	activate(PIN12,DELAY11);
	activate(PIN13,DELAY12);
	rotateall();
        while(1) {
		lightLED();
	};
}
