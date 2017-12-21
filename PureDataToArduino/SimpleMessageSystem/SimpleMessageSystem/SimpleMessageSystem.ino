#include <SimpleMessageSystem.h>
int  value_A = 0;
int  value_B = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  if (messageBuild() > 0) {
    
    int id = messageGetInt();

    if (id == 0) {
      value_A = messageGetInt();
    }
    if (id == 1) {
      value_B = messageGetInt();
    }

  }
}
