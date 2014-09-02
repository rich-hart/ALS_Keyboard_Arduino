int incomingByte = 0;   // for incoming serial data
String txtMsg = "";

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop(){
   //
  //delay(1000);
  Serial.println("Ready");
  
  //while (! Serial.available());
    while (Serial.available() > 0) {
      Serial.write(Serial.read());
    //char inChar = Serial.read();
    //txtMsg += inChar;
  } 
  
    //  Serial.println(txtMsg);
    //Serial.println(txtMsg.length());
  
  
}
