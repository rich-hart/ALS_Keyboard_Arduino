

#include <SoftwareSerial.h>
 
SoftwareSerial BT = SoftwareSerial(3, 2);
//int incomingByte = 0;   // for incoming serial data
//String txtMsg = "";

void setup() {
    Serial.begin(9600);
    BT.begin(9600);
        //Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop(){
   //
  delay(1000);
  Serial.println("Ready");
  
 // while (! Serial.available());
    while (Serial.available() > 0) {
      char c =Serial.read();
      Serial.write(c);
          BT.write(c);
          delay(10);
    //char inChar = Serial.read();
    //txtMsg += inChar;
  } 
  
    //  Serial.println(txtMsg);
    //Serial.println(txtMsg.length());
  
  
}
