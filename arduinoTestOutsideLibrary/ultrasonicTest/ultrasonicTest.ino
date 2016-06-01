int trigFront = 53; 
int echoFront = 52; 
int trigBack = 49; 
int echoBack = 48; 
long lecture_echo; 
long cm;

void setup() 
{ 
  pinMode(trigFront, OUTPUT); 
  digitalWrite(trigFront, LOW); 
  pinMode(echoFront, INPUT); 

  pinMode(trigBack, OUTPUT); 
  digitalWrite(trigBack, LOW); 
  pinMode(echoBack, INPUT); 
  
  Serial.begin(9600); 
}

void loop() 
{ 
  digitalWrite(trigFront, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigFront, LOW); 
  lecture_echo = pulseIn(echoFront, HIGH); 
  cm = lecture_echo / 58; 
  Serial.print("Distance front cm : "); 
  Serial.println(cm); 
  delay(1000); 

  digitalWrite(trigBack, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigBack, LOW); 
  lecture_echo = pulseIn(echoBack, HIGH); 
  cm = lecture_echo / 58; 
  Serial.print("Distance back cm : "); 
  Serial.println(cm); 
  delay(1000); 
}
