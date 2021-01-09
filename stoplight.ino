// ULTRASONIC SENSOR
int trigPin = 13;
int echoPin = 12;

// LIGHTS
int redLight = 7;
int yellowLight = 4;
int greenLight = 2;

// MOTION
bool firstLoop = true;

// DELAY
int lightTimer = 1500;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(redLight, OUTPUT);
  pinMode(yellowLight, OUTPUT);
  pinMode(greenLight, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance >= 200 || distance <= 0)
  {
    firstLoop = true;
    digitalWrite(greenLight, LOW);
    Serial.println("Out of range");
    digitalWrite(greenLight, LOW);
    digitalWrite(yellowLight, LOW);
    digitalWrite(redLight, HIGH);
  }
  else if (distance <= 20)
  {
    Serial.print(distance);
    Serial.println(" cm AAAAA");
    if (firstLoop) {
      digitalWrite(redLight, HIGH);
      delay(lightTimer);
      digitalWrite(redLight, LOW);
      digitalWrite(yellowLight, HIGH);
      delay(lightTimer);
      digitalWrite(yellowLight, LOW);
      digitalWrite(greenLight, HIGH);
      firstLoop = false;
    } else {
      digitalWrite(greenLight, HIGH);
    }
    delay(2500);
   
  } else {
    firstLoop = true;
    digitalWrite(greenLight, LOW);
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(redLight, HIGH);
  }
  delay(500);
  
}
