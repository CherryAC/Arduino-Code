/*
 * Test Servo Speed - see how the pulse width of the servo affects its RPM (revolutions per minute)
 * Send a character from the Serial Monitor to the Arduino to make the
 * left servo run for 6 seconds. A tone will play after each test. 
 * servoLeft will start out with 1375 us pulses and increase by 25 us with each repetition, up to 1625 us. 
 * servoLeft will turn clockwise while servoRight will turn counterclockwise.
 */
#include <Servo.h> // Include servo library

Servo servoLeft; // Declare left servo signal
Servo servoRight; // Declare right servo signal
void setup() // Built in initialization block
{
 tone(4, 3000, 1000); // Play tone for 1 second
 delay(1000); // Delay to finish tone

 Serial.begin(9600); // Set data rate to 9600 bps
 servoLeft.attach(13); // Attach left signal to P13
 servoRight.attach(12); //Attach right signal to P12
}

void loop() // Main loop auto-repeats
{
 // Loop counts with pulseWidth from 1375 to 1625 in increments of 25.
 for(int pulseWidth = 1375; pulseWidth <= 1625; pulseWidth += 25)
 {
 Serial.print("pulseWidth = "); // Display pulseWidth value
 Serial.println(pulseWidth);
 Serial.println("Press a key and click"); // User prompt: type any character into the bar at the top 
 Serial.println("Send to start servo..."); //Click the Send Button
 while(Serial.available() == 0); // Wait for character
 Serial.read(); // Clear character
 Serial.println("Running...");
 servoLeft.writeMicroseconds(pulseWidth); // Pin13 servo speed = pulse
 //servoRight needs to go in the opposite direction of servoLeft
 servoRight.writeMicroseconds(-pulseWidth);
 delay(6000); // ..for 6 seconds
 servoLeft.writeMicroseconds(1500); // Pin 13 servo speed = stop
 servoRight.writeMicroseconds(1500); //Pin 12 servo speed = stop
 tone(4, 3500, 1000);
 }
} 
