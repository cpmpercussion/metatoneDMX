import processing.serial.*;

Serial serialPort;
String inString;
String sendString = "";
float hue = 0.0;
float sat = 0.0f;
float val = 0.0f;

DmxLight light1;



void setup() {
  size (600, 200);
  PFont myFont = createFont(PFont.list()[2], 14);
  textFont(myFont);
  serialPort = new Serial(this, "/dev/tty.usbserial-A600affF", 9600);
  colorMode(HSB, 360.0, 1.0, 1.0);

  light1 = new DmxLight(1, hue, sat, val);
}

void draw() {
  background(0);

  light1.fade();
  light1.updateLight(serialPort);
  light1.paint(100,100);
  
  stroke(255);
  fill(255);
  
  text("received: " + inString, 10, 50);
  text("sent: " + sendString, 10, 100);
}

void serialEvent(Serial myPort) {
  inString = serialPort.readStringUntil(10);
}

void keyPressed() {
  hue = random(360);
  sat = random(1000) / 1000.0f;
  val = 1.0f;
  light1.setTargetColour(hue, sat, val);
}

// TODO:
// needs a midi library to connect to the nanokontrol
// needs a visualisation of the four lights
// needs an on screen control for each light's HSV
