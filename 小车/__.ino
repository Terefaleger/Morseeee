// f向前 b向后 l向左 r向右 s停止(刹车)
//从左往右依次为左前轮、右前轮、左后轮、右后轮的电机

void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

byte income=0;

void loop()
{
  if(Serial.available()>0)
    income=Serial.read();
  switch(income){
 case 'f':
    forward();
    break;
    case'b':
    backward();
    break;
    case'l':
    left();
    break;
    case'r':
    right();
    break;
    case's':
    stop();
    break;
    default:
    break;
  }

 
}


void forward()
{
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
}

void backward()
{
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);

}
void left()
{
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
}

void right()
{
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,LOW);
}

void stop()
{
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW); 
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW); 
}
