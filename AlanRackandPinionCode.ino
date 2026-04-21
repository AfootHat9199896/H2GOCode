
const int topLimit = 12; //sets top limit switch pin
const int bottomLimit = 13; //sets bottom limit switch pin 
const int motorPin1 = 4; //pin for the rack and pinion motor (Goes from arduino pin 4 to IN2) (Motor power to OUT1 and GND to OUT2 on HBRIDGE)
const int motorPin2 = 5; //pin for the rack and pinion motor (Goes from arduino pin 5 to IN1)
const int ENA = 3; 
const int ENAVoltage = 70; //voltage for the limit switch motor set from 0-255

const int waterAbsorbTime = 5000; //time in ms that water is absorbed

void setup() {
  pinMode(ENA,OUTPUT);
  pinMode(motorPin1,OUTPUT);
  pinMode(motorPin2,OUTPUT);
Serial.begin(9600); //this initializes the Serial Monitor so that I can see things on my computer screen
  delay(5000);

}


const int rpMotorSpeed = 255; //the speed of the rack and pinion motor from 0-255
bool rackMoving = false; //when true, rack will begin moving and will turn off once moved back to the original position

void runMission() {
      rackMoving = true;

if (rackMoving = true) {  

  while (digitalRead(topLimit) != HIGH) {   // moves rack and pinion down while limit switch isnt pressed 
    analogWrite(ENA, ENAVoltage);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  }

  digitalWrite(motorPin1, LOW); //brakes motors
  digitalWrite(motorPin2, LOW);
  delay(waterAbsorbTime); //time for the diaper to stop and absorb water

  while (digitalRead(bottomLimit) != HIGH) {   //moves rack and pinion up while bottom limit switch isnt pressed
    analogWrite(ENA, ENAVoltage);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
  }

    digitalWrite(motorPin1, LOW); //brakes motors
    digitalWrite(motorPin2, LOW);
    rackMoving = false;
}
  
}

 void moveRack(String rackDirection) {

  if(rackDirection == "Down") { while (digitalRead(topLimit) != HIGH) {
    analogWrite(ENA, ENAVoltage);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  }

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);

  }

  if (rackDirection == "Up") {while (digitalRead(bottomLimit) != HIGH) {
    analogWrite(ENA, ENAVoltage);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
  }

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  }

}


void loop() {
  /*Serial.print("Top Limit: ");
  Serial.print(digitalRead(topLimit));
  Serial.print(" | ");
  Serial.print("Bottom Limit: ");
  Serial.print(digitalRead(bottomLimit));
  Serial.println();
  moveRack("Up"); */
  runMission();
  delay(3000);
}

