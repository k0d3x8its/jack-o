/******************************************************************************
* + Project: Jack-O & The Lanterns                                            *
* + Version: 0.4.0a                                                           *
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
*                      [ ]-|NC           VUSB|-[ ] = VBUS                     * ************
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

#define JACK_O 1                // leadPumpkin PWM pin
#define MINION_0 3              // minionPumpkin0 PWM pin
#define MINION_1 2              // minionPumpkin1 PWM pin

// Define servos for each pumpkin
Servo leadPumpkin;              // Lead pumpkin (Jack-O)
Servo pumpkin0;                 // minionPumpkin0 (left)
Servo pumpkin1;                 // minionPumpkin1 (right)

// Time intervals between syllables (in milliseconds)
const int syllableDelay = 250;  // Adjust as needed for servo timing

// Servo positions
const int closedMouth = 90;
const int openMouth = 120;

void setup() {
  // Attach servos to their respective pins
  leadPumpkin.attach(JACK_O);        // Pin for lead pumpkin servo
  pumpkin0.attach(MINION_0);      // Pin for Minion 0 servo
  pumpkin1.attach(MINION_1);      // Pin for Minion 1 servo

  // Intialize all pumpkins with closed mouths
  leadPumpkin.write(closedMouth);
  pumpkin0.write(closedMouth);
  pumpkin1.write(closedMouth);
}

void loop() {
  // put your main code here, to run repeatedly:

}