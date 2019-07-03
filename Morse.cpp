int ledPin=12;
char*letters[]={".-","-...","-.-.","-..",".",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
char*numbers[]={"-----",".-----"};
int dotDelay=200;
void setup() 
{
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);//设置波特率为9600；
}
void loop() 
{
  char ch;
  if(Serial.available())
  {
    ch=Serial.read();
    if(ch>='a'&&ch<='z')
    {
      flashSequence(letters[ch-'a']);
    }
    else if(ch>='0'&&ch<='9')
    {
      flashSequence(numbers[ch-'0']);  
    }
    else if(ch==' ')
    {
      delay(dotDelay*4);
    }
  }
}
void flashSequence(char*sequence)
{
  int i=0;
  while(sequence[i]!=NULL)  
  {
    flashDotOrDash(sequence[i]);
    i++;  
  }
  delay(dotDelay*3);
}
void flashDotOrDash(char dotOrDash)
{
  digitalWrite(ledPin,HIGH);
  if(dotOrDash=='.')
  {delay(dotOrDash);}
  else
  {delay(dotDelay*3);}
  digitalWrite(ledPin,LOW);
  delay(dotDelay);
}
