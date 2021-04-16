  #include "MQ7.h"

int counter = 0;  // counterという名前の変数を用意して、0をセットする

const int AOUTpin=0;//the AOUT pin of the CO sensor goes into analog pin A0 of the arduino
const int DOUTpin=8;//the DOUT pin of the CO sensor goes into digital pin D8 of the arduino

int limit;
int value;

MQ7 mq7(A0, 5.0);

void setup() {
  
  Serial.begin(9600);             // シリアル通信の準備をする
  while (!Serial);                  // 準備が終わるのを待つ

  pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino

}

void loop() {
  
  float analog_0 = analogRead(AOUTpin);
  float voltage_0 = (analog_0*5)/1024;
  
  limit = digitalRead(DOUTpin);
  
  Serial.print("CO = ");
  Serial.print(mq7.getPPM());
  Serial.print(" ppm");
  Serial.println("");
  delay(500);
}
