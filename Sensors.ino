const int trigPin_1 = 2;
const int echoPin_1 = 3;
const int trigPin_2 = 5;
const int echoPin_2 = 4;
const int buzzer = 6;
const int emergencyPin = 7;

int distance_1,distance_2,freq;
bool isEmergency = false;
void setup() {
  pinMode(trigPin_1, OUTPUT); // Sets the trigPin_1 as an Output
  pinMode(echoPin_1, INPUT); // Sets the echoPin_1 as an Input
  pinMode(trigPin_2, OUTPUT); // Sets the trigPin_2 as an Output
  pinMode(echoPin_2, INPUT); // Sets the echoPin_2 as an Input
  pinMode(emergencyPin, OUTPUT); // Sets the trigPin_2 as an Output
  tone(buzzer, 1000); 
  Serial.begin(9600); // Starts the serial communication
  delay(500);
  noTone(buzzer); // Stop the tone
}

int calculateDistance(int trigPin,int echoPin){
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void emergencyTone(){
  while(true){
    tone(buzzer,4000);
    delay(80);
    noTone(buzzer);
    delay(80);
  }
}

void loop() {
  if(isEmergency)emergencyTone();
  
  distance_1=calculateDistance(trigPin_1,echoPin_1);
  distance_2=calculateDistance(trigPin_2,echoPin_2);
  if(digitalRead(emergencyPin)==1){
    isEmergency = true;
  }
  if(distance_1<25 || distance_2<25){
    freq = distance_1<25?2000:3000;
    tone(buzzer, freq);   // Start tone at 1000 Hz
  }else{
    noTone(buzzer);       // Stop tone
  }
  delay(150);
}