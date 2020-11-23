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
#include "Adafruit_VL53L0X.h"
#include <SoftwareSerial.h>
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
SoftwareSerial HC12(9, 10); // HC-12 TX Pin, HC-12 RX Pin
SoftwareSerial proMicro(16, 14); //proMicro TX,RX -> tx ke tx, rx ke rx?
int pot = 6;
int val = 0;

struct package {
  int msg[5] = {0};
};

typedef struct package Package;
  Package data;

void setup() {

    // wait until serial port opens for native USB devices
  while (! Serial) { delay(1); }
  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  
  //Serial3.begin(9600);             // Serial port to computer
  proMicro.begin(9600);
  HC12.begin(9600);               // Serial port to HC12
  Serial.begin(9600);
  
  pinMode(A7,INPUT);

}
void loop() { 
    VL53L0X_RangingMeasurementData_t measure;
    lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

    if (measure.RangeStatus != 4) {  // phase failures have incorrect data
      //Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
    } else {
      Serial.println(" out of range ");
    }

  int val = map(analogRead(A7),0,1024,0,255);
  //HC12.write(val);      // Send that data to HC-12 

  data.msg[0] = val;
  data.msg[1] = measure.RangeMilliMeter;
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
  proMicro.write((byte*)&data, sizeof(data));
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

  
