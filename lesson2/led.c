void setup()
{
  int i;
  for(i=8;i>=0;i--)
  {
  	pinMode(i, OUTPUT);
  }
}

void loop()
{
  int j;
  for(j=8;j>=0;j--)
  {
    digitalWrite(j, HIGH);
    delay(100); // Wait for 1000 millisecond(s)
    digitalWrite(j, LOW);
    delay(100); // Wait for 1000 millisecond(s)
  }
   for(j=0;j<8;j++)
  {
    digitalWrite(j, HIGH);
    delay(100); // Wait for 1000 millisecond(s)
    digitalWrite(j, LOW);
    delay(100); // Wait for 1000 millisecond(s)
  }
  
}