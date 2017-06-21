#include <DmxSimple.h>
#define DMX_MASTER_CHANNELS   512
#define DMX_ENABLE_PIN 2
#define DMX_ENABLE_PIN 3
#define DMX_TRANSMIT_PIN  4
#define STEP_INTERVAL           1

int light1 = 1;
int light2 = 2;
int light3 = 3;
int light4 = 4;

void setup() {
  Serial.begin(9600);
  DmxSimple.usePin(DMX_TRANSMIT_PIN);
  DmxSimple.maxChannel(DMX_MASTER_CHANNELS);
  pinMode(DMX_ENABLE_PIN, OUTPUT);
  digitalWrite(DMX_ENABLE_PIN, HIGH);

  setLightToRGB(1, 50, 50, 50);
  Serial.println("Ready for some colour strings - receiving HSV!");
  Serial.println("Light: 1-4, HUE: 0-360, Sat:0f-1f, Val: 0f-1f");

}

void loop() {
  while (Serial.available() > 0) {
    int channel = Serial.parseInt();
    float hue = Serial.parseFloat();
    float sat = Serial.parseFloat();
    float val = Serial.parseFloat();

    float red = 0;
    float green = 0;
    float blue = 0;

    HSVtoRGB(&red, &green, &blue, hue, sat, val);

    if (Serial.read() == '\n') {
      red = floor(red * 255);
      green = floor(green * 255);
      blue = floor(blue * 255);
      // Set the light going.
      setLightToRGB(channel, red, green, blue);

      Serial.print("Light ");
      Serial.print(channel);
      Serial.print(": ");
      Serial.print(red);
      Serial.print(", ");
      Serial.print(green);
      Serial.print(", ");
      Serial.println(blue);
    }
  }
}

void setLightToRGB(int light, int red, int green, int blue) {
  int baseChannel = ((light - 1) * 4) + 1;
  DmxSimple.write(baseChannel, 255);
  DmxSimple.write(baseChannel + 1, red);
  DmxSimple.write(baseChannel + 2, green);
  DmxSimple.write(baseChannel + 3, blue);
}


void HSVtoRGB( float *r, float *g, float *b, float h, float s, float v ) {
  int i;
  float f, p, q, t;
  if ( s == 0 ) {
    // achromatic (grey)
    *r = *g = *b = v;
    return;
  }
  h /= 60; // sector 0 to 5
  i = floor( h );
  f = h - i; // factorial part of h
  p = v * ( 1 - s );
  q = v * ( 1 - s * f );
  t = v * ( 1 - s * ( 1 - f ) );
  switch ( i ) {
    case 0:
      *r = v;
      *g = t;
      *b = p;
      break;
    case 1:
      *r = q;
      *g = v;
      *b = p;
      break;
    case 2:
      *r = p;
      *g = v;
      *b = t;
      break;
    case 3:
      *r = p;
      *g = q;
      *b = v;
      break;
    case 4:
      *r = t;
      *g = p;
      *b = v;
      break;
    default:// case 5:
      *r = v;
      *g = p;
      *b = q;
      break;
  }
}





