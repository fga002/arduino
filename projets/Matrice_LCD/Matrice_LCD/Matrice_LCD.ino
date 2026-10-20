#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define MAX_DEVICES 4
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10
#define SCROLL_DELAY  75  //ms
#define CHAR_SPACING  1   // pixels

int WAIT_TIME = 800;

MD_Parola P = MD_Parola(MD_MAX72XX::FC16_HW, CS_PIN, MAX_DEVICES);
/*
MD_MAX72XX mx = MD_MAX72XX(CS_PIN, MAX_DEVICES);

#define BUF_SIZE  75
char curMessage[BUF_SIZE];
char newMessage[BUF_SIZE];

bool newMessageAvailable = false;
unsigned int scrollDelay = SCROLL_DELAY;

void readSerial()
{
  static unsigned int putIndex = 0;
  while (Serail.available())
  {
    newMessage[putIndex] = (char)Serial.read();
    if ((newMessage[putIndex] == '\n') || (putIndex >= BUF_SIZE-3))
    {
      newMessage[putIndex++] = ' ';
      newMessage[putIndex] = '\0';
      putIndex = 0;
      newMessageAvailable = true;
    }
    else
    {
      putIndex++;
    }
  }
}
*/

void setup() {
  // put your setup code here, to run once:
  P.begin();
}

void loop() {
  P.print("Bonjour");
  delay(WAIT_TIME);
  P.print("tous");
  delay(WAIT_TIME);
  P.print("le");
  delay(WAIT_TIME);
  P.print("monde");
  delay(WAIT_TIME);

  //if (P.displayAnimate())
  //  P.displayText("PERDU", PA_CENTER, P.getSpeed(), P.getPause(), PA_OPENING, PA_CLOSING);
}
