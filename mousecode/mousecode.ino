#include <Morse.h>
  Morse morse(13);
  char MORSE[][4] = {
    {'.', '-', '*', '*'}, //A
    {'-', '.', '.', '.'}, //B
    {'-', '.', '-', '.'}, //C
    {'-', '.', '.', '*'}, //D
    {'.', '*', '*', '*'}, //E
    {'.', '.', '-', '.'}, //F
    {'-', '-', '.', '*'}, //G
    {'.', '.', '.', '.'}, //H
    {'.', '.', '*', '*'}, //I
    {'.', '-', '-', '-'}, //J
    {'-', '.', '-', '*'}, //K
    {'.', '-', '.', '.'}, //L
    {'-', '-', '*', '*'}, //M
    {'-', '.', '*', '*'}, //N
    {'-', '-', '-', '*'}, //O
    {'.', '-', '-', '.'}, //P
    {'-', '-', '.', '-'}, //Q
    {'.', '-', '.', '*'}, //R
    {'.', '.', '.', '*'}, //S
    {'-', '*', '*', '*'}, //T
    {'.', '.', '-', '*'}, //U
    {'.', '.', '.', '-'}, //V
    {'.', '-', '-', '*'}, //W
    {'-', '.', '.', '-'}, //X
    {'-', '.', '-', '-'}, //Y
    {'-', '-', '.', '.'}  //Z
  };
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
String me="";
String code="";
int i,t,temp=0;
int n=0;
while (Serial.available() > 0)
    {
      temp = 1;
      me+= char(Serial.read());
      delay(2);
      n++;
    }
    //接收并存储字符串
 if (temp)
    {
      for (i = 0; i < n; i++)
      {
        for (t = 0; t < 4; t++)
        {
          if (me[i] >96 && me[i] < 123)
          {
            code+= char(MORSE[int(me[i] - 97)][t]);
          }
        }
        code+= ' ';
      }
      Serial.println(code); 
      for (i = 0; code[i]!='\0' ; i++)//读取莫尔斯电码
      {
        if (code[i] == '.')morse.dot();
        else if (code[i] == '-')morse.dash();
        else if (code[i] == ' ')morse.w_space();
        if (code[i] != ' ' && me[i] != '*')morse.c_space();
      }
    }
}
