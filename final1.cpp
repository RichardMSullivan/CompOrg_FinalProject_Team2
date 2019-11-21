#include <wiringPi.h>
#include <softPwm.h>
#include <iostream>
using namespace std;

#define LDR 7
#define buzzer 12
void test(void);
int main(){
    wiringPiSetupP();
    pinMode(LDR, INPUT);
    //pinMode(buzzer, PWM_OUTPUT);
    pullUpDnControl(LDR,PUD_DOWN);
    while(1){
        test();
    }
    return 0;
}

void test(){
	


    digitalWrite(LDR, LOW);
    delay(5);
	
    pinMode(LDR, OUTPUT);
	printf("%d\n", digitalRead(LDR));
	
//	if (digitalRead(LDR) == 0){
//		pwmWrite(buzzer,100);
//	}
//	else{
//		pwmWrite(buzzer,0);
//
}
