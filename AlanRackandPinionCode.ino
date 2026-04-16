
const int topLimit = 12; //sets top limit switch pin
const int bottomLimit = 11; //sets bottom limit switch pin 
const int motorPin1 = 3; //pin for the rack and pinion motor
const int motorPin2 = 2; //pin for the rack and pinion motor
const int rpMotorSpeed = 255; //the speed of the rack and pinion motor from 0-255
const int ENA = 5;
bool rackMoving = false; //when true, rack will begin moving and will turn off once moved back to the original position

void setup() {
Serial.begin(9600); //this initializes the Serial Monitor so that I can see things on my computer screen
}

void runMission() {
      rackMoving = true;

if (rackMoving = true) {

  while (digitalRead(topLimit) != 1) {
    analogWrite(ENA,60);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  }

    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);

  delay(5000); //time for the diaper to stop and absorb water

  while (digitalRead(bottomLimit) != 1) {
    analogWrite(ENA,60);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
  }

   digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);


    rackMoving = false;
}
  
}

void moveRack(String rackDirection) {

  if(rackDirection = "Up") {
    while (digitalRead(topLimit) != HIGH) {
    digitalWrite(motorPin1, rpMotorSpeed * -1); }
  }

  if (rackDirection = "Down") {
    while (digitalRead(topLimit) != HIGH) {
    digitalWrite(motorPin1, rpMotorSpeed * -1); }
  }

}

void loop() {

  runMission();

delay(10000); 

}
