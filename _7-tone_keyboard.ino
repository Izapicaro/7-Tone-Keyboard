#include <LiquidCrystal.h>

//7 tone keyboard program by Nathan Bhak and Chris Ye

//sets pins for LCD display
LiquidCrystal lcd(11,12,13,14,15,16);

//sets pins for each button
const int buttons[7] = {3,4,5,6,7,8,9};
//sets pin for speaker
const int speaker = 2;
//all buttons are initially off
int buttonStates[7] = {0,0,0,0,0,0,0};

//array of pitches
const char pitches[] = {'C','D','E','F','G','A','B'};
//array of frequencies
const int tones[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014};

//represents the pitch
int noteTone = 0;

void setup() {

  //number of columns and rows being used on the display
  lcd.begin(1,1);

  //sets all buttons as input devices
  for(int i=0; i<=6; i++){
    pinMode(buttons[i],INPUT);
  }

  //sets the speaker as an output device
  pinMode(speaker, OUTPUT);

}

void loop() {

  //sets the location of the text on the display
  lcd.setCursor(0,0);

  //repeats 7 times
  for(int i=0; i<=6; i++){

    //reads the state of each button
    buttonStates[i] = digitalRead(buttonStates[i]);

    //if the button is switched on
    if(buttonStates[i] == HIGH){
      
      //displays the note
      lcd.print(pitches[i]);

      //sets the pitch to the note represented by the button pressed
      noteTone = tones[i];

      //plays the note with the correct frequency
      digitalWrite(speaker, HIGH);
      delayMicroseconds(noteTone);
      digitalWrite(speaker, LOW);
      delayMicroseconds(noteTone);
    }

    //if not button is pressed, then turn off the speaker
    else{
      digitalWrite(speaker, LOW);
    }

  }

}
