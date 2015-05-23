byte value = 0;
byte count = 0;

byte val[ 4 ] = { 
  0, 0, 0, 0
};

/////////////////////////////// SETUP
void setup() {
  
  Serial.begin( 9600 ); // Start serial communication at 9600 bps

  pinMode(3, OUTPUT);   // Initiates Motor Channel A pin
  pinMode(5, OUTPUT);   // Initiates Brake Channel A pin
  pinMode(6, OUTPUT);   // Initiates Motor Channel B pin
  pinMode(9, OUTPUT);   // Initiates Brake Channel B pin
}

/////////////////////////////// LOOP
void loop() {

  if ( Serial.available() > 0) { // If data is available to read,
    value = Serial.read();       // read it and store it in val
    if ( value == 255 ) {
      count = 0;
      // Serial.write( "A" );
    } 
    else {
      val[ count ] = value;
      count++;
    }

    analogWrite(3, val[0]);   // Motor speed digital pin 3
    analogWrite(5, val[1]);   // Motor speed digital pin 5
    analogWrite(6, val[2]);   // Motor speed digital pin 6
    analogWrite(9, val[3]);   // Motor speed digital pin 9
  }
}




