/* Broches */
const byte PIN_LED_R = 9;
const byte PIN_LED_G = 10;
const byte PIN_LED_B = 11;
#define DELAY 20

void displayColor(byte r, byte g, byte b) {

  // Assigne l'état des broches
  // Version cathode commune
  analogWrite(PIN_LED_R, r);
  analogWrite(PIN_LED_G, g);
  analogWrite(PIN_LED_B, b);

  // Version anode commune
  //analogWrite(PIN_LED_R, ~r);
  //analogWrite(PIN_LED_G, ~g);
  //analogWrite(PIN_LED_B, ~b);
}

void setup() {
  // Initialise les broches
  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
  displayColor(0, 0, 0);
}

void loop() {
  /**
  // RED
  displayColor(255, 0, 0);
  delay(1000);100

  // GREEN
  displayColor(0, 255, 0);
  delay(1000);

  // BLUE
  displayColor(0, 0, 255);
  delay(1000);
  **/

  // ROUGE
  for (int i = 0; i < 256; i++) {
    displayColor(i & 255, 0, 0);
    delay(DELAY);
  }
  delay(1000);

  // VERT
  for (int i = 0; i < 256; i++) {
    displayColor(0, i & 255, 0);
    delay(DELAY);
  }
  delay(1000);

  // BLEU
  for (int i = 0; i < 256; i++) {
    displayColor(0, 0, i & 255);
    delay(DELAY);
  }
  delay(1000);

  /**
  for (int r = 0; r < 256; r++) {
    String sr(r);
    for (int g = 0; g < 256; g++) {
      String sg(g);
      for (int b = 0; b < 256; b++) {
        String sb(b);
        String ss = sr + "," + sg + "," + sb;
        Serial.println(b);
        displayColor(r & 255, g & 255, b & 255);
        delay(10);
      }
    }
  }
  **/
  delay(1000);
}
