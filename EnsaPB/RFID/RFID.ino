#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

///////////////////////////// SETUP
void setup() {
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();          // Initiate SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522

  delay(1000);
}

///////////////////////////// LOOP
void loop() {
  // Look for new cards
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  String content = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  content.toUpperCase();

  if (content.substring(1) == "99 45 8C 98") {
    Serial.write('A');
    delay(500);
  }
  else if (content.substring(1) == "69 28 BE 98") {
    Serial.write('B');
    delay(500);
  }
  else if (content.substring(1) == "04 71 5D 12 0A 3C 80") {
    Serial.write('C');
    delay(500);
  }
  else if (content.substring(1) == "04 79 5D 12 0A 3C 80") {
    Serial.write('D');
    delay(500);
  }
  else if (content.substring(1) == "04 83 5D 12 0A 3C 80") {
    Serial.write('E');
    delay(500);
  }
  else if (content.substring(1) == "04 8F 5D 12 0A 3C 80") {
    Serial.write('F');
    delay(500);
  }
  else if (content.substring(1) == "04 9A 5D 12 0A 3C 80") {
    Serial.write('G');
    delay(500);
  }
  delay(500);
}
