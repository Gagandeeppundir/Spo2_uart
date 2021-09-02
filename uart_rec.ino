char rec;
void setup() 
{
  // put your setup code here, to run once:
Serial.begin(4800, SERIAL_8O1);
}

void loop()
{
  // put your main code here, to run repeatedly:

if(Serial.available()>0)
{
   rec = Serial.read();
   Serial.println(rec,BIN);
  }
 
}
