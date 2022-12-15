/*
 * Programmer: Mr. Lange
 * Date: 12.12.2022
 * Program: Ultrasonic Security System
 * 
 * Resource: https://create.arduino.cc/projecthub/Krepak/ultrasonic-security-system-3afe13?ref=search&ref_id=red%20green%20yellow%20light%20echo%20sensor&offset=1
 */


int trigPin = 2;
int echoPin = 3;
int LEDlampRed = 4;
int LEDlampYellow  = 5;
int LEDlampGreen = 6; 
int soundbuzzer = 7;
int sound = 500;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDlampRed, OUTPUT);
  pinMode(LEDlampYellow, OUTPUT);
  pinMode(LEDlampGreen, OUTPUT);
  pinMode(soundbuzzer, OUTPUT);
}
void loop() {
  long durationindigit, distanceincm;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationindigit = pulseIn(echoPin, HIGH);
  distanceincm = (durationindigit/5) / 29.1;
 
  if (distanceincm <= 10 && distanceincm >= 7) {
      digitalWrite(LEDlampGreen, HIGH);
      Serial.println("Getting Close - Proceed with caution");
}
  else {
      digitalWrite(LEDlampGreen, LOW);
  }
  
  if (distanceincm <= 6 && distanceincm >= 4) {
    digitalWrite(LEDlampYellow, HIGH);
    Serial.println("Really Close - Be ready to stop");
}
  else {
    digitalWrite(LEDlampYellow,LOW);
  }
  if (distanceincm < 4) {
    digitalWrite(LEDlampRed, HIGH);
    Serial.println("STOP NOW");
    tone(soundbuzzer, sound);
}
  else {
    digitalWrite(LEDlampRed,LOW);
  }
 
  if (distanceincm > 10 || distanceincm <= 0){
    Serial.println("We have not detected your car yet - Proceed Forward");
    noTone(soundbuzzer);
  }
  else {
    Serial.print(distanceincm);
    Serial.println(" cm");
    
  }
  
  delay(300);
}
