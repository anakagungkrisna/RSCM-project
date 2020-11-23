/* 1byte HC12 Receiver example.
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

struct package {
  int msg;
};

typedef struct package Package;
Package data[5];

int dataStatus;

//SoftwareSerial HC12(9, 10); // HC-12 TX Pin, HC-12 RX Pin
int LED = 3;
int period = 100;
int time_now = millis();





void setup() {
  Serial3.begin(9600);             // Serial port to computer
  //HC12.begin(9600);               // Serial port to HC12
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

int val1;
int val2;
int val3;

void loop() {

  dataStatus = readData();
  Serial.println(dataStatus);

  if(dataStatus == 1) {
    val1 = data[0].msg; //posisi lurusnya 92 + 6(biar akurat)
    val2 = data[2].msg;
    val3 = data[2].msg;
  }
  else if(dataStatus == 0) {
    val1 = 0; //posisi lurusnya 92 + 6(biar akurat)
    val2 = 0;
    val3 = 0;
  }

  delay(65);

  
//if(millis() > time_now + period) { 
//  time_now = millis(); 
//  if (Serial3.available()) {        // If HC-12 has data
//    int val = Serial3.read();
//    Serial.println(Serial3.read());      // Send the data to Serial monitor
//    analogWrite(LED,val);
//    Serial.println(val);
//    //delay(100);
//  }
//}
  
  //analogWrite(LED, 0);  
  //Serial.println(0);
  //delay(100);
  
}


int readData() {
  //Serial.println("TOST");
  if(Serial3.available()) {
    while(Serial3.available() ) {
      Serial3.readBytes((byte*)&data, sizeof(data)); 
      //Serial.println("TEST");
    }
    for (byte i=0; i<5; i++){
      Serial.println(data[i].msg);
    }
    Serial.println();
    return 1;
  }
  return 0;
}
