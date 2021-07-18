//int one = 1;
//int two = 1;
//int four = 1;
//int eight = 1;
//int sixteen = 1;
//bool isNew = FALSE;
int pageNumber = 0;

void setup() {
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  Serial.begin(9600);
  delay(1000);
}

void loop() {
//  isNew = digitalRead(0);

  if(digitalRead(0)) {
    Serial.print("new msg");
    delay(200);
    pageNumber =+ digitalRead(1) + digitalRead(2)*2 + digitalRead(3)*4 + digitalRead(4)+8 + digitalRead(5)*16;
    Serial.print(pageNumber);
//    one = digitalRead(1);
//    two = digitalRead(2);
//    four = digitalRead(3);
//    eight = digitalRead(4);
//    sixteen = digitalRead(5);
  }
}
