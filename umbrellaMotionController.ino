//Umbrella Motor Controller for an arduino
//Uses an L298 Motor Driver and 2 rocker switches
//to change directions
//By Christopher Lewis
//Checked in Wednesday, July 05, 2017


const int buttonEndStopTip = 11; //Pins for switch at the tip
const int buttonEndStopHandle = 12; // Pin for switch at the handle

int buttonStateEndStopTip = 0;
int buttonStateEndStopHandle = 0;

int enA = 10;
int in1 = 9;////Digital Pins are used because we only need to
int in2 = 8;////give signal to motor whether to rotate or not
int directionUp = true;

int pauseBetweenMovement = 5000;
void setup() {
  pinMode(buttonEndStopTip, INPUT_PULLUP);
  pinMode(buttonEndStopHandle, INPUT_PULLUP);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  analogWrite(enA, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

}

void loop() {

  buttonStateEndStopTip = digitalRead(buttonEndStopTip);
  buttonStateEndStopHandle = digitalRead(buttonEndStopHandle);

  if (buttonStateEndStopTip == LOW || buttonStateEndStopHandle == LOW) {
    pauseAndChangeDirection();
  }
}
void pauseAndChangeDirection(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(pauseBetweenMovement);
  directionUp = !directionUp;
  if (directionUp == true){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }else{
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
  delay(1000);//Delay to give the motor time to clear the button
}
