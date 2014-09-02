// Adafruit test code for Bluefruit EZ-Key serial reports
// Uncomment tests as you wish, remember that this will
// send various keypresses to your computer which may really
// annoy it! We used
// http://www.cambiaresearch.com/articles/15/javascript-char-codes-key-codes
// to test the non-printing characters!
// Connect the RX pin on the EZ-Key to digital #2 on the UNO
 
#include <SoftwareSerial.h>
 
SoftwareSerial BT = SoftwareSerial(3, 2);
 
void printabletest() {
  Serial.println("Testing printable 0x20-0x7E...");
  for (char c = 0x20; c <= 0x7E; c++) {
    Serial.write(c);
    BT.write(c);
    delay(10);
  }
  
  BT.write('\n');
  delay(3000);
  Serial.read(); // eat one char
  Serial.println();
  
  for (uint16_t i=0; i<200; i++) {
    while (Serial.available()) 
      Serial.write(Serial.read());
    delay(10);
  }
}
 
void nonprinting() { 
  Serial.println("Insert");
  BT.write(1); delay(1000);
  Serial.println("Home");
  BT.write(2); delay(1000);
  Serial.println("Page Up");
  BT.write(3); delay(1000);
  Serial.println("Delete");
  BT.write(4); delay(1000);
  Serial.println("End");
  BT.write(5); delay(1000);
  Serial.println("Page Down");
  BT.write(6); delay(1000);
  Serial.println("Right Arrow");
  BT.write(7); delay(1000);
  Serial.println("Backspace");
  BT.write(8); delay(1000);
  Serial.println("Tab");
  BT.write(9); delay(1000);
  Serial.println("Enter");
  BT.write(10); delay(1000);
  Serial.println("Left Arrow");
  BT.write(11); delay(1000);
  Serial.println("Down Arrow");
  BT.write(12); delay(1000);
  Serial.println("Enter");
  BT.write(13); delay(1000);
  Serial.println("Up Arrow");
  BT.write(14); delay(1000);
 
  for (uint8_t i=15; i<27; i++) {
    Serial.print("F"); Serial.println(i-14, DEC);
     BT.write(i); delay(500);
  }
  Serial.println("ESC");
  BT.write(27); delay(1000);
  Serial.println("Capslock");
  BT.write(28); delay(1000);
  Serial.println("Scroll lock");
  BT.write(29); delay(1000);
  Serial.println("Break");
  BT.write(30); delay(1000);
  Serial.println("Numlock");
  BT.write(31); delay(500);
 
}
void altkeystest() {
  Serial.println("Left Control\n");
  BT.write(0xE0);
  delay(500);
  Serial.println("Left Shift\n");
  BT.write(0xE1);
  delay(500);
  Serial.println("Left Alt\n");
  BT.write(0xE2);
  delay(500);
  Serial.println("Left GUI\n");
  BT.write(0xE3);
  delay(500);
  Serial.println("Right Control\n");
  BT.write(0xE4);
  delay(500);
  Serial.println("Right Shift\n");
  BT.write(0xE5);
  delay(500);
  Serial.println("Right Alt\n");
  BT.write(0xE6);
  delay(500);
  Serial.println("Right GUI\n");
  BT.write(0xE7);
  delay(500); 
}
 
void iphonekeyboard() {
  while (1) {
    Serial.println("toggle keyboard");
    BT.write(0x7F);
    delay(1000);
  }
}
 
void keyCommand(uint8_t modifiers, uint8_t keycode1, uint8_t keycode2 = 0, uint8_t keycode3 = 0, 
                uint8_t keycode4 = 0, uint8_t keycode5 = 0, uint8_t keycode6 = 0) {
  BT.write(0xFD);       // our command
  BT.write(modifiers);  // modifier!
  BT.write((byte)0x00); // 0x00  
  BT.write(keycode1);   // key code #1
  BT.write(keycode2); // key code #2
  BT.write(keycode3); // key code #3
  BT.write(keycode4); // key code #4
  BT.write(keycode5); // key code #5
  BT.write(keycode6); // key code #6
}
 
void rawkeytest() {
  // test sending a single 'a' (keycode 4)
  keyCommand(0, 4);
  delay(100);
  keyCommand(0, 0);
} 
 
/************** Support added in v1.1 */
 
void rawmousetest() {
  Serial.println("Move mouse!");
  Serial.println("Right");
  mouseCommand(0, -100, 0);
  delay(200); 
  Serial.println("Down");
  mouseCommand(0, 0, -100);  
  delay(200); 
  Serial.println("Left");
  mouseCommand(0, 100, 0);  
  delay(200); 
  Serial.println("Up");
  mouseCommand(0, 0, 100);  
  delay(200); 
}
 
void mouseCommand(uint8_t buttons, uint8_t x, uint8_t y) {
  BT.write(0xFD);
  BT.write((byte)0x00);
  BT.write((byte)0x03);
  BT.write(buttons);
  BT.write(x);
  BT.write(y);
  BT.write((byte)0x00);
  BT.write((byte)0x00);
  BT.write((byte)0x00);
}
 
/************** Support added in v1.1 */
 
void setup() {
  Serial.begin(9600);
  BT.begin(9600);
 
  Serial.println("Softserial/BT test!\n\rPress any key+return to start");
  while (! Serial.available());
 
  printabletest(); delay(200);
  //altkeystest();
  //nonprinting();
  //iphonekeyboard();
  //rawkeytest();
 
  //Supported in v1.1
  //rawmousetest();
}
 
void loop() {
  
}
