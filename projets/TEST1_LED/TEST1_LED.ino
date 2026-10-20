void setup() {
  // put your setup code here, to run once:
  for(int i =5; i<=7; i++)
  {
    pinMode(i,OUTPUT);
    digitalWrite(i, HIGH);
  }

  delay(1000);

  for(int i =5; i<=7; i++)
  {
    digitalWrite(i, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i =5; i<=7; i++)
  {
    digitalWrite(i, HIGH);
    delay(150);
    digitalWrite(i, LOW);
  }

}
