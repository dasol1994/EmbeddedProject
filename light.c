#include <stdio.h>
#include <wiringPi.h>

#define L1 12
#define L2 6
#define L3 13
#define L4 10
#define L5 14
#define L6 11

int POW(int num)
{
    int result = 1;
    for(int i = 0; i < num; i++){
	result *= 10;
    }
    return result;
}

void PRINT(int num)
{
	switch(num){
	    case 1:
	    	pinMode(L1, HIGH);
		OFF();
	    break;

	    case 2:
	    	pinMode(L1, HIGH);
   	  	pinMode(L3, HIGH);
		OFF();
	    break;

	    case 3:
	    	pinMode(L1, HIGH);
    	   	pinMode(L2, HIGH);
		OFF();
	    break;

	    case 4:
	    	pinMode(L1, HIGH);
    	   	pinMode(L2, HIGH);
  	    	pinMode(L4, HIGH);
		OFF();
	    break;

    	    case 5:
	    	pinMode(L1, HIGH);
  	    	pinMode(L4, HIGH);
		OFF();
	    break;

	    case 6:
	    	pinMode(L1, HIGH);
    	   	pinMode(L2, HIGH);
   	  	pinMode(L3, HIGH);
		OFF();
	    break;

	    case 7:
	    	pinMode(L1, HIGH);
    	   	pinMode(L2, HIGH);
   	  	pinMode(L3, HIGH);
  	    	pinMode(L4, HIGH);
		OFF();
	    break;

	    case 8:
	    	pinMode(L1, HIGH);
   	  	pinMode(L3, HIGH);
  	    	pinMode(L4, HIGH);
		OFF();
	    break;

	    case 9:
    	   	pinMode(L2, HIGH);
   	  	pinMode(L3, HIGH);
		OFF();
	    break;

	    case 0:
    	   	pinMode(L2, HIGH);
   	  	pinMode(L3, HIGH);
  	    	pinMode(L4, HIGH);
		OFF();
	    break;

	    default:
	    break;
	}
    }
}

void OFF()
{
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
    digitalWrite(L3, LOW);
    digitalWrite(L4, LOW);
    digitalWrite(L5, LOW);
    digitalWrite(L6, LOW);
}

int main(void)
{
    int num = 0;
    int I,j;
    int temp, temp2;
    int count = 1;

    pinMode(L1, OUTPUT);
    pinMode(L2, OUTPUT);
    pinMode(L3, OUTPUT);
    pinMode(L4, OUTPUT);
    pinMode(L5, OUTPUT);
    pinMode(L6, OUTPUT);

    for(;;){
	printf("num : ");
	scanf("%d, &num);
	
        pinMode(L2, HIGH);
        pinMode(L4, HIGH);
        pinMode(L5, HIGH);
        pinMode(L6, HIGH);
	OFF();

	temp = num;
	for(;;){
	    if(temp/10 == 0)
	        break;
	    else{
		temp /= 10;
		count++;
	    }
	}
	
	temp = num;
	temp2 = temp;

	for(int i =count; i > 0; i--){
	    temp = temp / POW(i-1);
	    PRINT(temp);
	    temp = temp2 - temp*POW(i-1);
	    temp2 = temp;
	}

    return 0;
}