#include <LiquidCrystal.h>

//7 tone keyboard program by Nathan Bhak and Chris Ye

//sets pins for LCD display
LiquidCrystal lcd(13,12,11,10,9,8);

//sets pins for each button
const int buttons[7] = {A5,A4,A3,A2,A1,A0,3};
//sets pin for speaker
const int speaker = 2;

//array of pitches
const char pitches[] = {'B','A','G','F','E','D','C'};
//array of frequencies
const int tones[] = {247,220,196,175,165,147,131};

//represents the pitch
int noteTone = 0;

void setup() {

  //number of columns and rows being used on the display
  lcd.begin(16,2);

  //sets all buttons as input devices
  for(int i=0; i<=6; i++){
    pinMode(buttons[i],INPUT_PULLUP);
  }

  //sets the speaker as an output device
  pinMode(speaker, OUTPUT);

}

void loop() {

  //repeats 7 times
  for(int i=0; i<=6; i++){
    
    //sets the location of the text on the display
    lcd.setCursor(0,0);
    
    //while the button is being pressed
    if(! digitalRead(buttons[i])){
      
      //displays the note
      lcd.print(pitches[i]);

      //sets the pitch to the note represented by the button pressed
      noteTone = tones[i];

      //plays the note with the correct frequency
      tone(speaker,noteTone);
    }

    else{
      //if no button is pressed, then turn off the speaker
      noTone(speaker);
    }
  }

}
