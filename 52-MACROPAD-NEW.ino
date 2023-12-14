// --------------------------------------------------------------
//
//                       B O O M Y  T E C H  
//
// YouTube: https://www.youtube.com/@boomytech7504
//
// EMail: boomytech@gmail.com
//
// --------------------------------------------------------------

#include <Adafruit_NeoPixel.h>
#include <Keyboard.h>
#include "Mouse.h"
#include <RotaryEncoder.h>

#define NumberLEDS     3   // Total number of leds

// PIN DEFINITION
#define pin_LEDS       10  // Pin used on arduino micro pro
#define pin_SW1 9
#define pin_SW2 8 
#define pin_SW3 7 
#define pin_SW4 6 
#define pin_SW5 5 
#define pin_SW6 4 
#define pin_SW7 3 
#define pin_SW8 2 
#define pin_ENCODER0 A0
#define pin_ENDORE1 A1

#define AntiBounceDelay delay(500); // to avoid key pressed bouncing

RotaryEncoder encoder(pin_ENCODER0, pin_ENCODER1, RotaryEncoder::LatchMode::TWO03);
Adafruit_NeoPixel pixel = Adafruit_NeoPixel(NumberLEDS, pin_LEDS, NEO_GRB + NEO_KHZ800);

// LETS DEFINE SOME VARIABLES
int              Encoder_newposition; // need to understand different position of encoder
unsigned int     Mode = 1; 
unsigned long    millis_start=0;
int              Bright = 0;
bool             Bright_Direction;
unsigned int     ModeColor[] = {0,0,10000,25000};




void setup() {
 Keyboard.begin();
 pixel.begin();
 Mouse.begin();  

}

void loop() {

  // ** ENCODER **
  static int Econder_position = 0;
  econder.tick();
  Encoder_newposition = encoder.getPosition();
  if (Encoder_position != Encodewr_newPosition) {
    if (Mode == 1) SetMode_1(0);
    if (Mode == 2) SetMode_2(0);
    if (Mode == 3) SetMode_3(0);
    Encoder_poisition = Encoder_newposition;
  }

  // ** KEY 1 **
  if (digitalRead(pin_SW1) == LOW) {
    if (Mode == 1) SetMode_1(0);
    if (Mode == 2) SetMode_2(0);
    if (Mode == 3) SetMode_3(0);
  }

  // ** KEY 2 **
    if (digitalRead(pin_SW2) == LOW) {
        if (Mode == 1) SetMode_1(2);
        if (Mode == 2) SetMode_2(2);
        if (Mode == 3) SetMode_3(2);
     }
     
     // ** KEY 3 **
     if (digitalRead(pin_SW3) == LOW) {
        if (Mode == 1) SetMode_1(3);
        if (Mode == 2) SetMode_2(3);
        if (Mode == 3) SetMode_3(3);
    }
    
    // ** KEY 4 **
    if (digitalRead(pin_SW4) == LOW) {
        if (Mode == 1) SetMode_1(4);
        if (Mode == 2) SetMode_2(4);
        if (Mode == 3) SetMode_3(4);
    }
    
    // ** KEY 5 **
    if (digitalRead(pin_SW5) == LOW) {
        if (Mode == 1) SetMode_1(5);
        if (Mode == 2) SetMode_2(5);
        if (Mode == 3) SetMode_3(5);
    }
    
     // ** KEY 6 **
     if (digitalRead(pin_SW6) == LOW) {
         if (Mode == 1) SetMode_1(6);
         if (Mode == 2) SetMode_2(6);
        if (Mode == 3) SetMode_3(6);
    }
    
    // ** KEY 7 **
    if (digitalRead(pin_SW7) == LOW) {
        if (Mode == 1) SetMode_1(7);
        if (Mode == 2) SetMode_2(7);
        if (Mode == 3) SetMode_3(7);
    }

    // ** KEY 8 **
    // This switch is used to change the key table
    if (digitalRead(pin_SW8) == LOW) {
        Mode +=1;
        if (Mode > 3) Mode = 1;
        AntiBounceDelay
    }

    // Background Color
    if (millis() > millis_start + 10) {
      millis_start = millis();
      LoopLedColor();
    }

}

void LoopLedColo() {
  pixel.setPixelColor(0, pixel.ColorHSV(ModeColor[Mode], 255, Bright));
  pixel.setPixelColor(1, pixel.ColorHSV(ModeColor[Mode], 255, Bright));
  pixel.setPixelColor(2, pixel.ColorHSV(ModeColor[Mode], 255, Bright));
  if (Bright_Direction) {
    Bright+=3;
    if (Bright > 255) {
      Bright_Direction = false;
      Bright = 255;
    }
  } else {
    Bright -=3;
    if (Bright < 0) {
      Bright_Direction = true;
      Bright = 0;
    }
  }
  pixel.show();


    
}
