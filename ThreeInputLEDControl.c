//Control LEDS with Three Inputs:
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




