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



void setup() {             
  dmx_master.enable();
  setLightToRGB(1,50,50,50);
}

void loop() 
{
    dmx_master.setChannelValue(1,255);
    dmx_master.setChannelValue(2,random(255));
    dmx_master.setChannelValue(3,random(255));
    dmx_master.setChannelValue(4,random(255));
    delay(500);
}
