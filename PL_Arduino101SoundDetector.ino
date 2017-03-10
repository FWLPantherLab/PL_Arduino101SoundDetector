const int Rled = 5;
const int Gled = 6;
const int Bled = 9;
const int soundPin = 0;

int sound;
int colorIndex = 0;

void setColor(int red, int green, int blue){
  analogWrite(Rled, red);
  analogWrite(Gled, green);
  analogWrite(Bled, blue);
}

void rainbowFade(){
  int d = 5;
  for (int i = 0; i <= 255; i++){
    setColor(i,0,0);
    delay(d);
  }
  for (int i = 0; i <= 255; i++){
    setColor(255,i,0);
    delay(d);
  }
  for (int i = 255; i >= 0; i--){
    setColor(i,255,0);
    delay(d);
  }
  for (int i = 0; i <= 255; i++){
    setColor(0,255,i);
    delay(d);
  }
  for (int i = 255; i >= 0; i--){
    setColor(0,i,255);
    delay(d);
  }
  for (int i = 0; i <= 255; i++){
    setColor(i,0,255);
    delay(d);
  }
  for (int i = 255; i >= 0; i--){
    setColor(255,0,i);
    delay(d);
  }
}

void changeColor() {
  switch(colorIndex) {
    case 0:
      setColor(255, 0, 0);  // red
      break;
    case 1:
      setColor(0, 255, 0);  // green
      break;
    case 2:
      setColor(0, 0, 255);  // blue
      break;
    case 3:
      setColor(255, 255, 0);  // yellow
      break;
    case 4:
      setColor(80, 0, 80);  // purple
      break;
    case 5:
      setColor(0, 255, 255);  // aqua
      break;
    default:
      setColor(0,0,0); //default off
      break;
  }
}

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(Rled, OUTPUT);
  pinMode(Gled, OUTPUT);
  pinMode(Bled, OUTPUT);
  changeColor();
}

void loop() {
  sound = analogRead(soundPin);
  Serial.println(sound);
  if (sound > 300) {
    rainbowFade();
    changeColor();
  }
  else if (sound > 100) {
    colorIndex++;
    if (colorIndex > 5) colorIndex = 0;
    changeColor();
    delay(500);
  }
  
  
}



