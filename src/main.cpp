/******************************************************************************
* + Project: Jack-O & The Lanterns                                            *
* + Version: 0.6.0a                                                           *
* + Description: Animatronic singing pumpkin trio                             *
* + Board: Feather Huzzah ESP8266                                             *
* + Sensor: N/A                                                               *
* + Module: SG90 Micro Servo                                                  *
* + Author: K0d3x 8its                                                        *
* + Date: October 9th, 2024                                                   *
* + License: MIT                                                              *
*******************************************************************************
  + Inspired by: Duckman | https://busyducks.com/ascii-art-arduino-pinouts/
  + Designed by: K0d3x   | https://github.com/k0d3x8its
*******************************************************************************
*                           ----[      ]-----             * VUSB = VIN | 5VDC *
*                      [ ]-|RST          ____|            *********************
*   MAX output 400mA = [ ]-|3V3         | __ |                                *
*                      [ ]-|NC          | __ |-[ ] = 3.7V Battery             *
*                      [ ]-|GND         |____|                                *
*                ADC = [ ]-|A0            BAT|-[ ] = LiPo                     **************
*                      [ ]-|NC             EN|-[ ] = connect GND to disable 3.3V regulator *
*                      [ ]-|NC           VUSB|-[ ] = VBUS                     **************
*                      [ ]-|NC          ~ D14|-[ ] = SCK                      *
*                      [ ]-|NC          ~ D12|-[ ] = MISO                     *
*                      [ ]-|NC          ~ D13|-[ ] = MOSI                     *
*                SCK = [ ]-|D14 ~  *    ~ D15|-[ ]                            *
*             ~ MOSI = [ ]-|D13  Feather ~ D0|-[ ] = Board LED/Bootloader     *
*             ~ MISO = [ ]-|D12  Huzzah ~ D16|-[ ] = WAKE                     *
*   Minion0 <=== RX--> [*]-|D3 ~         ~ D2|-[*] ===> Minion1               *
*    Jack-O <=== TX <--[*]-|D1 ~         ~ D5|-[ ] = SCL                      *
*                 EN = [ ]-|CHPD         ~ D4|-[ ] = SDA                      *
*                           \_______________/                                 *
*                                                                             *
*******************************************************************************
    ******************     Feather Huzzah Overview      ******************
*******************************************************************************
   ****** https://learn.adafruit.com/adafruit-feather-huzzah-esp8266 ******
*******************************************************************************
*******************************************************************************
         ******************  Example Datasheet  ******************
*******************************************************************************
               *** https://www.website.com/path/to/datasheet ***
******************************************************************************/

#include <Arduino.h>
#include <Servo.h>

// ─────────────────────────────────────────────────────────────
// Pin assignments
// ─────────────────────────────────────────────────────────────
#define JACK_O 1                  // leadPumpkin PWM pin
#define MINION_0 3                // minionPumpkin0 PWM pin
#define MINION_1 2                // minionPumpkin1 PWM pin

// ─────────────────────────────────────────────────────────────
// Servo objects for each pumpkin
// ─────────────────────────────────────────────────────────────
Servo jackO;                     // Lead pumpkin (Jack-O)
Servo minion0;                   // minionPumpkin0 (left)
Servo minion1;                   // minionPumpkin1 (right)

// ─────────────────────────────────────────────────────────────
// Timing & positions
// ─────────────────────────────────────────────────────────────
const int syllableDelay = 250;    // Adjust as needed for servo timing
const int closedMouth = 90;       // servo angle for mouth closed
const int openMouth = 120;        // servo angle for mouth opened

// ─────────────────────────────────────────────────────────────
// Forward declarations for helper functions used in loop()
// ─────────────────────────────────────────────────────────────
void moveJackO();
void moveTheLanterns();

// ─────────────────────────────────────────────────────────────
// Setup: attach servos & start in closed position
// ─────────────────────────────────────────────────────────────
void setup() {
  // Attach servos to their respective pins
  jackO.attach(JACK_O);         // Pin for lead pumpkin servo
  minion0.attach(MINION_0);     // Pin for Minion 0 servo
  minion1.attach(MINION_1);     // Pin for Minion 1 servo

  // Intialize all pumpkins with closed mouths
  jackO.write(closedMouth);
  minion0.write(closedMouth);
  minion1.write(closedMouth);
}

// ─────────────────────────────────────────────────────────────
// Loop: simple demo pattern for first verse/chorus fragment
// ─────────────────────────────────────────────────────────────
void loop() {
  // Jack-O sings "If there's something strange"
  moveJackO();

  // Jack-O sings "...in the neighborhood"
  moveJackO();

  // Jack-O sings "who ya gonna call"
  moveJackO();

  // The Lanterns sing "Ghostbusters!"
  moveTheLanterns();

}

// ─────────────────────────────────────────────────────────────
// Lead pumpkin: open → hold → close for ONE syllable
// ─────────────────────────────────────────────────────────────
void moveJackO() {
  jackO.write(openMouth);     // Open mouth 120 degrees
  delay(syllableDelay);       // Keep mouth open for the duration of one syllable
  jackO.write(closedMouth);   // Close mouth to 90 degrees (resting position)
}

// ─────────────────────────────────────────────────────────────
// Minions: both open → hold → close for ONE syllable
// (used for "Ghostbusters!" backup)
// ─────────────────────────────────────────────────────────────
void moveTheLanterns() {
  minion0.write(openMouth);     // minion0 opens mouth
  minion1.write(openMouth);     // minion1 opens mouth
  delay(syllableDelay);         // delay keeps both mouths open
  minion0.write(closedMouth);   // minion0 closes mouth
  minion1.write(closedMouth);   // minion1 closes mouth
}
