/*
Control LEDS with Three Inputs:
Assignment:
ASSIGNMENT: 

Write a program that uses a SPDT switch, a photoresistor, and a button.

The switch will change between the photoresistor and a button.
	Setup: 6 lights in a row: red, blue, green, yellow, red, blue
	
	When the switch is flipped, the green light will light up.  

	When the button is pressed, the green light will turn off and the yellow light will turn on 
for 1 seconds.  Then the yellow light will turn off and the red light will turn on for 3 
seconds.  Then the green light will turn on until the button is pressed again.
Setup:	on:                green				off:red, blue,            yellow, red, blue	
1st: 	on:  	                     yellow			off:red, blue, green              red, blue
2nd: 	on:			          red		off:red, blue, green, yellow,         blue                               
3rd: 	on:                green				off:red, blue,            yellow, red, blue


The photoresistor will begin blinking lights when it is dark, and turn off all lights when it is light.
	
Setup:   6 lights in a row: red, blue, green, yellow, red, blue

Turn on the first red and blue together, then turn on green and yellow together, then turn 
on the last red and blue together.  Turn off the first red, then blue, green, yellow, red, blue.  Repeat.
Setup	on: 						off:red, blue, green, yellow, red, blue
1st: 	on: red, blue					off:                green, yellow, red, blue
2nd: 	on: red, blue, green, yellow			off:                                       red, blue
3rd: 	on: red, blue, green, yellow, red, blue	off: 
4th: 	on:        blue, green, yellow, red, blue		off: red
5th:	on:                 green, yellow, red, blue	off: red, blue
6th: 	on:         	          yellow, red, blue	off: red, blue, green
7th: 	on:			          red, blue	off: red, blue, green, yellow
8th: 	on:				      blue	off: red, blue, green, yellow, red
9th:	on: 						off: red, blue, green, yellow, red, blue



Use a loop to turn the lights on and off.  

Use a loop to setup your lights as outputs.

*/

int ledPins[] = {4, 5, 6, 7, 8, 10};
// 4 = red, 5 = blue, 6 = green, 7 = yellow, 8 = red, 9 = blue

const int photoPin = A0;
const int buttonPin = 3;
const int switchPin = 2;

int lightCal; //the base light value that the photoresistor will use to determine when it is dark and when it is light
int lightVal; //the current light value that will be compared to the base light value
int buttonState; //will tell if the button is pressed on not
int switchVal; //will tell if the switch is slid or not

void setup(){
  int index; //another variable to track for loop
  for(index = 0; index <=5; index++){
    pinMode(ledPins[index], OUTPUT);
  }
  pinMode(photoPin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(switchPin, INPUT);

  lightCal = analogRead(photoPin); //taking a single reading from the light sensor and storing it as the LightCal value
}

void loop(){
  lightVal = analogRead(photoPin); //reading the photoPin value to determine the current light value (compared to LightCal to determine whether it is darker or brighter)
  switchVal = digitalRead(switchPin); //reading the switchPin value (whether it is switched on or off) to determine what should happen to the ledPins
   //reading the buttonPin value (whether it is pressed down or not) to determine what should happen to the ledPins

//if the switchVal is turned on, the green light should turn on
  if(switchVal == HIGH){
    digitalWrite(6, HIGH);
    buttonState = digitalRead(buttonPin);
    //if the button is pressed down/turned on, run void button
    if(buttonState == LOW){
      button();
      }
  }
  else{
      digitalWrite(6, LOW);
      if(lightVal < lightCal - 50){
        photoresistor();
      }
  }

}

void photoresistor(){
   int indexx;
    for(indexx = 0; indexx <= 5; indexx++){
      digitalWrite(ledPins[indexx], HIGH);
      digitalWrite(ledPins[indexx] + 1, HIGH);
      indexx = indexx + 1;
        if(indexx==5){
          digitalWrite(ledPins[indexx], HIGH);
          digitalWrite(ledPins[indexx] + 2, HIGH);
          //digitalWrite(10, HIGH); //since we can’t plug a pin into pin 9, this step must be added
        }
      delay(500);
    }
    for(indexx = 0; indexx <= 5; indexx++){
      digitalWrite(ledPins[indexx], LOW);
      delay(500);
    }
    delay(500);
    int index;
    for(index = 0; index <= 5; index++){
      digitalWrite(ledPins[index], LOW);
      delay(500);
    }
  }


//in this void, yellow will turn on, then red, then green
 void button(){
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(1000);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    delay(3000);
    digitalWrite(8, LOW);
    digitalWrite(6, HIGH);
 }




