#define BELL_INPUT 6
#define FEED_INPUT 7
#define BELL_PIN 8
#define CLICK_PIN 9
#define LED_PIN 10


#include <Servo.h>

Servo myservo;  
int pos = 0;    
int upper = 130;
int lower = 90;
bool markingTime = 0;
long unsigned markTime;



void setup() {
  Serial.begin(9600);
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
  myservo.write(upper);
  myservo.detach();
  pinMode(BELL_INPUT, INPUT);
  pinMode(FEED_INPUT, INPUT);
pinMode(BELL_PIN, OUTPUT);
pinMode(CLICK_PIN, OUTPUT);
pinMode(LED_PIN, OUTPUT);

}

void loop() {

if (digitalRead(7) == HIGH){
feedKittyTimes(1);
}

if (digitalRead(6) == HIGH){
ringKitty();
}




}

void ringKitty(){
  Serial.println("ringing");

digitalWrite(LED_PIN, HIGH);
ringBell(2);
delay(200);
ringBell(4);
//delay(400);
//clicketyClick();
//playSong();
//delay(1000);
//digitalWrite(LED_PIN, LOW);

}
void ringBell(int i){
  for (int x = 0; x < i; x++){
    digitalWrite(BELL_PIN, HIGH);
    delay(10);
    digitalWrite(BELL_PIN, LOW);
    delay(20);
  }
}

void clicketyClick(){
  digitalWrite(CLICK_PIN, HIGH);
  delay(100);
  digitalWrite(CLICK_PIN, LOW);
  delay(100);
  digitalWrite(CLICK_PIN, HIGH);
  delay(100);
  digitalWrite(CLICK_PIN, LOW);
  delay(100);
  
}

void playSong(){

  tone(8, 900);
  delay(120);
  tone(8, 700);
  delay(120);
  tone(8, 900);
  delay(120);
  tone(8, 700);
  delay(120);
  noTone(8);
}


  
  void feedKittyTimes(int f){
    for (int x = 0; x < f; x++){
        Serial.println("feeding");
myservo.attach(3);
myservo.write(lower);
delay(400);
myservo.write(upper);
delay(400);
myservo.detach();
//  myservo.attach(3);
//  for (pos = upper; pos >= lower; pos -= 1) {
//    myservo.write(pos);              
//    delay(10);                      
//  }
//      myservo.detach();
//      myservo.attach(3);
//    delay(50);
//      for (pos = lower; pos <= upper; pos += 1) { 
//    myservo.write(pos);              
//    delay(10);                       
//  }
//  delay(100);
//    myservo.detach();
    }
  }


