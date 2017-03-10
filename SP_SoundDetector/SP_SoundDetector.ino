/*
SparkFun Inventor's Kit 
Example sketch 15

SOUND DETECTOR

Use the sound detector to measure the volume of the surrounding area and change the 
color of an RGB based on that volume.
*/

 //pin variables
const int redPin = 5;
const int greenPin = 6;
const int bluePin = 9;
const int soundPin = 0;

//variables for storing raw sound and scaled value
int sound;
int scale;

uint32_t timer;

void setup()
{
 //start the serial port a@ 9600bps
 Serial.begin(9600);
 //set RGB pins to OUTPUT
 pinMode(redPin, OUTPUT);
 pinMode(greenPin, OUTPUT);
 pinMode(bluePin, OUTPUT);
 timer = millis();
}

void loop()
{
  int oldScale = scale;
 //read and store the audio from Envelope pin
 sound = analogRead(soundPin);
 //map sound which in a quiet room a clap is 300
 //from 0 to 3 to be used with switch case
 scale = map(sound, 0, 300, 0, 3);
 if (scale > 3) scale = 3;
 if (scale > 0) timer=millis();
 if (millis()-timer < 1000 && scale <= oldScale){
  if (oldScale > 0) {
    scale = oldScale;
  }
 }
 //print values over the serial port for debugging
 Serial.print(sound);
 Serial.print("   ");
 Serial.println(scale);

 
 //switch case on scaled value
switch (scale)
{
//if 0 RGB = Blue
case 0:
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, HIGH);
  break;
//if 1 RGB = Green  
case 1:
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, LOW);
  break;
//if 2 RGB = Yellow  
case 2:
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, LOW);
  break;
//if 3 RGB = Red
case 3:
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  break;
//default off
default:
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  break;
 }
}

