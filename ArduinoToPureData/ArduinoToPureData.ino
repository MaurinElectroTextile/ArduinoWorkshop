////////////////////////// Code Arduino
// La transmission d'une valeur de 10 bits (0 - 1024)
// nécessite une méthode particulière, car seul des
// octets/bytes circulent sur la liaison série

///////////// déclaration des variables
int sensorPin_A = A0;    // sélection de la broche alogique A0
int sensorPin_B = A1;    // sélection de la broche alogique A1
int sensorValue_A = 0;   // déclaration de la variable qui contiendra une valeur captée (0 ---- 1024)
int sensorValue_B = 0;   // déclaration de la variable qui contiendra une valeur captée (0 ---- 1024)

boolean DEBUG = false; // false for PureData, true for Arduino

///////////// initialisation
void setup() {
  Serial.begin(19200);   // baude rate is 9600
}

///////////// boucle principale
void loop() {

  sensorValue_A = analogRead(sensorPin_A); // lecture de la broche analogue
  sensorValue_B = analogRead(sensorPin_B); // lecture de la broche analogue

  if (!DEBUG) Serial.write(100);    // header BYTE 1
  if (!DEBUG) Serial.write(254);    // header BYTE 2
  if (!DEBUG) Serial.write(33);     // header BYTE 3
  if (!DEBUG) Serial.write(125);    // header BYTE 4

  delay(5);

  if (DEBUG) Serial.println(sensorValue_A), Serial.print(" ");   
  if (DEBUG) Serial.print(sensorValue_B);  

  if (!DEBUG) print2byte(sensorValue_A);  // envoi de la première valeur captée 
  if (!DEBUG) print2byte(sensorValue_B);  // envoi de la deuxième valeur captée 
}

///////////// Fonction de transition d'une valeur dix bits (0-1024) sur deux octets/bytes
void print2byte( int inputVal ) {
  byte MSB = 0;
  byte LSB = 0;

  LSB = lowByte(inputVal);
  Serial.write(LSB);
  MSB = highByte(inputVal); 
  Serial.write(MSB);
}
