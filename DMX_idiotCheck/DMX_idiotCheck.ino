#include <Conceptinetics.h>
#define DMX_MASTER_CHANNELS   100 
#define RXEN_PIN                2
#define STEP_INTERVAL           1
DMX_Master dmx_master(DMX_MASTER_CHANNELS, RXEN_PIN);

int light1 = 1;
int light2 = 2;
int light3 = 3;
int light4 = 4;

void setLightToRGB(int light, int red, int green, int blue) {
  dmx_master.setChannelValue(light,255);
  dmx_master.setChannelValue(light+1,red);
  dmx_master.setChannelValue(light+2,green);
  dmx_master.setChannelValue(light+3,blue);
}

void welcomeAnimation() {
  // Check each light.
  for(int i = 0; i<4; i++) {
    setLightToRGB(light1,255,0,0);
    setLightToRGB(light2,0,0,0);
    setLightToRGB(light3,0,0,0);
    setLightToRGB(light4,0,0,0);

    delay(1000);

    setLightToRGB(light1,0,255,0);
    setLightToRGB(light2,255,0,0);
    setLightToRGB(light3,0,0,0);
    setLightToRGB(light4,0,0,0);

    delay(1000);

    setLightToRGB(light1,0,0,255);
    setLightToRGB(light2,0,0,0);
    setLightToRGB(light3,255,0,0);
    setLightToRGB(light4,0,0,0);

    delay(1000);

    setLightToRGB(light1,0,0,0);
    setLightToRGB(light2,0,0,0);
    setLightToRGB(light3,0,0,0);
    setLightToRGB(light4,255,0,0);

    delay(1000);
  }
  
  for(int i = 0; i<4; i++) {
    setLightToRGB(light1,random(255),random(255),random(255));
    setLightToRGB(light2,random(255),random(255),random(255));
    setLightToRGB(light3,random(255),random(255),random(255));
    setLightToRGB(light4,random(255),random(255),random(255));
    delay(1000);
  }
}

void setup() {             
  dmx_master.enable ();
  
  setLightToRGB(1,255,0,0);
  delay(1000);
  setLightToRGB(1,0,255,0);
  delay(1000);
  setLightToRGB(1,0,0,255);
  delay(1000);  

  setLightToRGB(1,0,255,255);
  delay(1000);
  setLightToRGB(1,255,0,255);
  delay(1000);
  setLightToRGB(1,255,255,0);
  delay(1000);
//  welcomeAnimation();
}




void loop() 
{
    dmx_master.setChannelValue(1,200);
    dmx_master.setChannelValue(2,random(255));
    dmx_master.setChannelValue(3,random(255));
    dmx_master.setChannelValue(4,random(255));
    delay(500);
}
