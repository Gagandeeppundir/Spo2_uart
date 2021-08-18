void segment(unsigned int value, unsigned int digit);
 int i,j,k;
void setup()
{
                 // put your setup code here, to run once:
  
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
}

void loop()
{
                  // put your main code here, to run repeatedly:
for(i=0;i<10;i++)
{
  for(j=0;j<10;j++)
  {
    for(k=0;k<=9;k++)
    {
     segment(i,2);
     delay(10);
     segment(j,1);
     delay(10);
    }
  }
}
}

  void segment(unsigned int value, unsigned int digit)
  {
    switch(digit)
    {
      case 1:
            digitalWrite(5,HIGH);
            digitalWrite(6,LOW);
      break;
      case 2:
            digitalWrite(5,LOW);
            digitalWrite(6,HIGH);      
      break;
      default:
            digitalWrite(5,LOW);
            digitalWrite(6,LOW);
      break;
      }
    
  switch(value)
  {
    case 0:
           digitalWrite(7,HIGH);
           digitalWrite(8,HIGH);   
           digitalWrite(9,HIGH);
           digitalWrite(10,HIGH);
           digitalWrite(11,HIGH);
           digitalWrite(12,HIGH);
           digitalWrite(13,LOW);
    break; 
    case 1:
           digitalWrite(7,LOW);
           digitalWrite(8,HIGH);   
           digitalWrite(9,HIGH);
           digitalWrite(10,LOW);
           digitalWrite(11,LOW);
           digitalWrite(12,LOW);
           digitalWrite(13,LOW);
    break; 
    case 2:
           digitalWrite(7,HIGH);
           digitalWrite(8,HIGH);   
           digitalWrite(9,LOW);
           digitalWrite(10,HIGH);
           digitalWrite(11,HIGH);
           digitalWrite(12,LOW);
           digitalWrite(13,HIGH);
    break; 
    case 3:
           digitalWrite(7,HIGH);
           digitalWrite(8,HIGH);   
           digitalWrite(9,HIGH);
           digitalWrite(10,HIGH);
           digitalWrite(11,LOW);
           digitalWrite(12,LOW);
           digitalWrite(13,HIGH);
    break; 
    case 4:
           digitalWrite(7,LOW);
           digitalWrite(8,HIGH);   
           digitalWrite(9,HIGH);
           digitalWrite(10,LOW);
           digitalWrite(11,LOW);
           digitalWrite(12,HIGH);
           digitalWrite(13,HIGH);
    break; 
    case 5:
           digitalWrite(7,HIGH);
           digitalWrite(8,LOW);   
           digitalWrite(9,HIGH);
           digitalWrite(10,HIGH);
           digitalWrite(11,LOW);
           digitalWrite(12,HIGH);
           digitalWrite(13,HIGH);
    break; 
   case 6:
           digitalWrite(7,HIGH);
           digitalWrite(8,LOW);   
           digitalWrite(9,HIGH);
           digitalWrite(10,HIGH);
           digitalWrite(11,HIGH);
           digitalWrite(12,HIGH);
           digitalWrite(13,HIGH);
    break; 
    case 7:
           digitalWrite(7,HIGH);
           digitalWrite(8,HIGH);   
           digitalWrite(9,HIGH);
           digitalWrite(10,LOW);
           digitalWrite(11,LOW);
           digitalWrite(12,LOW);
           digitalWrite(13,LOW);
    break; 
   case 8:
           digitalWrite(7,HIGH);
           digitalWrite(8,HIGH);   
           digitalWrite(9,HIGH);
           digitalWrite(10,HIGH);
           digitalWrite(11,HIGH);
           digitalWrite(12,HIGH);
           digitalWrite(13,HIGH);
    break; 
    case 9:
           digitalWrite(7,HIGH);
           digitalWrite(8,HIGH);   
           digitalWrite(9,HIGH);
           digitalWrite(10,HIGH);
           digitalWrite(11,LOW);
           digitalWrite(12,HIGH);
           digitalWrite(13,HIGH);
    break; 
    default:
    break;
   }
   } 
