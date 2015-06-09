#include <stdio.h>
#include <wiringPi.h>

#define TRIG 5
#define ECHO 4
#define CLOSE 2
#define DISTANCE 3

int main(void)
{
	int A=0;
	int B=0;
	int temp;
	int distance = 0;
	int pulse = 0;

	if(wiringPiSetup() ==-1)
		return 1;
	pinMode(TRIG,OUTPUT);
	pinMode(ECHO,INPUT);
	pinMode(CLOSE,OUTPUT);
	pinMode(DISTANCE, OUTPUT);

	for(;;){
		digitalWrite(TRIG,LOW);
		usleep(2);
		digitalWirte(TRIG,HIGH);
		usleep(20);

		digitalWrite(TRIG,LOW);

		whiie(digitalRead(ECHO) == LOW);
			long startTaime = micros();
		while(digitalRead(ECHO) == HIGH);
			long travelTaime = micros() - startTime;

		int distance = travelTime/58;

		temp = B;
		B = distance;
		A = temp;

		if(A - B >= 10)
		{
			 digitalWrite(CLOSE,HIGH);
			digitalWrite(CLOSE, LOW);
		}
		else if(B - A >= 10)
		{
			 digitalWrite(DISTANCE, HIGH);
			digitalWrite(DISTANCE, LOW);
		}

		printf("Distance: %d cm \n", distance);
		delay(100);
	}

	return 0;
}

