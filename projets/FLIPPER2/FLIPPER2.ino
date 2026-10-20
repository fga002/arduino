/*************************************************** 
  FLIPPER !!
 ****************************************************/
#include <Wire.h>
#include "musique.h"
#include "melodies.h"
#include "solenoid.h"
#include "ctrl74hc595n.h"
#include "led.h"

// ********************************************************************************************
// Les pins
// ********************************************************************************************
const int BOUTON1_PIN   = 1;
const int BOUTON2_PIN   = 2;
const int BOUTON3_PIN   = 3;
const int FLIPPER1_PIN  = 4;
const int FLIPPER2_PIN  = 5;
const int LANCEUR1_PIN  = 6;
const int LED_ORANGE    = 7;
const int BUZZER        = 8;
const int LED_ON        = 9;
const int LED_ROUGE     = 10;
const int CLOCK_PIN     = 11;
const int LATCH_PIN     = 12;
const int DATA_PIN      = 13;

// ********************************************************************************************
// Les boutons
// ********************************************************************************************
Solenoid flipper1(BOUTON1_PIN, FLIPPER1_PIN);
Solenoid flipper2(BOUTON2_PIN, FLIPPER2_PIN);
Solenoid lanceur1(BOUTON3_PIN, LANCEUR1_PIN);

// ********************************************************************************************
// La musique
// ********************************************************************************************
Musique musique_mario(BUZZER, melodie_mario, ALLEGRO);

// ********************************************************************************************
// Ctrl de leds
// ********************************************************************************************
Ctrl74HC595N ledsCtrl( DATA_PIN ,CLOCK_PIN ,LATCH_PIN );
Led led_verte(LED_ON);
Led led_orange(LED_ORANGE);
Led led_rouge(LED_ROUGE);

// ********************************************************************************************
// Variables
// ********************************************************************************************


/**********************************************************************************************
 * INITIALISATION
 **********************************************************************************************/
void setup()
{

  // Initialise la carte PWM (servos)
  Serial.begin(9600);
  
  while(!Serial); // Waiting for serial...
  
  // Attribution des PIN
  flipper1.init();
  flipper2.init();
  lanceur1.init();
  ledsCtrl.init();
  musique_mario.init();
  led_verte.init();
  led_orange.init();
  led_rouge.init();

  // MUSIQUE DEBUT
  // musique_mario.play();

  Serial.println("DEBUT !");
  led_verte.on();
  delay(10);
}
 
/**********************************************************************************************
 * BOUCLE PRINCIPALE
 **********************************************************************************************/
void loop() {
  
  flipper1.update();
  flipper2.update();
  lanceur1.update();
  /*
  updateLeds( 0 );
  delay(2000);
  
  int delaiMs = 500; // ms
  for( int i = 0; i<=15; i++ ){
     updateLeds( i );
     delay( delaiMs );
  }
  */
  
  delay(20);
}
