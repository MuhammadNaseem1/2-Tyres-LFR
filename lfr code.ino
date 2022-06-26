int left_wheelA = 11; int left_wheelB = 10;
int right_wheelA = 9; int right_wheelB = 8;
int left_wheel_EN = 13; int right_wheel_EN = 12;
int S2 = 4;
int S3 = 3;
int S4 = 2;
int left = HIGH;
int centre = HIGH;
int right = HIGH;
const int freq = 5000;
const int Channel_1 = 0;
const int Channel_2 = 1;
const int resolution = 8;
void setup() {
 pinMode(left_wheelA, OUTPUT); pinMode(left_wheelB, OUTPUT);
 pinMode(right_wheelA, OUTPUT); pinMode(right_wheelB, OUTPUT);
 
 pinMode(left_wheel_EN, OUTPUT);
 pinMode(right_wheel_EN, OUTPUT);
 
 
 pinMode(S2, INPUT);
 pinMode(S3, INPUT);
 pinMode(S4, INPUT);
 Serial.begin(9600);
 ledcSetup(Channel_1, freq, resolution);
 ledcSetup(Channel_2, freq, resolution);
 ledcAttachPin(left_wheel_EN, Channel_1);
 ledcAttachPin(right_wheel_EN, Channel_2);
}
void loop() {
 
 
 left = digitalRead(S2);
 centre = digitalRead(S3);
 right = digitalRead(S4);
 
 
 if (left == HIGH && centre == LOW && right == HIGH) {
 Serial.println("ON Line, Go straight!!");
 digitalWrite(left_wheel_EN, HIGH); digitalWrite(right_wheel_EN, HIGH);
 ledcWrite(Channel_1, 120);
 ledcWrite(Channel_2, 140);
 
 digitalWrite(left_wheelA, LOW); digitalWrite(left_wheelB, HIGH);
 digitalWrite(right_wheelA, LOW); digitalWrite(right_wheelB, HIGH);
 
 
 }
 else if (left == LOW && centre == HIGH && right == HIGH){
 Serial.println("Moving on right side, turn left");
 turn_left();
 }
 else if (left == HIGH && centre == HIGH && right == LOW){
 Serial.println("Moving on leftt side, turn right");
 
 turn_right();
 }
 else {
 Serial.println("No Line found");
 
 
 }
}
 void turn_left(void){
 digitalWrite(left_wheelA, LOW); digitalWrite(left_wheelB, HIGH);
 digitalWrite(right_wheelA, HIGH); digitalWrite(right_wheelB, LOW);
}
 void turn_right(void){
 digitalWrite(left_wheelA, HIGH); digitalWrite(left_wheelB, LOW);
 digitalWrite(right_wheelA, LOW); digitalWrite(right_wheelB, HIGH);
}
