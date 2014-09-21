import processing.serial.*;

Serial serialPort;
String inString;

void setup() {
  size (600, 200);
  PFont myFont = createFont(PFont.list()[2], 14);
  textFont(myFont);
  serialPort = new Serial(this, "/dev/tty.usbserial-A600affF", 9600);
}

void draw() {
  background(0);
  text("received: " + inString, 10, 50);
}

void serialEvent(Serial myPort) {
  inString = serialPort.readStringUntil(10);
}

void keyPressed() {
  // Send the keystroke out:
  serialPort.write("1,15.0,0.5,0.8\n");
}

// TODO:
// needs a midi library to connect to the nanokontrol
// needs a visualisation of the four lights
// needs an on screen control for each light's HSV
