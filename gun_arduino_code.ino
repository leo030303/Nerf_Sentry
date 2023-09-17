//Main Code

// Define stepper motor connections and steps per revolution:
#define dirPin A1
#define stepPin A3
#define stepperEnablePin A5
#define stepsPerRevolution 200
#define stepInterval 10000
#define pushPin 6
#define pullPin 5
#define relayEnablePin 10
int data;

void setup() {
  // Declare pins as output:
  digitalWrite(13, LOW);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600); // open the serial port at 9600 bps:
  pinMode(stepperEnablePin, OUTPUT);
  pinMode(relayEnablePin, OUTPUT);
  pinMode(pushPin, OUTPUT);
  pinMode(pullPin, OUTPUT);
  digitalWrite(stepperEnablePin, HIGH);
  digitalWrite(relayEnablePin, LOW);
  digitalWrite(pushPin, LOW);
  digitalWrite(pullPin, LOW);
}

void loop() {
  digitalWrite(stepperEnablePin, LOW);
  //Serial.println("Test");
  while(Serial.available()){
    data = Serial.read();
    Serial.println(data);
    Serial.flush();
  }
  // if (data == "1") do nothing
  if (data == 50){ //turn clockwise
    data = 0;  
    Serial.println("Rotating Clockwise");    
    digitalWrite(dirPin, HIGH);
    for (int i = 0; i < stepsPerRevolution/20; i++) {
      // These four lines result in 1 step:
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(stepInterval);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(stepInterval);
    }
  }
  else if (data == 51){ //turn anticlockwise
    data = 0;
    Serial.println("Rotating Anticlockwise");
    digitalWrite(dirPin, LOW);
    for (int i = 0; i < stepsPerRevolution/20; i++) {
      // These four lines result in 1 step:
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(stepInterval);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(stepInterval);
    }
  }
  else if (data == 52){ //pull trigger
    data = 0;
    Serial.println("Firing");
    digitalWrite(relayEnablePin, HIGH);
    digitalWrite(pullPin, HIGH);
  }
  else if (data == 53){ //unpull trigger
    data = 0;
    Serial.println("Ending Firing");
    digitalWrite(relayEnablePin, HIGH);
    digitalWrite(pullPin, LOW);
    digitalWrite(pushPin, HIGH);
  } 
}



//Test Mechanics
/*
// Define stepper motor connections and steps per revolution:
#define dirPin A1
#define stepPin A3
#define stepperEnablePin A5
#define stepsPerRevolution 200
#define stepInterval 10000
#define pushPin 6
#define pullPin 5
#define relayEnablePin 10
int data;

void setup() {
  // Declare pins as output:
  digitalWrite(13, LOW);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600); // open the serial port at 9600 bps:
  pinMode(stepperEnablePin, OUTPUT);
  pinMode(relayEnablePin, OUTPUT);
  pinMode(pushPin, OUTPUT);
  pinMode(pullPin, OUTPUT);
  digitalWrite(stepperEnablePin, HIGH);
  digitalWrite(relayEnablePin, LOW);
  digitalWrite(pushPin, LOW);
  digitalWrite(pullPin, LOW);
}

void loop() {
  delay(5000);
  digitalWrite(stepperEnablePin, LOW);
  //Serial.println("Test");
  // if (data == "1") do nothing
   //turn clockwise
  Serial.println("Rotating Clockwise");    
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < stepsPerRevolution/3; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepInterval);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepInterval);
  }
  //turn anticlockwise
  Serial.println("Rotating Anticlockwise");
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < stepsPerRevolution/3; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepInterval);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepInterval);
  }
     //turn clockwise
  Serial.println("Rotating Clockwise");    
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < stepsPerRevolution/20; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepInterval);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepInterval);
  }
  //turn anticlockwise
  Serial.println("Rotating Anticlockwise");
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < stepsPerRevolution/20; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepInterval);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepInterval);
  }
  //pull trigger
  Serial.println("Firing");
  digitalWrite(relayEnablePin, HIGH);
  digitalWrite(pullPin, HIGH);
  delay(1000);
  Serial.println("Rotating Anticlockwise");
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < stepsPerRevolution/4; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepInterval);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepInterval);
  }
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < stepsPerRevolution/4; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepInterval);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepInterval);
  }
  delay(5000);
  //unpull trigger
  Serial.println("Ending Firing");
  digitalWrite(relayEnablePin, HIGH);
  digitalWrite(pullPin, LOW);
  digitalWrite(pushPin, HIGH);
}
*/


// serial test
/*
int data;

void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:
}

void loop() {
  while(Serial.available()){
    data = Serial.read();
    Serial.println(data);
  }
}
*/