/* 1byte HC12 TRANSMITTER example.
/* Tutorial link: http://electronoobs.com/eng_arduino_tut96.php
 * Code: http://electronoobs.com/eng_arduino_tut96_code1.php
 * Scheamtic: http://electronoobs.com/eng_arduino_tut96_sch1.php
 * Youtube Channel: http://www.youtube/c/electronoobs   
 * 
  Module // Arduino UNO/NANO    
    GND    ->   GND
    Vcc    ->   3.3V
    Tx     ->   D10
    Rx     ->   D11      
 */

#include <SoftwareSerial.h>
SoftwareSerial HC12(9, 10); // HC-12 TX Pin, HC-12 RX Pin
int pot = 6;
int val = 0;

struct package {
  int msg[5] = {0};
};

typedef struct package Package;
  Package data;

void setup() {
  //Serial3.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12
  Serial.begin(9600);
  
  pinMode(A7,INPUT);

}
void loop() { 
  

  int val = map(analogRead(A7),0,1024,0,255);
  //HC12.write(val);      // Send that data to HC-12 

  data.msg[0] = val;
  data.msg[1] = 2;
  data.msg[2] = 30;
  data.msg[3] = 40;
  data.msg[4] = 50;
  
  writeData();
  delay(50);

   
  //HC12.write(val);
  //Serial.println(val);
  //Serial3.write("Hello World");
  //delay(100);

}

void writeData() {
  HC12.write((byte*)&data, sizeof(data));
  Serial.print ("\ nSent:");
  Serial.print (data.msg[0]);
  Serial.print (" ");
  Serial.print (data.msg[1]);
  Serial.print (" ");
  Serial.print (data.msg[2]);
  Serial.print (" ");
  Serial.print (data.msg[3]);
  Serial.print (" ");
  Serial.println (data.msg[4]);
}

  
