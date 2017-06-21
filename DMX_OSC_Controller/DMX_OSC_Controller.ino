#include <Conceptinetics.h>
#include <LiquidCrystal_I2C.h>
#define DMX_MASTER_CHANNELS   100
#define RXEN_PIN                2
#define STEP_INTERVAL           1
DMX_Master dmx_master(DMX_MASTER_CHANNELS, RXEN_PIN);

int light1 = 1;
int light2 = 2;
int light3 = 3;
int light4 = 4;
LiquidCrystal_I2C lcd(0x3f, 16, 2);

void setLightToRGB(int light, int red, int green, int blue, int dim) {
  dmx_master.setChannelValue(light, red); // red
  dmx_master.setChannelValue(light + 1, green); // green
  dmx_master.setChannelValue(light + 2, blue); // blue
  dmx_master.setChannelValue(light + 3, dim); // dimmer
  dmx_master.setChannelValue(light + 4, 0); // strobe
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("R:");
  lcd.print(red);
  lcd.setCursor(9,0);
  lcd.print("G:");
  lcd.print(green);
  lcd.setCursor(0,1);
  lcd.print("B:");
  lcd.print(blue);
  lcd.setCursor(9,1);
  lcd.print("D:");
  lcd.print(dim);
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Booting Lighting Control");
  dmx_master.enable();
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)


  setLightToRGB(1, 255, 0, 0, 255);
  delay(1000);
  setLightToRGB(1, 0, 255, 0, 255);
  delay(1000);
  setLightToRGB(1, 0, 0, 255, 255);
  delay(1000);

  
  setLightToRGB(1, 255, 0, 0, 153);
  delay(1000);
  setLightToRGB(1, 0, 255, 0, 153);
  delay(1000);
  setLightToRGB(1, 0, 0, 255, 153);
  delay(1000);

  
  setLightToRGB(1, 255, 0, 0, 76);
  delay(1000);
  setLightToRGB(1, 0, 255, 0, 76);
  delay(1000);
  setLightToRGB(1, 0, 0, 255, 76);
  delay(1000);
}

int dimmer = 0;


void loop()
{
  
  setLightToRGB(1, 255, 255, 255, dimmer);
  dimmer += 10;
  dimmer = dimmer % 256;
  delay(500);
}
