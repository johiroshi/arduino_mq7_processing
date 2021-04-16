import processing.serial.*;
 
Serial Port;
String Text = "";
int lf = 10;    // ASCII return 

void setup() {
  
  // list available serial port  
  printArray(Serial.list());
  
  Port = new Serial(this, "/dev/cu.usbmodem14201", 9600);
  Port.clear();
  Text = null;
  
  size(1024, 720);
  Port.bufferUntil(10);
}

void serialEvent(Serial Port) {
  Text = Port.readStringUntil(10);
}

void draw() {
  background(0, 0, 0);
  textAlign(CENTER);
  text(Text, width/2, height/2);
  textSize(100);
}
