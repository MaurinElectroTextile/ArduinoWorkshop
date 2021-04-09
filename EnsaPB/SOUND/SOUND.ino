const int LED_PIN = 13;
const int THRESHOLD = 21;
boolean state = false;
boolean toggle = false;


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int val = analogRead(A0);
  // print out the value you read:

  //Serial.println(val);
  //delay(1);        // delay in between reads for stability

  if (val > THRESHOLD && toggle == false) {
    toggle = true;
    state = !state;
    digitalWrite(LED_PIN, state);
    delay(200);
  }
  else if (val < THRESHOLD && toggle == true) {
    toggle = false;
  }
}
