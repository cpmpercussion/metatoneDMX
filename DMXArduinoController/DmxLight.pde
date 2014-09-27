final float HUE_FADE = 1.0;
final float SAT_FADE = 0.01;
final float VAL_FADE = 0.01;



class DmxLight {
  int number;
  float hue;
  float sat;
  float val;

  float target_hue;
  float target_sat;
  float target_val;

  DmxLight(int n, float h, float s, float v) {
    number = n;
    hue = h;
    sat = s;
    val = v;

    target_hue = h;
    target_sat = s;
    target_val = v;
  }

  void paint(int x, int y) {
    fill(hue, sat, val);
    ellipse(x, y, 50, 50);
  }

  void fade() {
    if (abs(target_hue - hue) < HUE_FADE) {
      hue = target_hue;
    } else  if (target_hue > hue) {
      hue += HUE_FADE;
    } else if (target_hue < hue) {
      hue -= HUE_FADE;
    }

    if (abs(target_sat - sat) < SAT_FADE) {
      sat = target_sat;
    } else  if (target_sat > sat) {
      sat += SAT_FADE;
    } else if (target_sat < sat) {
      sat -= SAT_FADE;
    }

    if (abs(target_val - val) < VAL_FADE) {
      val = target_val;
    } else  if (target_val > val) {
      val += VAL_FADE;
    } else if (target_val < val) {
      val -= VAL_FADE;
    }
  }

  void setTargetColour(float h, float s, float v) {
    println("Set Target Colour for light " + number + " to: "+ h + ", " + s + ", " + v);
    target_hue = h;
    target_sat = s;
    target_val = v;
  }

  void updateLight(Serial port) {
    String lightMessage = number + ", "+hue+", "+sat+", "+val+"\n";
    print(lightMessage);
    port.write(lightMessage);
  }
}
