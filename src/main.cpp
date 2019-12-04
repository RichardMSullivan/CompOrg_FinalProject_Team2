#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <softTone.h>
#include <unistd.h>


using namespace std;
#define lazer 3
#define buzzer 12

int main(){
    wiringPiSetupPhys();    
    
    pinMode(lazer,INPUT); 
    pinMode(buzzer,OUTPUT);
//    softToneCreate(buzzer);
//    pinMode(buzzer,PWM_OUTPUT);  
    
    bool lazer_state = 0;
    bool lazer_state_old = 0;
    
    digitalWrite(buzzer,0);

    while(true){
       delay(50);
       
       lazer_state = digitalRead(lazer);

       cout <<   "lazer_state:     "<< lazer_state
            << "\nlazer_state_old: " << lazer_state_old 
            << endl;

       if (lazer_state != lazer_state_old){
           
           lazer_state_old = lazer_state;
           
           if (lazer_state_old == 0){
                digitalWrite(buzzer,0);
    //            pwmWrite(buzzer,2);

                cout << "buzzer on!"<< endl;
           }
           else {
               digitalWrite(buzzer,1);
               //pwmWrite(buzzer,0);
               
               cout << "buzzer off!" << endl;
           }
       }
    }

    return 0 ;
}
