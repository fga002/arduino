/*************************************************** 
  FLIPPER !!
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

// Amplitudes max/min
#define POSITION_MAX_1  300
#define POSITION_MIN_1  150

// Les boutons
const int bouton1 = 7;
int etatbouton1 = 0;

/**
 * INITIALISATION
 */
void setup() {

  // Initialise la carte PWM (servos)
  Serial.begin(9600);

  
  
  Serial.println("DEBUT !");

  pinMode(bouton1, INPUT_PULLUP); 

  pwm.begin();
  /*
   * In theory the internal oscillator (clock) is 25MHz but it really isn't
   * that precise. You can 'calibrate' this by tweaking this number until
   * you get the PWM update frequency you're expecting!
   * The int.osc. for the PCA9685 chip is a range between about 23-27MHz and
   * is used for calculating things like writeMicroseconds()
   * Analog servos run at ~50 Hz updates, It is importaint to use an
   * oscilloscope in setting the int.osc frequency for the I2C PCA9685 chip.
   * 1) Attach the oscilloscope to one of the PWM signal pins and ground on
   *    the I2C PCA9685 chip you are setting the value for.
   * 2) Adjust setOscillatorFrequency() until the PWM update frequency is the
   *    expected value (50Hz for most ESCs)
   * Setting the value here is specific to each individual I2C PCA9685 chip and
   * affects the calculations for the PWM update frequency. 
   * Failure to correctly set the int.osc value will cause unexpected PWM results
   */
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  delay(10);
}

/**
 * VERIFIE L'ETAT DU BOUTON ET BOUGE LE SERVO A LA POSITION MIN OU MAX
 */
void gererServo(int noservo, int nobouton, int* etatbouton, int posmin, int posmax) {
  int nouveletat = digitalRead(nobouton);
  if (nouveletat != *etatbouton)
  {
    *etatbouton = nouveletat;
    if (nouveletat == HIGH)
    {
      pwm.setPWM(noservo, 0, posmax);
    }
    else
    {
      pwm.setPWM(noservo, 0, posmin);
    }
  }
}

/**
 * BOUCLE PRINCIPALE
 */
void loop() {
  gererServo(0, bouton1, &etatbouton1, POSITION_MIN_1, POSITION_MAX_1);
  delay(10);
}
