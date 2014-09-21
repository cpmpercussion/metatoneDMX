void setup() {
  Serial.begin(9600);
  Serial.println("Ready for some colour strings - receiving HSV!");
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
    
    HSVtoRGB(&red,&green,&blue,hue,sat,val);

    if (Serial.read() == '\n') {
      red = floor(red * 255);
      green = floor(green * 255);
      blue = floor(blue * 255);
      
      // Set the light going.
      Serial.print("Channel ");
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


void HSVtoRGB( float *r, float *g, float *b, float h, float s, float v )
{
	int i;
	float f, p, q, t;
	if( s == 0 ) {
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
	switch( i ) {
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





