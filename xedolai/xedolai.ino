int ENA = 11; //speed motor a
int le_UP = 12; //motor a = +in1
int le_DOWN = 13; //motor a = -in2
int ri_DOWN = 7; //motor b = - in3
int ri_UP = 6; //motor b = + in4
int ENB = 5; //speed motor b
int R_S = 8; //sincer R
int S_S = 9; //sincer S
int L_S = 10; //sincer L
void setup()
{
pinMode(ri_DOWN, OUTPUT);
pinMode(ri_UP, OUTPUT);
pinMode(le_UP, OUTPUT);
pinMode(le_DOWN, OUTPUT);
pinMode(ENB, OUTPUT);
pinMode(ENA, OUTPUT);
pinMode(L_S, INPUT);
pinMode(S_S, INPUT);
pinMode(R_S, INPUT);
Serial.begin(9600);
analogWrite(ENA, 90);//70
analogWrite(ENB, 90);//120
delay(25);
}
void loop()
{
//int trai = digitalRead(L_S);
//int giua = digitalRead(S_S);
//int phai = digitalRead(R_S);
if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){forward();}
if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){turnLeft();}
if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) ==0)&&(digitalRead(R_S) == 0)) {turnLeft();}
if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){turnRight();}
if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){turnRight();}
if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){Stop();}
if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){Stop();}
if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)){Stop();}
//Serial.println(dolinetrai);
//delay(1000);
//Serial.println(S_S);
//Serial.println(dolinephai);
}
void forward(){
digitalWrite(le_UP, LOW);
digitalWrite(le_DOWN, HIGH);
digitalWrite(ri_DOWN, HIGH);
digitalWrite(ri_UP, LOW);
}
void turnRight(){
digitalWrite(le_UP, LOW);
digitalWrite(le_DOWN, HIGH);
digitalWrite(ri_DOWN, LOW);
digitalWrite(ri_UP, LOW);
}
void turnLeft(){
digitalWrite(le_UP, LOW);
digitalWrite(le_DOWN, LOW);
digitalWrite(ri_DOWN, HIGH);
digitalWrite(ri_UP, LOW);
}
void Stop(){
digitalWrite(le_UP, LOW);
digitalWrite(le_DOWN, LOW);
digitalWrite(ri_DOWN, LOW);
digitalWrite(ri_UP, LOW);
}
