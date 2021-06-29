const int trig1 = 1;
const int trig2 = 2;
const int trig3 = 3;
const int trig4 = 4;

const int echo1 = 8;
const int echo2 = 9;
const int echo3 = 10;
const int echo4 = 11;

long duration1 = 0;
long distance1 = 0;

long duration2 = 0;
long distance2 = 0;

long duration3 = 0;
long distance3 = 0;

long duration4 = 0;
long distance4 = 0;

void setup() 
{
  pinMode(trig1 , OUTPUT);
  pinMode(trig2 , OUTPUT);
  pinMode(trig3 , OUTPUT);
  pinMode(trig4 , OUTPUT);
  
  pinMode(echo1 , INPUT);
  pinMode(echo2 , INPUT);
  pinMode(echo3 , INPUT);
  pinMode(echo4 , INPUT);

  Serial.begin(9600);
}

void loop()
{ 
  sonic2();
  sonic3();
  sonic4();  
  sonic1();  
}

void sonic1(){
  digitalWrite(trig1 , HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1 , LOW);

  duration1 = pulseIn(echo1 , HIGH);
  distance1 = (duration1/2) / 28.5 ; 
  Serial.print("        Sonic4: "); 
  Serial.print(distance1); 
}

void sonic2() {
  digitalWrite(trig2 , HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2 , LOW);

  duration2 = pulseIn(echo2 , HIGH);
  distance2 = (duration2/2) / 28.5 ;  
  Serial.println();  
  Serial.print("Sonic1: "); 
  Serial.print(distance2);
}

void sonic3() {
  digitalWrite(trig3 , HIGH);
  delayMicroseconds(10);
  digitalWrite(trig3 , LOW);

  duration3 = pulseIn(echo3 , HIGH);
  distance3 = (duration3/2) / 28.5 ;
  Serial.print("        Sonic2: "); 
  Serial.print(distance3);
}

void sonic4() {
  digitalWrite(trig4 , HIGH);
  delayMicroseconds(10);
  digitalWrite(trig4 , LOW);

  duration4 = pulseIn(echo4 , HIGH);
  distance4 = (duration4/2) / 28.5 ;
  Serial.print("        Sonic3: "); 
  Serial.print(distance2);
}
